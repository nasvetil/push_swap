/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 20:20:03 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/26 19:35:49 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_ps_cmd_pa(t_ps_data **data)
{
	ft_lstpush(&(*data)->list_a, &(*data)->list_b);
	ft_ps_print_cmd(data, "pa");
}

void	ft_ps_cmd_pb(t_ps_data **data)
{
	ft_lstpush(&(*data)->list_b, &(*data)->list_a);
	ft_ps_print_cmd(data, "pb");
}
