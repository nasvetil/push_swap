/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_number_param.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:52:05 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:15:32 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void			ft_put_number_sign(t_pf *pf, int *i_pos)
{
	if (pf->spec.flags.hash && ((pf->spec.param.type_d
		&& !pf->spec.param.d_zero) || pf->spec.type.p))
	{
		if (pf->spec.type.o)
			ft_memcpy(&pf->spec.param.buff[*i_pos], "0", 1);
		if (pf->spec.type.x)
			ft_memcpy(&pf->spec.param.buff[*i_pos], "0x", 2);
		if (pf->spec.type.x_)
			ft_memcpy(&pf->spec.param.buff[*i_pos], "0X", 2);
	}
	else if (pf->spec.flags.hash && pf->spec.param.d_zero)
		ft_memcpy(&pf->spec.param.buff[*i_pos], "0", 1);
	if (pf->spec.flags.plus)
	{
		if (pf->spec.param.type_d && !pf->spec.param.d_neg)
			ft_memcpy(&pf->spec.param.buff[*i_pos], "+", 1);
		else
			ft_memcpy(&pf->spec.param.buff[*i_pos], "-", 1);
	}
	else if (pf->spec.flags.space)
		ft_memcpy(&pf->spec.param.buff[*i_pos], " ", 1);
	*i_pos = *i_pos + pf->spec.flags.space + pf->spec.flags.plus
		+ pf->spec.flags.hash * pf->spec.type.o * 1
		+ pf->spec.flags.hash * (pf->spec.type.x || pf->spec.type.x_) * 2;
}

void			ft_set_empty_str(t_pf *pf)
{
	ft_bzero(pf->spec.param.str, ft_strlen(pf->spec.param.str));
	ft_memdel((void**)&pf->spec.param.str);
	pf->spec.param.str = ft_memalloc_exit(0);
}

void			ft_set_number_hash_flags(t_pf *pf)
{
	if (pf->spec.type.o || pf->spec.type.x || pf->spec.type.x_
		|| pf->spec.type.u || pf->spec.type.u_)
	{
		pf->spec.flags.plus = 0;
		pf->spec.flags.space = 0;
	}
	if (pf->spec.type.d || pf->spec.type.i
		|| pf->spec.type.u || pf->spec.type.u_)
		pf->spec.flags.hash = 0;
	if (pf->spec.type.o && pf->spec.prec - pf->spec.param.str_len > 0)
		pf->spec.flags.hash = 0;
}

void			ft_set_number_flags(t_pf *pf)
{
	pf->spec.check_prec *= !(pf->spec.prec < 0);
	pf->spec.prec *= !(pf->spec.prec < 0);
	pf->spec.flags.minus = (pf->spec.width < 0) || pf->spec.flags.minus;
	pf->spec.width += (pf->spec.width < 0) * 2 * -pf->spec.width;
	pf->spec.flags.plus = pf->spec.param.d_neg || pf->spec.flags.plus;
	if (pf->spec.param.d_zero && pf->spec.check_prec && !pf->spec.prec
		&& !(pf->spec.type.o && pf->spec.flags.hash))
		ft_set_empty_str(pf);
	pf->spec.param.str_len = ft_strlen(pf->spec.param.str);
	if (pf->spec.param.d_zero && !pf->spec.type.p)
		pf->spec.flags.hash = 0;
	if (pf->spec.flags.minus || pf->spec.check_prec)
		pf->spec.flags.zero = 0;
	pf->spec.flags.minus = (pf->spec.prec < 0) || pf->spec.flags.minus;
	ft_set_number_hash_flags(pf);
	if (pf->spec.prec)
	{
		pf->spec.flags.zero = 0;
		if (pf->spec.prec > pf->spec.param.str_len)
			pf->spec.prec -= pf->spec.param.str_len;
		else
			pf->spec.prec = 0;
	}
}

void			ft_set_number_width(t_pf *pf)
{
	if (pf->spec.flags.hash && (pf->spec.type.x || pf->spec.type.x_))
		pf->spec.width -= 2;
	if (pf->spec.flags.hash && pf->spec.type.o)
		pf->spec.width--;
	pf->spec.width -= (pf->spec.prec + pf->spec.param.str_len);
	if (pf->spec.width > 0 && pf->spec.flags.zero)
	{
		pf->spec.prec = pf->spec.width;
		pf->spec.width = 0;
	}
	if (!(pf->spec.width > 0))
		pf->spec.width = 0;
}
