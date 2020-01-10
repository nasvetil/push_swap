/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:27:41 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:15:30 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		*ft_empty_string_str(t_pf *pf)
{
	char		*str;

	pf->spec.prec = 0;
	str = ft_strnew_exit(2);
	str = ft_memcpy(str, "\0\0", 2);
	return (str);
}

static char		*ft_null_string_str(t_pf *pf)
{
	size_t		len;
	char		*str;

	if (pf->spec.prec)
		len = pf->spec.prec;
	else
		len = 6;
	str = ft_strnew_exit(len);
	str = ft_strncpy(str, "(null)", len);
	return (str);
}

void			ft_put_str(t_pf *pf)
{
	char		*str_arg;
	char		*str;
	size_t		len;

	str_arg = va_arg(pf->arg, char*);
	if (pf->spec.prec < 0 && str_arg != NULL)
	{
		pf->spec.flags.zero = 0;
		pf->spec.flags.minus = 1;
		pf->spec.prec = ft_strlen(str_arg);
	}
	if (pf->spec.check_prec && pf->spec.prec <= 0)
		str = ft_empty_string_str(pf);
	else if (str_arg == NULL)
		str = ft_null_string_str(pf);
	else
	{
		if (pf->spec.prec)
			len = pf->spec.prec;
		else
			len = ft_strlen(str_arg);
		str = ft_strnew_exit(len);
		str = ft_strncpy(str, str_arg, len);
	}
	ft_put_string(pf, &str);
}
