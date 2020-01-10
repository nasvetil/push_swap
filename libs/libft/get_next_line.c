/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 12:41:33 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:19:51 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list_fd	*ft_get_list(t_list_fd **stat_list, int fd)
{
	t_list_fd	*ptr_list;

	if (!stat_list)
		return (NULL);
	ptr_list = (*stat_list);
	while (ptr_list)
	{
		if ((int)ptr_list->fd == fd)
			return (ptr_list);
		ptr_list = ptr_list->next;
	}
	ptr_list = ft_lstnew_fd("", 0, fd);
	ft_lstadd_fd(stat_list, ptr_list);
	return (ptr_list);
}

int			ft_read_line(char **cnt, int len, const int fd)
{
	int		len_line;
	int		read_result;
	char	*temp;
	char	buff[BUFF_SIZE];

	read_result = len;
	if (ft_memchr(*cnt, '\n', len))
		return (read_result);
	while ((len_line = read(fd, buff, BUFF_SIZE)))
	{
		temp = *cnt;
		*cnt = ft_memjoin(*cnt, read_result, buff, len_line);
		if (!(*cnt))
			return (0);
		free(temp);
		read_result += len_line;
		if (ft_memchr(buff, '\n', len_line))
			break ;
		ft_bzero(buff, BUFF_SIZE);
	}
	return (read_result);
}

int			ft_line_copy(char **line, char *cnt, size_t len, char c)
{
	size_t	i;

	i = 0;
	while (i < len && cnt[i] != c)
		i++;
	*line = ft_memalloc_exit(i + 1);
	ft_memcpy(*line, cnt, i);
	if (!(*line))
		return (0);
	return (i);
}

int			get_next_line(const int fd, char **line)
{
	size_t				len_line;
	static t_list_fd	*list;
	t_list_fd			*ptr_list;
	char				*temp;

	if (fd < 0 || fd > 10240 || !line || read(fd, *line, 0) < 0
		|| (!(ptr_list = ft_get_list(&list, fd))))
		return (-1);
	ptr_list->size = ft_read_line((char**)&(ptr_list->cnt), ptr_list->size, fd);
	if (!ptr_list->size)
		return (0);
	len_line = ft_line_copy(line, ptr_list->cnt, ptr_list->size, '\n');
	temp = ptr_list->cnt;
	if (len_line < ptr_list->size)
	{
		ptr_list->cnt = ft_memcpy(
			ft_memalloc_exit(ptr_list->size - len_line + 1),
			&((ptr_list->cnt)[len_line + 1]),
			ptr_list->size - len_line - 1);
		ptr_list->size = ptr_list->size - len_line - 1;
	}
	else
		ptr_list->size = 0;
	free(temp);
	return (1);
}

int			get_next_line_count(const int fd, char **line)
{
	size_t				len_line;
	static t_list_fd	*list;
	t_list_fd			*ptr_list;
	char				*temp;

	if (fd < 0 || fd > 10240 || !line || read(fd, *line, 0) < 0
		|| (!(ptr_list = ft_get_list(&list, fd))))
		return (-1);
	ptr_list->size = ft_read_line((char**)&(ptr_list->cnt), ptr_list->size, fd);
	if (!ptr_list->size)
		return (0);
	len_line = ft_line_copy(line, ptr_list->cnt, ptr_list->size, '\n');
	temp = ptr_list->cnt;
	if (len_line < ptr_list->size)
	{
		ptr_list->cnt = ft_memcpy(
			ft_memalloc_exit(ptr_list->size - len_line + 1),
			&((ptr_list->cnt)[len_line + 1]),
			ptr_list->size - len_line - 1);
		ptr_list->size = ptr_list->size - len_line - 1;
	}
	else
		ptr_list->size = 0;
	free(temp);
	return (len_line + 1);
}
