/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:53:24 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/27 20:16:09 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int		ft_ps_ptr_rotate(t_list **lst, t_list **ptr_list, int min)
{
	int			i;

	i = 0;
	while (*(int*)(*ptr_list)->content != min)
	{
		*lst = ft_lstrotate(*lst);
		*ptr_list = *lst;
		i++;
	}
	return (i);
}

int				ft_ps_check_rotates_sort(t_list *lst, int min)
{
	t_list		*ptr_list;
	int			i;
	int			rlt;

	ptr_list = lst;
	if (ptr_list == NULL)
		return (1);
	i = ft_ps_ptr_rotate(&lst, &ptr_list, min);
	rlt = 1;
	while (ptr_list->next)
	{
		if (*(int*)ptr_list->content > *(int*)ptr_list->next->content)
		{
			rlt = 0;
			break ;
		}
		ptr_list = ptr_list->next;
	}
	while (i--)
		lst = ft_lstrevrotate(lst);
	return (rlt);
}

int				ft_ps_check_rotates_op(t_ps_op *rotate_1, t_ps_op *rotate_2)
{
	int			rlt_1;
	int			rlt_2;

	if (rotate_1 == NULL)
		return (1);
	rlt_1 = rotate_1->ra_count + rotate_1->rb_count + rotate_1->rr_count +
		rotate_1->rra_count + rotate_1->rrb_count + rotate_1->rrr_count;
	rlt_2 = rotate_2->ra_count + rotate_2->rb_count + rotate_2->rr_count +
		rotate_2->rra_count + rotate_2->rrb_count + rotate_2->rrr_count;
	if (rlt_2 < rlt_1 || (rotate_2->check_alg_4_5 == 0 && rlt_1 == 0 &&
		rotate_2->rb_count == 0 && rotate_2->rrb_count == 0))
		return (1);
	return (0);
}
