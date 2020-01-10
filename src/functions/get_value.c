/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:17:31 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/27 19:59:39 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int			ft_get_max_value(t_list *elem)
{
	int		numb;
	t_list	*ptr_elem;

	ptr_elem = elem;
	numb = *(int*)ptr_elem->content;
	while (ptr_elem)
	{
		if (*(int*)ptr_elem->content > numb)
			numb = *(int*)ptr_elem->content;
		ptr_elem = ptr_elem->next;
	}
	return (numb);
}

int			ft_get_min_value(t_list *elem)
{
	int		numb;
	t_list	*ptr_elem;

	ptr_elem = elem;
	numb = *(int*)ptr_elem->content;
	while (ptr_elem)
	{
		if (*(int*)ptr_elem->content < numb)
			numb = *(int*)ptr_elem->content;
		ptr_elem = ptr_elem->next;
	}
	return (numb);
}

int			ft_get_median_value(t_list *elem)
{
	t_list	*ptr_elem_ref;
	t_list	*ptr_elem;
	int		more_count;
	int		less_count;

	ptr_elem_ref = elem;
	while (ptr_elem_ref)
	{
		more_count = 0;
		less_count = 0;
		ptr_elem = elem->next;
		while (ptr_elem)
		{
			if (*(int*)ptr_elem_ref->content > *(int*)ptr_elem->content)
				less_count++;
			else if (*(int*)ptr_elem_ref->content < *(int*)ptr_elem->content)
				more_count++;
			ptr_elem = ptr_elem->next;
		}
		if (ft_abs(more_count - less_count) <= 1)
			return (*(int*)ptr_elem_ref->content);
		ptr_elem_ref = ptr_elem_ref->next;
	}
	return (0);
}

int			ft_get_list_pos_min_max(t_list *elem, int n)
{
	int		i;
	t_list	*ptr_elem;

	i = 0;
	ptr_elem = elem;
	while (ptr_elem->next)
	{
		if (n > *(int*)ptr_elem->content && n < *(int*)ptr_elem->next->content)
			return (i);
		ptr_elem = ptr_elem->next;
		i++;
	}
	return (-1);
}
