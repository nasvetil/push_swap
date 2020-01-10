/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 11:01:50 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:19:24 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*str;

	ptr = (char*)s;
	str = NULL;
	while (*ptr != '\0' || (int)*ptr == c)
	{
		if ((int)*ptr == c)
			str = (char*)ptr;
		if (*ptr == '\0')
			return (str);
		ptr++;
	}
	return (str);
}
