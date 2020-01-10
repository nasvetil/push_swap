/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 20:52:19 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:15:15 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		ft_itoa_base_symb(int n)
{
	if (n >= 10)
		return ('a' + n - 10);
	return ('0' + n);
}

static size_t	ft_itoa_max_size(intmax_t n, int base)
{
	size_t		len_int;

	len_int = 0;
	if (n < 0)
		len_int++;
	n /= base;
	len_int++;
	while (n != 0)
	{
		n /= base;
		len_int++;
	}
	return (len_int);
}

char			*ft_itoa_base_max(intmax_t n, int base)
{
	char		*buf;
	char		*ptr;
	int			sign;
	size_t		len_int;

	sign = (n >= 0) ? 1 : -1;
	len_int = ft_itoa_max_size(n, base);
	if (!(buf = (char*)malloc(len_int + sizeof(char))))
		return (NULL);
	ptr = buf + (unsigned int)len_int + sizeof(char);
	*--ptr = '\0';
	*--ptr = (char)ft_itoa_base_symb((n % base) * sign);
	n /= base;
	while (n != 0)
	{
		*--ptr = (char)ft_itoa_base_symb((n % base) * sign);
		n /= base;
	}
	if (sign == -1)
		*--ptr = '-';
	return (ptr);
}

static size_t	ft_itoa_u_max_size(uintmax_t n, int base)
{
	size_t		len_int;

	len_int = 0;
	n /= base;
	len_int++;
	while (n != 0)
	{
		n /= base;
		len_int++;
	}
	return (len_int);
}

char			*ft_itoa_u_base_max(uintmax_t n, int base)
{
	char		*buf;
	char		*ptr;
	size_t		len_int;

	len_int = ft_itoa_u_max_size(n, base);
	if (!(buf = (char*)malloc(len_int + sizeof(char))))
		return (NULL);
	ptr = buf + (unsigned int)len_int + sizeof(char);
	*--ptr = '\0';
	*--ptr = (char)ft_itoa_base_symb(n % base);
	n /= base;
	while (n != 0)
	{
		*--ptr = (char)ft_itoa_base_symb(n % base);
		n /= base;
	}
	return (ptr);
}
