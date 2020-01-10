/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 19:31:15 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/27 20:16:10 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void		ft_ps_ft_ps_compare_rotate(t_ps_data **data,
					t_ps_op **rotate_1, t_ps_op **rotate_2, int i)
{
	(*rotate_2)->ra_count = i;
	if ((*rotate_2)->ra_count >= (*data)->count / 2)
	{
		(*rotate_2)->rra_count = (*data)->count - (*rotate_2)->ra_count;
		(*rotate_2)->ra_count = 0;
	}
	if (ft_ps_check_rotates_op(*rotate_1, *rotate_2))
	{
		if (*rotate_1 != NULL)
			ft_bzero(*rotate_1, sizeof(t_ps_op));
		free(*rotate_1);
		*rotate_1 = *rotate_2;
		*rotate_2 = ft_memalloc_exit(sizeof(t_ps_op));
	}
}

static void		ft_ps_do_rotates(t_ps_data **data, t_ps_op *rotate)
{
	while (rotate->ra_count--)
		ft_ps_cmd_ra(data);
	while (rotate->rra_count--)
		ft_ps_cmd_rra(data);
}

static void		ft_ps_search_opt_swap(t_ps_data **data, t_ps_op **rotate_1,
					t_ps_op **rotate_2, t_list **ptr_list)
{
	int		first_value;
	int		temp_value;
	int		i;

	first_value = *(int*)(*ptr_list)->content;
	i = 0;
	while (*ptr_list)
	{
		if ((*ptr_list)->next)
			temp_value = *(int*)(*ptr_list)->next->content;
		else
			temp_value = first_value;
		if ((*(int*)(*ptr_list)->content > temp_value &&
			!(*(int*)(*ptr_list)->content == (*data)->max &&
			temp_value == (*data)->min)) ||
			(*(int*)(*ptr_list)->content == (*data)->min &&
			temp_value == (*data)->max))
			ft_ps_ft_ps_compare_rotate(data, rotate_1, rotate_2, i);
		ft_bzero(*rotate_2, sizeof(t_ps_op));
		(*rotate_2)->check_alg_4_5 = 1;
		(*ptr_list) = (*ptr_list)->next;
		i++;
	}
}

void			ft_ps_alg_3_swap(t_ps_data **data)
{
	t_ps_op *rotate_1;
	t_ps_op *rotate_2;
	t_list	*ptr_list;
	int		i;
	int		first_value;

	rotate_1 = NULL;
	rotate_2 = malloc(sizeof(t_ps_op));
	ft_bzero(rotate_2, sizeof(t_ps_op));
	rotate_2->check_alg_4_5 = 1;
	ptr_list = (*data)->list_a;
	first_value = *(int*)(ptr_list)->content;
	i = 0;
	ft_ps_search_opt_swap(data, &rotate_1, &rotate_2, &ptr_list);
	free(rotate_2);
	ft_ps_do_rotates(data, rotate_1);
	free(rotate_1);
}
