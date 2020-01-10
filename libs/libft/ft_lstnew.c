/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:15:12 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/25 15:54:50 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	void	*new_content;

	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!(content))
	{
		list->content = NULL;
		list->content_size = 0;
		list->next = NULL;
		return (list);
	}
	if (!(new_content = (void*)malloc(content_size)))
		return (NULL);
	ft_memcpy(new_content, content, content_size);
	list->content = new_content;
	list->content_size = content_size;
	list->next = NULL;
	return (list);
}
