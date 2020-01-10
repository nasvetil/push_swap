/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:01:31 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 15:04:44 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstaddnew(t_list **alst, void const *content, size_t content_size)
{
	t_list			*ptr;

	ptr = ft_lstnew(content, content_size);
	if ((*alst) == NULL)
		(*alst) = ptr;
	else
		ft_lstadd(alst, ptr);
}
