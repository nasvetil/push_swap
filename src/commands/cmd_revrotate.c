/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_revrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 20:16:11 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/26 19:35:52 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_ps_cmd_rra(t_ps_data **data)
{
	(*data)->list_a = ft_lstrevrotate((*data)->list_a);
	ft_ps_print_cmd(data, "rra");
}

void	ft_ps_cmd_rrb(t_ps_data **data)
{
	(*data)->list_b = ft_lstrevrotate((*data)->list_b);
	ft_ps_print_cmd(data, "rrb");
}

void	ft_ps_cmd_rrr(t_ps_data **data)
{
	(*data)->list_a = ft_lstrevrotate((*data)->list_a);
	(*data)->list_b = ft_lstrevrotate((*data)->list_b);
	ft_ps_print_cmd(data, "rrr");
}
