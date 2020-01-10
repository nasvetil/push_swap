/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 19:32:47 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/27 20:24:58 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_list		*ft_ps_alg_3_elem(t_ps_data **data)
{
	while (!ft_ps_check_rotates_sort((*data)->list_a, (*data)->min))
	{
		if (*(int*)(*data)->list_a->content >
			*(int*)(*data)->list_a->next->content &&
			!(*(int*)(*data)->list_a->content == (*data)->max &&
			*(int*)(*data)->list_a->next->content == (*data)->min))
			ft_ps_cmd_sa(data);
		else
			ft_ps_cmd_rra(data);
	}
	ft_ps_rotate_cycle_list(data);
	return ((*data)->list_a);
}

t_list		*ft_ps_alg_4_5_elem(t_ps_data **data)
{
	if (ft_ps_check_rotates_sort_rev_new(data) == 1 && (*data)->count == 5)
		ft_ps_rotate_cycle_list(data);
	else if (ft_ps_check_rotates_sort_rev_new(data) == -1 &&
		*(int*)(*data)->list_a->content == (*data)->min &&
		(*data)->count == 5)
		ft_ps_cmd_ra(data);
	while (!ft_ps_check_rotates_sort((*data)->list_a, (*data)->min))
	{
		ft_ps_alg_3_swap(data);
		ft_ps_cmd_sa(data);
	}
	ft_ps_rotate_cycle_list(data);
	return ((*data)->list_a);
}
