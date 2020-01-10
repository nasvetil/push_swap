/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:25:30 by dorange-          #+#    #+#             */
/*   Updated: 2019/11/01 09:28:35 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void		ft_lstpush(t_list **lst_1_front, t_list **lst_2_front)
{
	t_list	*ptr_lst_2_front_next;
	t_list	*ptr_lst_1_front;

	if (*lst_2_front == NULL)
		return ;
	ptr_lst_1_front = *lst_1_front;
	ptr_lst_2_front_next = (*lst_2_front)->next;
	*lst_1_front = *lst_2_front;
	(*lst_1_front)->next = ptr_lst_1_front;
	*lst_2_front = ptr_lst_2_front_next;
}
