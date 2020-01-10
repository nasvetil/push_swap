/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:21:04 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/27 20:14:59 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void		ft_ps_print_debug_header(char *cmd)
{
	ft_printf("\n");
	ft_printf("| %-3s ----------------------- |\n", cmd);
	ft_printf("|                             |\n");
	ft_printf("| %-12c%3c%12c |\n", 'a', ' ', 'b');
	ft_printf("| %-12c%3c%12c |\n", '-', ' ', '-');
}

static void		ft_ps_print_debug_footer(void)
{
	ft_printf("|_____________________________|\n");
}

static void		ft_ps_print_stack_param(t_list **list_a, t_list **list_b)
{
	if (*list_a)
		ft_printf("| %-12d%3c", *(int*)(*list_a)->content, ' ');
	else
		ft_printf("| %15c", ' ');
	if (*list_b)
		ft_printf("%12d ", *(int*)(*list_b)->content, ' ');
	else
		ft_printf("%12c ", ' ');
	ft_printf("|\n");
	if (*list_a)
		*list_a = (*list_a)->next;
	if (*list_b)
		*list_b = (*list_b)->next;
}

static void		ft_ps_print_parameters(t_list **list_a,
					t_list **list_b, int count)
{
	int			i;

	i = 0;
	while (i < count)
	{
		ft_ps_print_stack_param(list_a, list_b);
		i++;
	}
}

void			ft_ps_debug(t_ps_data **data, char *cmd)
{
	t_list		*ptr_list_a;
	t_list		*ptr_list_b;
	int			count_a;
	int			count_b;
	int			count;

	count_a = ft_ps_get_list_count((*data)->list_a);
	count_b = ft_ps_get_list_count((*data)->list_b);
	ptr_list_a = (*data)->list_a;
	ptr_list_b = (*data)->list_b;
	count = count_a;
	if (count_b > count_a)
		count = count_b;
	ft_ps_print_debug_header(cmd);
	ft_ps_print_parameters(&ptr_list_a, &ptr_list_b, count);
	ft_ps_print_debug_footer();
}
