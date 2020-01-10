/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 11:44:15 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/26 17:50:26 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;

	ptr_s1 = (unsigned char*)s1;
	ptr_s2 = (unsigned char*)s2;
	while (*ptr_s1 == *ptr_s2 && *ptr_s1 != '\0' && *ptr_s2 != '\0')
	{
		ptr_s1++;
		ptr_s2++;
	}
	return ((int)*ptr_s1 - (int)*ptr_s2);
}
