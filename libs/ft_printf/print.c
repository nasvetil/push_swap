/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 14:38:53 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:15:27 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void				ft_put_string_text(t_pf *pf, char *str)
{
	long double		len;
	char			*buff_str;

	len = ft_strlen(str);
	pf->spec.prec = 3;
	buff_str = ft_strnew_exit(3);
	buff_str = ft_strncpy(buff_str, str, len);
	ft_put_string(pf, &buff_str);
}

static void			ft_put_char(t_pf *pf)
{
	char			c;
	char			*str;

	c = va_arg(pf->arg, int);
	str = ft_strnew_exit(1);
	*str = c;
	ft_put_string(pf, &str);
}

void				ft_put_arg(t_pf *pf)
{
	char			*str;

	if (pf->spec.type.per)
	{
		str = ft_strnew_exit(1);
		*str = '%';
		ft_put_string(pf, &str);
	}
	if (pf->spec.type.d || pf->spec.type.i || pf->spec.type.o
		|| pf->spec.type.u || pf->spec.type.x || pf->spec.type.x_
		|| pf->spec.type.u_ || pf->spec.type.p || pf->spec.type.b)
		ft_put_digit(pf);
	if (pf->spec.type.s)
		ft_put_str(pf);
	if (pf->spec.type.c)
		ft_put_char(pf);
	if (pf->spec.type.f)
		ft_put_float(pf);
}
