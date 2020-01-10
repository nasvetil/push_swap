/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:04:45 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:17:04 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static void	ft_lstdel_elem(void *content, size_t content_size)
{
	if (content)
	{
		(void)content_size;
		free(content);
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*ptr_list;
	t_list	*prev_list;

	if (!(lst) || !(f))
		return (NULL);
	list = f(lst);
	ptr_list = list;
	prev_list = list;
	while (lst->next)
	{
		lst = lst->next;
		if (!(prev_list->next = f(lst)))
		{
			ft_lstdel(&ptr_list, &ft_lstdel_elem);
			return (NULL);
		}
		prev_list = prev_list->next;
	}
	return (ptr_list);
}
