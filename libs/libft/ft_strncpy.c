/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:28:58 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:19:08 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*ptr;
	size_t	count;

	ptr = dst;
	count = 0;
	while (count < len)
	{
		if (*src != '\0')
		{
			*dst = *src;
			src++;
		}
		else
			*dst = '\0';
		dst++;
		count++;
	}
	return (ptr);
}
