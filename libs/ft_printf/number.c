/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:40:47 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:15:23 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void			ft_put_number_param(t_pf *pf)
{
	int			i_pos;
	char		*ptr_str;

	pf->spec.param.buff_len = pf->spec.param.str_len + pf->spec.prec
		+ pf->spec.width + pf->spec.flags.plus + pf->spec.flags.space
		+ pf->spec.flags.hash * pf->spec.type.o * 1
		+ pf->spec.flags.hash * (pf->spec.type.x || pf->spec.type.x_) * 2;
	pf->spec.param.buff = ft_memalloc_exit(pf->spec.param.buff_len);
	i_pos = 0;
	if (pf->spec.width > 0 && !pf->spec.flags.minus)
		ft_memset(&pf->spec.param.buff[i_pos], ' ', pf->spec.width);
	i_pos += !pf->spec.flags.minus * pf->spec.width;
	ft_put_number_sign(pf, &i_pos);
	if (pf->spec.prec > 0)
		ft_memset(&pf->spec.param.buff[i_pos], '0', pf->spec.prec);
	i_pos += pf->spec.prec;
	ft_memcpy(&pf->spec.param.buff[i_pos], pf->spec.param.str,
		pf->spec.param.str_len);
	i_pos += pf->spec.param.str_len;
	if (pf->spec.width > 0 && pf->spec.flags.minus)
		ft_memset(&pf->spec.param.buff[i_pos], ' ', pf->spec.width);
	ptr_str = pf->spec.param.buff;
	ft_pf_buff(pf, &*pf->spec.param.buff, pf->spec.param.buff_len);
	ft_memdel((void**)&pf->spec.param.str);
	ft_memdel((void**)&ptr_str);
}

void			ft_put_clear_number(t_pf *pf)
{
	char		*ptr_str;
	char		*buff;
	size_t		str_len;

	ptr_str = ft_strchr(pf->spec.param.str, '0');
	str_len = ft_strlen(ptr_str);
	buff = ft_strnew_exit(str_len);
	buff = ft_memcpy(buff, ptr_str, str_len);
	ft_memdel((void**)&pf->spec.param.str);
	pf->spec.param.str = buff;
}

void			ft_put_neg_number(t_pf *pf)
{
	char		*buff;
	size_t		str_len;

	str_len = ft_strlen(pf->spec.param.str) - 1;
	buff = ft_strnew_exit(str_len);
	buff = ft_memcpy(buff, &pf->spec.param.str[1], str_len);
	ft_memdel((void**)&pf->spec.param.str);
	pf->spec.param.str = buff;
}

void			ft_put_number(t_pf *pf)
{
	if (pf->spec.param.str[0] == '0' && (pf->spec.type.o
		|| pf->spec.type.x || pf->spec.type.x_))
		ft_put_clear_number(pf);
	if (pf->spec.param.d_neg && !(pf->spec.type.o || pf->spec.type.x
		|| pf->spec.type.x_ || pf->spec.type.u || pf->spec.type.u_))
		ft_put_neg_number(pf);
	ft_set_number_flags(pf);
	pf->spec.flags.space *= !(pf->spec.flags.plus);
	pf->spec.width -= pf->spec.flags.plus;
	pf->spec.width -= pf->spec.flags.space;
	ft_set_number_width(pf);
	ft_put_number_param(pf);
}

void			ft_put_digit(t_pf *pf)
{
	intmax_t	n;

	if ((pf->spec.type.u || pf->spec.type.o || pf->spec.type.x
		|| pf->spec.type.x_ || pf->spec.type.u_ || pf->spec.type.b))
		n = ft_get_number_u(pf);
	else if (pf->spec.type.p)
	{
		pf->spec.size.ll = 1;
		pf->spec.type.x = 1;
		pf->spec.flags.hash = 1;
		n = ((intmax_t)va_arg(pf->arg, void*));
	}
	else
		n = ft_get_number(pf);
	pf->spec.param.str = ft_get_str_number(pf, n);
	pf->spec.param.type_d = 1;
	pf->spec.param.d_neg = (n < 0);
	pf->spec.param.d_zero = (n == 0);
	ft_put_number(pf);
}
