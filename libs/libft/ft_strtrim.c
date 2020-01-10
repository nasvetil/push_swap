/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 18:19:56 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:19:41 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	start;
	size_t	finish;
	char	*str;
	char	*ptr_str;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (len == 0)
		return ((char*)s);
	start = 0;
	finish = len - 1;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while ((s[finish] == ' ' || s[finish] == '\n' || s[finish] == '\t')
			&& finish >= start)
		finish--;
	if (!(str = (char*)malloc((finish - start + 2) * sizeof(char))))
		return (NULL);
	ptr_str = str;
	while (start <= finish)
		*str++ = s[start++];
	*str = '\0';
	return (ptr_str);
}
