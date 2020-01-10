/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 19:45:53 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/27 20:14:36 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void		ft_ps_check_stack(t_list *list)
{
	t_list	*ptr_list;

	ptr_list = list->next;
	if (!ptr_list)
		return ;
	while (ptr_list)
	{
		if (*(int*)list->content == *(int*)ptr_list->content)
			ft_ps_error("Error\n");
		ptr_list = ptr_list->next;
	}
}

int			ft_ps_check_sort(t_list *lst)
{
	t_list	*ptr_list;

	ptr_list = lst;
	if (ptr_list == NULL)
		return (1);
	while (ptr_list->next)
	{
		if (*(int*)ptr_list->content > *(int*)ptr_list->next->content)
			return (0);
		ptr_list = ptr_list->next;
	}
	return (1);
}

void		ft_ps_data_del(t_ps_data **data)
{
	ft_lstdel(&(*data)->list_a, ft_ps_free_cnt);
	ft_lstdel(&(*data)->list_b, ft_ps_free_cnt);
	ft_lstdel(&(*data)->cmd, ft_ps_free_cnt);
	ft_bzero(*data, sizeof(t_ps_data));
	free(*data);
}

void		ft_ps_exit(t_ps_data **data)
{
	ft_ps_data_del(data);
	ft_ps_error("Error\n");
}

void		ft_ps_print_cmd(t_ps_data **data, char *str)
{
	if ((*data)->check_v_flag)
		ft_ps_debug(data, str);
	else if (!(*data)->check_checker)
		ft_printf("%s\n", str);
}
