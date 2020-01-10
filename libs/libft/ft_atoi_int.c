/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:55:44 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/27 18:59:11 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_atoi_int(const char *str)
{
	int			nmb;
	int			sign;

	nmb = 0;
	sign = 1;
	while ((*str == '\t' || *str == '\n' || *str == '\v' ||
			*str == '\f' || *str == '\r' || *str == ' '))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if ((sign * (nmb * 10 + (*str - '0'))) / 10 != sign * nmb)
			return (0);
		nmb = nmb * 10 + (*str - '0');
		str++;
	}
	return (sign * nmb);
}
