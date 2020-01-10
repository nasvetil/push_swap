/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:09:21 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:16:56 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr_next;

	if (alst && del)
	{
		while (*alst)
		{
			ptr_next = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			(*alst) = ptr_next;
		}
	}
	(*alst) = NULL;
}
