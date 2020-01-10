/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 09:43:14 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:15:21 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

intmax_t		ft_get_number_u(t_pf *pf)
{
	intmax_t	n;

	n = va_arg(pf->arg, uintmax_t);
	if (pf->spec.size.j)
		n = (uintmax_t)n;
	else if (pf->spec.size.ll)
		n = (unsigned long long int)n;
	else if (pf->spec.size.l || pf->spec.type.u_)
		n = (unsigned long int)n;
	else if (pf->spec.size.z)
		n = (size_t)n;
	else if (pf->spec.size.h)
		n = (unsigned short)n;
	else if (pf->spec.size.hh)
		n = (unsigned char)n;
	else
		n = (unsigned int)n;
	return (n);
}

intmax_t		ft_get_number(t_pf *pf)
{
	intmax_t	n;

	n = va_arg(pf->arg, intmax_t);
	if (pf->spec.size.j)
		n = (intmax_t)n;
	else if (pf->spec.size.ll)
		n = (long long int)n;
	else if (pf->spec.size.l || pf->spec.size.z)
		n = (long int)n;
	else if (pf->spec.size.h)
		n = (short)n;
	else if (pf->spec.size.hh)
		n = (char)n;
	else
		n = (int)n;
	return (n);
}

char			*ft_get_str_number(t_pf *pf, intmax_t n)
{
	char		*str;

	if (pf->spec.type.u || pf->spec.type.u_)
		str = ft_itoa_u_base_max(n, 10);
	if (pf->spec.type.d || pf->spec.type.i)
		str = ft_itoa_base_max(n, 10);
	if (pf->spec.type.o)
		str = ft_itoa_u_base_max(n, 8);
	if (pf->spec.type.b)
		str = ft_itoa_u_base_max(n, 2);
	if (pf->spec.type.x || pf->spec.type.x_)
		str = ft_itoa_u_base_max(n, 16);
	if (pf->spec.type.x_)
		ft_strtoupper(&str);
	return (str);
}
