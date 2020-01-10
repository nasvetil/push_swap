/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:17:27 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:19:15 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strnew_exit(size_t size)
{
	char	*str;

	if (size + 1 == 0)
	{
		exit(EXIT_FAILURE);
		return (NULL);
	}
	if (!(str = (char*)malloc((size + 1) * sizeof(char))))
	{
		exit(EXIT_FAILURE);
		return (NULL);
	}
	ft_bzero(str, size + 1);
	return (str);
}
