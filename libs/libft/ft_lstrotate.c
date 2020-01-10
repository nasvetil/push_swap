/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:21:24 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 14:58:39 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list		*ft_lstrotate(t_list *lst_front)
{
	t_list	*ptr_lst;
	t_list	*new_lst_front;

	if (lst_front == NULL)
		return (NULL);
	if (lst_front->next == NULL)
		return (lst_front);
	new_lst_front = lst_front->next;
	ptr_lst = lst_front;
	while (ptr_lst->next)
	{
		ptr_lst = ptr_lst->next;
	}
	ptr_lst->next = lst_front;
	lst_front->next = NULL;
	return (new_lst_front);
}
