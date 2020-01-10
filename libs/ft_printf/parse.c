/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 08:29:16 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:15:25 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int				ft_str_check_z(t_pf *pf)
{
	char	*ptr_str;

	ptr_str = pf->s;
	while (*ptr_str && *ptr_str != '\n' && *ptr_str != '\t'
		&& *ptr_str != '\v' && *ptr_str != '\f' && *ptr_str != '\r')
	{
		if (ft_check_type(*ptr_str))
			return (0);
		if (*ptr_str == 'Z')
			return (1);
		ptr_str++;
	}
	return (0);
}

void			ft_parse_correct(t_pf *pf)
{
	if (pf->spec.type.s || pf->spec.type.c || pf->spec.type.per)
	{
		pf->spec.flags.plus = 0;
		pf->spec.flags.hash = 0;
	}
	if (pf->spec.type.per || pf->spec.type.c)
		pf->spec.flags.space = 0;
}

void			ft_parse_spec_step(t_pf *pf)
{
	if (ft_check_flag(*pf->s))
		ft_set_flags(pf);
	else if (*pf->s == '.')
		ft_set_prec(pf);
	else if (ft_isdigit(*pf->s) || *pf->s == '*')
		ft_set_width(pf);
	else if (ft_check_size(pf->s))
		ft_set_size(pf);
	else
		pf->s++;
}

int				ft_parse_spec(t_pf *pf)
{
	ft_bzero((void*)&(pf->spec), sizeof(pf->spec));
	if (ft_strchr(pf->s, 'Z'))
	{
		if (ft_str_check_z(pf))
		{
			pf->s = ft_strrchr(pf->s, 'Z');
			return (1);
		}
	}
	if (ft_str_check_type(pf) == 0)
	{
		pf->s = ft_strchr_control(pf->s);
		return (1);
	}
	while (!ft_check_type(*pf->s))
		ft_parse_spec_step(pf);
	ft_set_type(pf);
	ft_parse_correct(pf);
	ft_put_arg(pf);
	return (1);
}
