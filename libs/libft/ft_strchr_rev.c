/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:49:51 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:18:11 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strchr_rev(const char *s, int c)
{
	char	*ptr;

	ptr = (char*)s;
	while (*ptr != '\0' || (int)*ptr == c)
		ptr++;
	if (*ptr != '\0' && (int)*ptr != c)
		return (ptr);
	return (NULL);
}
