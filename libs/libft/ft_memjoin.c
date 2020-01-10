/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:29:54 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:17:28 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_memjoin(char const *s1, size_t len_s1,
			char const *s2, size_t len_s2)
{
	char	*str;
	char	*text_str;
	char	*ptr_str;

	if (!(s1) || !(s2))
		return (NULL);
	if (!(str = (char*)malloc((len_s1 + len_s2) * sizeof(char))))
		return (NULL);
	ft_bzero(str, len_s1 + len_s2);
	ptr_str = str;
	while (len_s1--)
	{
		*str = *s1;
		str++;
		s1++;
	}
	text_str = str;
	while (len_s2--)
	{
		*str = *s2;
		str++;
		s2++;
	}
	return (ptr_str);
}
