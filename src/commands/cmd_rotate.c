/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 20:05:30 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/26 19:35:55 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_ps_cmd_ra(t_ps_data **data)
{
	(*data)->list_a = ft_lstrotate((*data)->list_a);
	ft_ps_print_cmd(data, "ra");
}

void	ft_ps_cmd_rb(t_ps_data **data)
{
	(*data)->list_b = ft_lstrotate((*data)->list_b);
	ft_ps_print_cmd(data, "rb");
}

void	ft_ps_cmd_rr(t_ps_data **data)
{
	(*data)->list_a = ft_lstrotate((*data)->list_a);
	(*data)->list_b = ft_lstrotate((*data)->list_b);
	ft_ps_print_cmd(data, "rr");
}
