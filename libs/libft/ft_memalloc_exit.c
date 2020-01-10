/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:16:14 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:17:09 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void		*ft_memalloc_exit(size_t size)
{
	char	*str;

	if (!(str = (char*)malloc(size * sizeof(char))))
	{
		exit(EXIT_FAILURE);
		return (NULL);
	}
	ft_bzero(str, size);
	return (str);
}
