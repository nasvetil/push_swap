/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 10:49:12 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:18:14 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char*)s;
	while (*ptr != '\0' || (int)*ptr == c)
	{
		if ((int)*ptr == c)
			return (ptr);
		ptr++;
	}
	return (NULL);
}
