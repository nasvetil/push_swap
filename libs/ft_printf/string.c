/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:40:08 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:15:39 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void			ft_put_param_string(t_pf *pf)
{
	int			i_pos;
	char		*ptr_str;

	i_pos = 0;
	if (pf->spec.width > 0 && !pf->spec.flags.minus)
		ft_memset(&pf->spec.param.buff[i_pos], ' ', pf->spec.width);
	i_pos += !pf->spec.flags.minus * pf->spec.width;
	if (pf->spec.flags.space)
		ft_memcpy(&pf->spec.param.buff[i_pos], " ", 1);
	i_pos = i_pos + pf->spec.flags.space;
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

void			ft_set_string_buff(t_pf *pf)
{
	pf->spec.param.buff_len = pf->spec.param.str_len
		+ pf->spec.prec + pf->spec.width
		+ pf->spec.flags.plus + pf->spec.flags.space
		+ pf->spec.flags.hash * pf->spec.type.o * 1
		+ pf->spec.flags.hash * (pf->spec.type.x || pf->spec.type.x_) * 2;
	if (pf->spec.param.buff_len - pf->spec.prec > pf->spec.prec
		&& pf->spec.prec != 0 && pf->spec.param.str_len != 0)
		pf->spec.param.buff_len = pf->spec.prec;
	else if (pf->spec.param.str_len == 0
		&& pf->spec.param.buff_len - pf->spec.prec < pf->spec.width)
	{
		pf->spec.param.buff_len = pf->spec.width;
	}
	if (pf->spec.param.str_len == 0)
		pf->spec.prec = 0;
	pf->spec.param.buff = ft_memalloc_exit(pf->spec.param.buff_len);
	ft_bzero(pf->spec.param.buff, pf->spec.param.buff_len);
}

void			ft_set_string_flags(t_pf *pf)
{
	pf->spec.param.str_len = ft_strlen(pf->spec.param.str);
	pf->spec.prec *= !(pf->spec.param.str[0] == '\0');
	if (pf->spec.param.str[0] == '\0' && pf->spec.type.c)
		pf->spec.param.str_len = 1;
	pf->spec.flags.zero *= !(pf->spec.prec < 0);
	pf->spec.flags.minus = pf->spec.flags.minus || (pf->spec.prec < 0);
	if (pf->spec.prec < 0)
	{
		if (!(pf->spec.width > pf->spec.prec))
			pf->spec.width = pf->spec.prec;
		pf->spec.prec = pf->spec.param.str_len;
	}
	pf->spec.flags.minus = (pf->spec.width < 0)
		|| pf->spec.flags.minus;
	pf->spec.width += (pf->spec.width < 0) * 2 * -pf->spec.width;
	pf->spec.flags.zero *= !(pf->spec.flags.minus
		|| pf->spec.check_prec);
	pf->spec.flags.zero *= !(pf->spec.prec > 0);
	pf->spec.prec *= !(pf->spec.prec > 0);
}

void			ft_put_string(t_pf *pf, char **str_str)
{
	pf->spec.param.str = *str_str;
	ft_set_string_flags(pf);
	pf->spec.width -= pf->spec.flags.space;
	if (pf->spec.param.str[0] != '\0')
		pf->spec.width -= (pf->spec.prec + pf->spec.param.str_len);
	else if (pf->spec.param.str[0] == '\0' && pf->spec.type.c)
		pf->spec.width -= pf->spec.param.str_len;
	if (pf->spec.width > 0 && pf->spec.flags.zero)
	{
		pf->spec.prec = pf->spec.width;
		pf->spec.width = 0;
	}
	pf->spec.width *= (pf->spec.width > 0);
	ft_set_string_buff(pf);
	ft_put_param_string(pf);
}
