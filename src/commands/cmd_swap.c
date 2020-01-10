/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 20:17:33 by dorange-          #+#    #+#             */
/*   Updated: 2019/11/01 09:48:46 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_ps_cmd_sa(t_ps_data **data)
{
	t_list	*lst_front;

	if ((*data)->list_a)
	{
		lst_front = ft_lstswap((*data)->list_a,
			(*data)->list_a->next, (*data)->list_a);
		if (lst_front)
			(*data)->list_a = lst_front;
	}
	ft_ps_print_cmd(data, "sa");
}

void	ft_ps_cmd_sb(t_ps_data **data)
{
	t_list	*lst_front;

	if ((*data)->list_b)
	{
		lst_front = ft_lstswap((*data)->list_b,
			(*data)->list_b->next, (*data)->list_b);
		if (lst_front)
			(*data)->list_b = lst_front;
	}
	ft_ps_print_cmd(data, "sb");
}

void	ft_ps_cmd_ss(t_ps_data **data)
{
	t_list	*lst_front;

	if ((*data)->list_a)
	{
		lst_front = ft_lstswap((*data)->list_a,
			(*data)->list_a->next, (*data)->list_a);
		if (lst_front)
			(*data)->list_a = lst_front;
	}
	if ((*data)->list_b)
	{
		lst_front = ft_lstswap((*data)->list_b,
			(*data)->list_b->next, (*data)->list_b);
		if (lst_front)
			(*data)->list_b = lst_front;
	}
	ft_ps_print_cmd(data, "ss");
}
