/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:50:47 by dorange-          #+#    #+#             */
/*   Updated: 2019/11/01 09:46:22 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdio.h>

static void		ft_lstswap_init(t_lst_swap *swap, t_list *lst_1,
					t_list *lst_2, t_list *lst_front)
{
	swap->lst_1 = lst_1;
	swap->lst_2 = lst_2;
	swap->lst_front = lst_front;
}

static void		ft_lstswap_init_ptr(t_lst_swap *swap)
{
	swap->lst_1_prev = swap->lst_front;
	swap->lst_2_prev = swap->lst_front;
	if (swap->lst_1_prev == swap->lst_1)
		swap->lst_1_prev = NULL;
	else
		while (swap->lst_1_prev->next != swap->lst_1)
			swap->lst_1_prev = swap->lst_1_prev->next;
	if (swap->lst_2_prev == swap->lst_2)
		swap->lst_2_prev = NULL;
	else
		while (swap->lst_2_prev->next != swap->lst_2)
			swap->lst_2_prev = swap->lst_2_prev->next;
	swap->lst_1_next = swap->lst_1->next;
	swap->lst_2_next = swap->lst_2->next;
}

static void		ft_lstswap_swap(t_lst_swap *swap)
{
	if (swap->lst_2 == swap->lst_1_next)
	{
		swap->lst_2->next = swap->lst_1;
		swap->lst_1->next = swap->lst_2_next;
		if (swap->lst_1 != swap->lst_front)
			swap->lst_1_prev->next = swap->lst_2;
	}
	else if (swap->lst_1 == swap->lst_2_next)
	{
		swap->lst_1->next = swap->lst_2;
		swap->lst_2->next = swap->lst_1_next;
		if (swap->lst_2 != swap->lst_front)
			swap->lst_2_prev->next = swap->lst_2;
	}
	else
	{
		if (swap->lst_1 != swap->lst_front)
			swap->lst_1_prev->next = swap->lst_2;
		swap->lst_2->next = swap->lst_1_next;
		if (swap->lst_2 != swap->lst_front)
			swap->lst_2_prev->next = swap->lst_1;
		swap->lst_1->next = swap->lst_2_next;
	}
}

t_list			*ft_lstswap(t_list *lst_1, t_list *lst_2, t_list *lst_front)
{
	t_lst_swap	*swap;
	t_list		*rlt_lst_front;

	if (lst_1 == NULL || lst_2 == NULL || lst_front == NULL)
		return (NULL);
	swap = ft_memalloc_exit(sizeof(t_lst_swap));
	ft_lstswap_init(swap, lst_1, lst_2, lst_front);
	if (swap->lst_1 == NULL || swap->lst_front == NULL)
		return (NULL);
	if (swap->lst_2 == NULL)
		return (swap->lst_front);
	ft_lstswap_init_ptr(swap);
	ft_lstswap_swap(swap);
	if (swap->lst_1 == swap->lst_front)
		rlt_lst_front = swap->lst_2;
	else if (swap->lst_2 == swap->lst_front)
		rlt_lst_front = swap->lst_1;
	else
		rlt_lst_front = (swap->lst_front);
	free(swap);
	return (rlt_lst_front);
}
