/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:54:11 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/27 20:00:12 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void		ft_ps_free_cnt(void *s, size_t n)
{
	ft_bzero(s, n);
	free(s);
}

void		ft_ps_set_new_arg(int numb, t_list **lst)
{
	ft_lstaddnew(lst, &numb, sizeof(int));
}

void		ft_ps_print_list_int(t_list *elem)
{
	ft_printf("%d\n", *(int*)elem->content);
}

void		ft_ps_error(char *str)
{
	ft_dprintf(2, "%s", str);
	exit(EXIT_FAILURE);
}

void		ft_ps_exit_not_error(t_ps_data **data)
{
	if (data != NULL)
		ft_ps_data_del(data);
	exit(EXIT_SUCCESS);
}
