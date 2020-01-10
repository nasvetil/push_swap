/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:40:09 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:18:06 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strchr_control(const char *s)
{
	char	*ptr;

	ptr = (char*)s;
	while ((*ptr != '\t' && *ptr != '\n' &&
			*ptr != '\v' && *ptr != '\f' &&
			*ptr != '\r' && *ptr != '\0'))
		ptr++;
	return (ptr);
}
