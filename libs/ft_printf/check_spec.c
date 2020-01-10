/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 08:43:48 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:14:54 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int				ft_check_flag(int c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		return (1);
	return (0);
}

int				ft_check_type(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' ||
		c == 'i' || c == 'o' || c == 'u' || c == 'x' ||
		c == 'X' || c == 'f' || c == 'U' || c == '%' ||
		c == 'b')
		return (1);
	return (0);
}

int				ft_check_size(char *s)
{
	if (s[0] == 'h' || s[0] == 'l' || s[0] == 'L' ||
		s[0] == 'j' || s[0] == 'z')
		return (1);
	return (0);
}

int				ft_str_check_type(t_pf *pf)
{
	char	*ptr_str;

	ptr_str = pf->s;
	while (*ptr_str && *ptr_str != '\n' && *ptr_str != '\t'
		&& *ptr_str != '\v' && *ptr_str != '\f' && *ptr_str != '\r')
	{
		if (ft_check_type(*ptr_str))
			return (1);
		ptr_str++;
	}
	return (0);
}
