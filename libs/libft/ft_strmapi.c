/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:55:27 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:19:00 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	char			*ptr_str;
	int				len_str;
	unsigned int	i;

	if (!(s) || !(f))
		return (NULL);
	len_str = ft_strlen(s);
	if (!(str = (char*)malloc((len_str + 1) * sizeof(char))))
		return (NULL);
	ptr_str = str;
	i = 0;
	while (*s != '\0')
	{
		*str = f(i, *s);
		str++;
		s++;
		i++;
	}
	*str = '\0';
	return (ptr_str);
}
