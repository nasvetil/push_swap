/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:24:16 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:18:57 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*ptr_str;
	int		len_str;

	if (!(s) || !(f))
		return (NULL);
	len_str = ft_strlen(s);
	if (!(str = (char*)malloc((len_str + 1) * sizeof(char))))
		return (NULL);
	ptr_str = str;
	while (*s != '\0')
	{
		*str = f(*s);
		str++;
		s++;
	}
	*str = '\0';
	return (ptr_str);
}
