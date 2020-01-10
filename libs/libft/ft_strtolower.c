/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 10:57:59 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:19:35 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_strtolower(char **str)
{
	char	*ptr_str;
	size_t	str_len;
	size_t	i;

	ptr_str = *str;
	str_len = ft_strlen(*str);
	i = 0;
	while (i < str_len)
	{
		*ptr_str = ft_tolower(*ptr_str);
		ptr_str++;
		i++;
	}
}
