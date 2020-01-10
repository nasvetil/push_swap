/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 11:07:43 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:19:20 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char*)haystack);
	i = 0;
	while (*haystack != '\0' && i < len)
	{
		j = 0;
		while (haystack[j] == needle[j] && haystack[j] != '\0' &&
				needle[j] != '\0' && (i + j) <= len)
			j++;
		if ((i + j) <= len && needle[j] == '\0')
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
