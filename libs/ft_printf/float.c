/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 20:54:44 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:15:13 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void				ft_get_float_digit(long double *n, char **str, int prec)
{
	uintmax_t		integer;
	char			*ptr_str;

	ptr_str = *str;
	*ptr_str = '.';
	ptr_str++;
	prec--;
	while (prec--)
	{
		(*n) *= 10;
		integer = (uintmax_t)(*n + 0.01);
		*ptr_str = (char)(ft_abs_null((int)integer) + 48);
		ptr_str++;
		(*n) = (*n) - (long double)integer;
		*str = ptr_str;
	}
}

void				ft_get_float(long double n, char **s, int prec)
{
	uintmax_t		integer;
	short			neg;
	size_t			int_len;
	char			*ft_itoa;
	char			*ptr_str;

	neg = (n < 0);
	if (neg)
		n = -n;
	integer = (uintmax_t)n;
	neg *= (integer != 0);
	ft_itoa = ft_itoa_u_base_max(integer, 10);
	int_len = ft_strlen(ft_itoa);
	n = n - (long double)integer;
	*s = ft_strnew_exit(neg + 1 + int_len + prec);
	ptr_str = *s;
	if (neg)
	{
		*ptr_str = '-';
		ptr_str++;
	}
	ft_strncpy(ptr_str, ft_itoa, int_len);
	free(ft_itoa);
	ptr_str += int_len * sizeof(char);
	ft_get_float_digit(&n, &ptr_str, prec);
}

void				ft_put_float(t_pf *pf)
{
	long double		n;
	char			*str;

	if (pf->spec.size.l_)
		n = va_arg(pf->arg, long double);
	else
		n = ((long double)va_arg(pf->arg, double));
	if (n == INFINITY)
		ft_put_string_text(pf, "inf");
	else if (n != n && !pf->spec.size.l_)
		ft_put_string_text(pf, "nan");
	else
	{
		if (pf->spec.prec == 0)
			pf->spec.prec = 6;
		pf->spec.prec++;
		ft_get_float(n, &str, pf->spec.prec);
		pf->spec.prec = 0;
		pf->spec.param.str = str;
		ft_put_number(pf);
	}
}
