/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:32:30 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:17:38 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

long long int	ft_powint(long long int a, long long int b)
{
	int			c;

	c = 1;
	while (b--)
	{
		if ((c * a + 0) / a != c)
			return (0);
		c *= a;
	}
	return (c);
}
