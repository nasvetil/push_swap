/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 18:01:06 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:19:33 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*ptr_str;
	size_t	count;

	if (!(s))
		return (NULL);
	if (!(str = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	ptr_str = str;
	count = 0;
	s = &s[start];
	while (count < len && *s != '\0')
	{
		*str = *s;
		str++;
		s++;
		count++;
	}
	*str = '\0';
	return (ptr_str);
}
