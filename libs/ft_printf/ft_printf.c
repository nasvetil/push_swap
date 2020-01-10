/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:54:18 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:15:19 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int				ft_printf(const char *s, ...)
{
	t_pf		pf;

	ft_bzero((void*)(&pf), sizeof(pf));
	(&pf)->s = (char*)s;
	va_start((&pf)->arg, s);
	while (*(&pf)->s)
	{
		ft_parse_color(&pf);
		if (*(&pf)->s == '%')
		{
			(&pf)->s++;
			ft_parse_spec(&pf);
		}
		else
		{
			ft_pf_buff(&pf, &*pf.s, 1);
			(&pf)->s++;
		}
	}
	write(1, (&pf)->buff, (&pf)->buff_len);
	va_end((&pf)->arg);
	free((&pf)->buff);
	return ((&pf)->buff_len);
}

int				ft_dprintf(int fd, const char *s, ...)
{
	t_pf		pf;

	ft_bzero((void*)(&pf), sizeof(pf));
	(&pf)->s = (char*)s;
	va_start((&pf)->arg, s);
	while (*(&pf)->s)
	{
		ft_parse_color(&pf);
		if (*(&pf)->s == '%')
		{
			(&pf)->s++;
			ft_parse_spec(&pf);
		}
		else
		{
			ft_pf_buff(&pf, &*pf.s, 1);
			(&pf)->s++;
		}
	}
	write(fd, (&pf)->buff, (&pf)->buff_len);
	va_end((&pf)->arg);
	free((&pf)->buff);
	return ((&pf)->buff_len);
}

void			ft_pf_buff(t_pf *pf, void *cnt, size_t len)
{
	char		**ptr_cnt;
	void		*ptr_void;

	ptr_cnt = &pf->buff;
	if (*ptr_cnt == NULL)
		*ptr_cnt = ft_memalloc_exit(0);
	ptr_void = pf->buff;
	pf->buff = ft_memjoin(pf->buff, pf->buff_len, cnt, len);
	ft_bzero(ptr_void, pf->buff_len);
	pf->buff_len = pf->buff_len + len;
	free(ptr_void);
}
