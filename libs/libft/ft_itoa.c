/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 19:32:48 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:16:48 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static size_t	ft_itoa_size(int n)
{
	size_t		len_int;

	len_int = 0;
	if (n < 0)
		len_int++;
	n /= 10;
	len_int++;
	while (n != 0)
	{
		n /= 10;
		len_int++;
	}
	return (len_int);
}

char			*ft_itoa(int n)
{
	char		*buf;
	char		*ptr;
	int			sign;
	size_t		len_int;

	len_int = ft_itoa_size(n);
	if (!(buf = (char*)malloc(len_int + sizeof(char))))
		return (NULL);
	ptr = buf + (int)len_int + sizeof(char);
	*--ptr = '\0';
	sign = (n >= 0) ? 1 : -1;
	*--ptr = (char)('0' + (n % 10) * sign);
	n /= 10;
	while (n != 0)
	{
		*--ptr = (char)('0' + (n % 10) * sign);
		n /= 10;
	}
	if (sign == -1)
		*--ptr = '-';
	return (ptr);
}
