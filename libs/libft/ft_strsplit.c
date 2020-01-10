/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:22:56 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:19:27 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int		ft_str_count_elem(char const *s, char c)
{
	int		count_elem;
	char	*ptr_s;

	if (!(s))
		return (0);
	count_elem = 0;
	ptr_s = (char*)s;
	while (*ptr_s != '\0')
	{
		if (*ptr_s == c)
			ptr_s++;
		if (*ptr_s != c && *ptr_s != '\0')
			count_elem++;
		while (*ptr_s != c && *ptr_s != '\0')
			ptr_s++;
	}
	return (count_elem);
}

static size_t	ft_strlen_chr(const char *s, char c)
{
	size_t		len;

	if (!(s))
		return (0);
	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

static void		*ft_memdel_arr_null(char ***ap, int count)
{
	int		i;
	char	***ptr_ap;

	ptr_ap = ap;
	if (**ap)
	{
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

char			**ft_strsplit(char const *s, char c)
{
	int			i;
	int			j;
	char		**arr;

	if (!(s))
		return (NULL);
	if (!(arr = (char**)malloc((ft_str_count_elem(s, c) + 1) * sizeof(char*))))
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			j = 0;
			if (!(arr[i] = ft_strnew(ft_strlen_chr(s, c) + 1)))
				return (ft_memdel_arr_null(&arr, i));
			while (*s != c && *s != '\0')
				arr[i][j++] = (char)*s++;
			arr[i++][j] = '\0';
		}
		else
			s++;
	}
	arr[i] = NULL;
	return (arr);
}
