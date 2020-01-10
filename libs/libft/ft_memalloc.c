/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 15:21:45 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:17:12 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void		*ft_memalloc(size_t size)
{
	char	*str;

	if (!(str = (char*)malloc(size * sizeof(char))))
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
