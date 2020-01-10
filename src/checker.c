/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:22:11 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/27 21:28:16 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

static void		ft_ps_check_cmd(char *str, t_ps_data **data)
{
	if (!(!ft_strcmp(str, "sa") || !ft_strcmp(str, "sb") ||
		!ft_strcmp(str, "ss") || !ft_strcmp(str, "pa") ||
		!ft_strcmp(str, "pb") || !ft_strcmp(str, "ra") ||
		!ft_strcmp(str, "rb") || !ft_strcmp(str, "rr") ||
		!ft_strcmp(str, "rra") || !ft_strcmp(str, "rrb") ||
		!ft_strcmp(str, "rrr")))
	{
		ft_ps_exit(data);
	}
}

static void		ft_ps_checker_step(t_ps_data **data, char *str)
{
	if (!ft_strcmp(str, "sa"))
		ft_ps_cmd_sa(data);
	if (!ft_strcmp(str, "sb"))
		ft_ps_cmd_sb(data);
	if (!ft_strcmp(str, "ss"))
		ft_ps_cmd_ss(data);
	if (!ft_strcmp(str, "ra"))
		ft_ps_cmd_ra(data);
	if (!ft_strcmp(str, "rb"))
		ft_ps_cmd_rb(data);
	if (!ft_strcmp(str, "rr"))
		ft_ps_cmd_rr(data);
	if (!ft_strcmp(str, "rra"))
		ft_ps_cmd_rra(data);
	if (!ft_strcmp(str, "rrb"))
		ft_ps_cmd_rrb(data);
	if (!ft_strcmp(str, "rrr"))
		ft_ps_cmd_rrr(data);
	if (!ft_strcmp(str, "pa"))
		ft_ps_cmd_pa(data);
	if (!ft_strcmp(str, "pb"))
		ft_ps_cmd_pb(data);
}

static char		*ft_ps_checker_op(t_ps_data **data)
{
	t_list	*ptr_cmd;
	char	*str;

	ptr_cmd = (*data)->cmd;
	while (ptr_cmd)
	{
		str = (char*)ptr_cmd->content;
		ft_ps_checker_step(data, str);
		ptr_cmd = ptr_cmd->next;
	}
	if (ft_ps_check_sort((*data)->list_a) && (*data)->list_b == NULL)
		return ("OK");
	return ("KO");
}

static t_list	*ft_ps_get_input(t_ps_data **data)
{
	char	*line;
	int		i;
	t_list	*commands;
	t_list	*next_command;
	size_t	len;

	i = 0;
	commands = NULL;
	next_command = NULL;
	while ((len = get_next_line_count(0, &line)) && len - 1 > 0)
	{
		ft_ps_check_cmd(line, data);
		next_command = ft_lstnew(line, len);
		((char*)next_command->content)[len - 1] = '\0';
		ft_lstpush(&commands, &next_command);
		commands = ft_lstrotate(commands);
		free(line);
	}
	(*data)->cmd = commands;
	return (commands);
}

int				main(int argc, char **argv)
{
	t_ps_data		*data;
	char			*rlt;

	if (argc == 1)
		ft_ps_exit_not_error(NULL);
	data = ft_memalloc_exit(sizeof(t_ps_data));
	ft_bzero(data, sizeof(t_ps_data));
	data->check_checker = 1;
	ft_ps_set_stacks(&data, argc, argv);
	ft_lstiter(data->list_a, ft_ps_check_stack);
	data->cmd = ft_ps_get_input(&data);
	rlt = ft_ps_checker_op(&data);
	ft_printf("%s\n", rlt);
	ft_lstdel(&data->list_a, ft_ps_free_cnt);
	ft_lstdel(&data->list_b, ft_ps_free_cnt);
	ft_lstdel(&data->cmd, ft_ps_free_cnt);
	ft_bzero(data, sizeof(t_ps_data));
	free(data);
	return (0);
}
