/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:46:47 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/27 20:24:58 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int		ft_get_list_pos(t_list *elem, int n)
{
	int			i;
	t_list		*ptr_elem;

	ptr_elem = elem;
	i = 0;
	while (*(int*)ptr_elem->content != n)
	{
		ptr_elem = ptr_elem->next;
		i++;
	}
	return (i);
}

t_list			*ft_ps_rotate_cycle_list(t_ps_data **data)
{
	int			pos;

	pos = ft_get_list_pos((*data)->list_a, (*data)->min);
	if (pos < ((*data)->count / 2 + (*data)->count % 2))
	{
		while (*(int*)(*data)->list_a->content != (*data)->min)
			ft_ps_cmd_ra(data);
	}
	else
	{
		while (*(int*)(*data)->list_a->content != (*data)->min)
			ft_ps_cmd_rra(data);
	}
	return ((*data)->list_a);
}

static int		ft_ps_get_rev_rotate(t_list *ptr_list, int check_first)
{
	int			temp_arg;
	int			rlt;

	temp_arg = 0;
	rlt = 1;
	while (ptr_list->next)
	{
		if (*(int*)ptr_list->content < *(int*)ptr_list->next->content)
		{
			if (!ptr_list->next->next)
			{
				if (check_first == 1 &&
					(temp_arg > *(int*)ptr_list->next->content))
					rlt = -1;
				else
					rlt = 0;
			}
			else
				rlt = 0;
			break ;
		}
		temp_arg = *(int*)ptr_list->content;
		ptr_list = ptr_list->next;
	}
	return (rlt);
}

int				ft_ps_check_rotates_sort_rev_new(t_ps_data **data)
{
	t_list		*ptr_list;
	int			i;
	int			rlt;
	int			check_first;

	if ((*data)->count != 5)
		return (0);
	ptr_list = (*data)->list_a;
	if (ptr_list == NULL)
		return (1);
	i = 0;
	check_first = 0;
	if (*(int*)ptr_list->content == (*data)->min)
		check_first = 1;
	while (*(int*)ptr_list->content != (*data)->max)
	{
		(*data)->list_a = ft_lstrotate((*data)->list_a);
		ptr_list = (*data)->list_a;
		i++;
	}
	rlt = ft_ps_get_rev_rotate(ptr_list, check_first);
	while (i--)
		(*data)->list_a = ft_lstrevrotate((*data)->list_a);
	return (rlt);
}
