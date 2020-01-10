/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrevrotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:21:02 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 15:06:40 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdio.h>

t_list		*ft_lstrevrotate(t_list *lst_front)
{
	t_list	*ptr_lst;
	t_list	*ptr_lst_prev;
	t_list	*new_lst_front;

	if (lst_front == NULL)
		return (NULL);
	if (lst_front->next == NULL)
		return (lst_front);
	ptr_lst = lst_front;
	while (ptr_lst->next)
	{
		ptr_lst_prev = ptr_lst;
		ptr_lst = ptr_lst->next;
	}
	new_lst_front = ptr_lst;
	new_lst_front->next = lst_front;
	ptr_lst_prev->next = NULL;
	return (new_lst_front);
}
