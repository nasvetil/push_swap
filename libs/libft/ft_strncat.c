/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:42:44 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:19:02 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*ptr_s1;
	char	*ptr_s2;

	ptr_s1 = (char*)s1;
	ptr_s2 = (char*)s2;
	while (*ptr_s1 != '\0')
		ptr_s1++;
	while (*ptr_s2 != '\0' && n--)
	{
		*ptr_s1 = *ptr_s2;
		ptr_s1++;
		ptr_s2++;
	}
	*ptr_s1 = '\0';
	return ((char*)s1);
}
