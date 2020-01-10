/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 09:48:45 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/27 20:14:59 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include <stdio.h>

int			ft_ps_get_list_count(t_list *list)
{
	t_list	*ptr_list;
	int		i;

	ptr_list = list;
	i = 0;
	while (ptr_list)
	{
		ptr_list = ptr_list->next;
		i++;
	}
	return (i);
}

int			ft_ps_check_arg(char *arg)
{
	while (*arg)
	{
		if (*arg != ' ' && !ft_isdigit(*arg))
		{
			if (!(*arg == '-' && ft_isdigit(arg[1])))
				return (0);
		}
		arg++;
	}
	return (1);
}

int			ft_ps_get_strsplit_count(char **array)
{
	char	**ptr_array;
	int		count;

	ptr_array = array;
	count = 0;
	while (*ptr_array++)
		count++;
	return (count);
}

void		ft_ps_parse_arg(t_ps_data **data, char *arg)
{
	int		numb;
	char	**array;
	int		len;

	array = ft_strsplit(arg, ' ');
	len = ft_ps_get_strsplit_count(array);
	while (len--)
	{
		numb = ft_atoi_int(array[len]);
		if (numb == 0 && array[len][0] != '0')
			ft_ps_exit(data);
		ft_ps_set_new_arg(numb, &(*data)->list_a);
		(*data)->count++;
	}
	ft_strsplit_del(&array);
}

void		ft_ps_set_stacks(t_ps_data **data, int argc, char **argv)
{
	int		i;

	(*data)->count = 0;
	i = argc - 1;
	while (i >= 1)
	{
		if (ft_strcmp(argv[i], "-v") == 0 &&
			!(*data)->check_v_flag)
			(*data)->check_v_flag = 1;
		else if (ft_ps_check_arg(argv[i]))
			ft_ps_parse_arg(data, argv[i]);
		else
			ft_ps_exit(data);
		i--;
	}
}
