/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 19:28:42 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/27 20:25:44 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void		ft_ps_set_basic_numbers(t_ps_data **data)
{
	(*data)->min = ft_get_min_value((*data)->list_a);
	(*data)->max = ft_get_max_value((*data)->list_a);
	(*data)->median = ft_get_median_value((*data)->list_a);
	(*data)->count_a = (*data)->count;
	(*data)->count_b = 0;
}

int			ft_ps_check_basic_numbers(t_ps_data **data)
{
	if (*(int*)(*data)->list_a->content != (*data)->min &&
		*(int*)(*data)->list_a->content != (*data)->max &&
		*(int*)(*data)->list_a->content != (*data)->median)
		return (1);
	return (0);
}

void		ft_ps_push_a_to_b_spec(t_ps_data **data)
{
	if ((*data)->count_b == 2)
	{
		if (*(int*)(*data)->list_b->content >
			*(int*)(*data)->list_b->next->content)
			ft_ps_cmd_sb(data);
	}
	if ((*data)->count > 170)
	{
		if (*(int*)(*data)->list_a->content < (*data)->median)
			ft_ps_cmd_pb(data);
		else
		{
			ft_ps_cmd_pb(data);
			ft_ps_cmd_rb(data);
		}
	}
	else
		ft_ps_cmd_pb(data);
}

void		ft_ps_push_a_to_b(t_ps_data **data)
{
	int		i;

	i = 0;
	while (i < (*data)->count)
	{
		if (ft_ps_check_basic_numbers(data))
		{
			if ((*data)->count_b < 2)
				ft_ps_cmd_pb(data);
			else
				ft_ps_push_a_to_b_spec(data);
			(*data)->count_b++;
			(*data)->count_a--;
		}
		else
			ft_ps_cmd_ra(data);
		i++;
	}
}

t_list		*ft_ps_algorithm(t_ps_data **data)
{
	if ((*data)->list_a->next == NULL)
		return ((*data)->list_a);
	ft_ps_set_basic_numbers(data);
	if ((*data)->count < 6)
	{
		if ((*data)->count < 4)
			(*data)->list_a = ft_ps_alg_3_elem(data);
		else
			(*data)->list_a = ft_ps_alg_4_5_elem(data);
		return ((*data)->list_a);
	}
	ft_ps_push_a_to_b(data);
	(*data)->list_a = ft_ps_alg_3_elem(data);
	while ((*data)->list_b != NULL)
	{
		ft_ps_search_rotate(data);
		ft_ps_cmd_pa(data);
		(*data)->count_a++;
		(*data)->count_b--;
	}
	(*data)->list_a = ft_ps_rotate_cycle_list(data);
	return ((*data)->list_a);
}
