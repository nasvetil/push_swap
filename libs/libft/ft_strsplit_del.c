/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:25:32 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/27 16:29:32 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	ft_get_strsplit_count(char **array)
{
	char	**ptr_array;
	int		count;

	ptr_array = array;
	count = 0;
	while (*ptr_array++)
		count++;
	return (count);
}

void		*ft_strsplit_del(char ***ap)
{
	int		i;
	int		count;
	char	***ptr_ap;

	ptr_ap = ap;
	if (**ap)
	{
		count = ft_get_strsplit_count(*ap);
		i = count - 1;
		while (i >= 0)
		{
			free((*ap)[i]);
			(*ap)[i] = NULL;
			i--;
		}
	}
	free((*ap));
	(*ap) = NULL;
	return (NULL);
}
