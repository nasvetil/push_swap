/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:23:57 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/27 21:28:16 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int			main(int argc, char **argv)
{
	t_ps_data		*data;

	if (argc == 1)
		ft_ps_exit_not_error(NULL);
	data = ft_memalloc_exit(sizeof(t_ps_data));
	ft_bzero(data, sizeof(t_ps_data));
	ft_ps_set_stacks(&data, argc, argv);
	ft_lstiter(data->list_a, ft_ps_check_stack);
	if (ft_ps_check_sort(data->list_a))
		ft_ps_exit_not_error(&data);
	data->list_a = ft_ps_algorithm(&data);
	ft_lstdel(&data->list_a, ft_ps_free_cnt);
	ft_lstdel(&data->list_b, ft_ps_free_cnt);
	ft_lstdel(&data->cmd, ft_ps_free_cnt);
	ft_bzero(data, sizeof(t_ps_data));
	free(data);
	return (0);
}
