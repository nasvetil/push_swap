/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cycle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 19:30:22 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/27 20:25:44 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void		ft_ps_get_min_rotate(t_ps_data **data,
					t_ps_op *rotate_2, t_list *ptr_list_b)
{
	rotate_2->ra_count = ft_get_list_pos_min_max((*data)->list_a,
		*(int*)ptr_list_b->content);
	if (rotate_2->ra_count == -1)
	{
		rotate_2->rra_count = 1;
		rotate_2->ra_count = 0;
	}
	else if (rotate_2->ra_count >= (*data)->count_a / 2)
	{
		rotate_2->rra_count = (*data)->count_a - rotate_2->ra_count;
		rotate_2->ra_count = 0;
	}
	rotate_2->ra_count++;
}

static void		ft_ps_set_min_b_rotate(t_ps_data **data, t_ps_op *rotate_2)
{
	if (rotate_2->rb_count >= (*data)->count_b / 2)
	{
		rotate_2->rrb_count = (*data)->count_b - rotate_2->rb_count;
		rotate_2->rb_count = 0;
	}
	while (rotate_2->ra_count > 0 && rotate_2->rra_count > 0)
	{
		rotate_2->ra_count--;
		rotate_2->rra_count--;
	}
	while (rotate_2->rb_count > 0 && rotate_2->rrb_count > 0)
	{
		rotate_2->rb_count--;
		rotate_2->rrb_count--;
	}
	while (rotate_2->rr_count > 0 && rotate_2->rrr_count > 0)
	{
		rotate_2->rr_count--;
		rotate_2->rrr_count--;
	}
}

static void		ft_ps_do_rotates(t_ps_data **data, t_ps_op *rotate)
{
	while (rotate->rr_count--)
		ft_ps_cmd_rr(data);
	while (rotate->ra_count--)
		ft_ps_cmd_ra(data);
	while (rotate->rb_count--)
		ft_ps_cmd_rb(data);
	while (rotate->rrr_count--)
		ft_ps_cmd_rrr(data);
	while (rotate->rra_count--)
		ft_ps_cmd_rra(data);
	while (rotate->rrb_count--)
		ft_ps_cmd_rrb(data);
}

static void		ft_ps_compare_rotate(t_ps_op **rotate_1, t_ps_op **rotate_2)
{
	(void)rotate_1;
	(void)rotate_2;
	(*rotate_2)->rr_count = ((*rotate_2)->ra_count < (*rotate_2)->rb_count) ?
		(*rotate_2)->ra_count : (*rotate_2)->rb_count;
	(*rotate_2)->ra_count -= (*rotate_2)->rr_count;
	(*rotate_2)->rb_count -= (*rotate_2)->rr_count;
	(*rotate_2)->rrr_count = ((*rotate_2)->rra_count < (*rotate_2)->rrb_count) ?
		(*rotate_2)->rra_count : (*rotate_2)->rrb_count;
	(*rotate_2)->rra_count -= (*rotate_2)->rrr_count;
	(*rotate_2)->rrb_count -= (*rotate_2)->rrr_count;
	if (ft_ps_check_rotates_op(*rotate_1, *rotate_2))
	{
		if (*rotate_1 != NULL)
			ft_bzero(*rotate_1, sizeof(t_ps_op));
		free(*rotate_1);
		*rotate_1 = *rotate_2;
		*rotate_2 = ft_memalloc_exit(sizeof(t_ps_op));
	}
	ft_bzero(*rotate_2, sizeof(t_ps_op));
}

void			ft_ps_search_rotate(t_ps_data **data)
{
	t_ps_op *rotate_1;
	t_ps_op *rotate_2;
	t_list	*ptr_list_b;
	int		i;

	rotate_1 = NULL;
	rotate_2 = malloc(sizeof(t_ps_op));
	ft_bzero(rotate_2, sizeof(t_ps_op));
	ptr_list_b = (*data)->list_b;
	i = 0;
	while (ptr_list_b)
	{
		ft_ps_get_min_rotate(data, rotate_2, ptr_list_b);
		rotate_2->rb_count = i;
		ft_ps_set_min_b_rotate(data, rotate_2);
		ft_ps_compare_rotate(&rotate_1, &rotate_2);
		ft_bzero(rotate_2, sizeof(t_ps_op));
		ptr_list_b = ptr_list_b->next;
		i++;
	}
	free(rotate_2);
	ft_ps_do_rotates(data, rotate_1);
	free(rotate_1);
}
