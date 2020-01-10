/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:51:44 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:18:00 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_putstr(char const *s)
{
	if (s)
	{
		while (*s != '\0')
		{
			ft_putchar((int)*s);
			s++;
		}
	}
}