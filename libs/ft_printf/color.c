/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:45:48 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:15:11 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int		ft_set_color(t_pf *pf, size_t len)
{
	if (!ft_strncmp(pf->s, "black", len))
		ft_put_string_text(pf, C_TX_BLACK);
	else if (!ft_strncmp(pf->s, "red", len))
		ft_put_string_text(pf, C_TX_RED);
	else if (!ft_strncmp(pf->s, "green", len))
		ft_put_string_text(pf, C_TX_GREEN);
	else if (!ft_strncmp(pf->s, "yellow", len))
		ft_put_string_text(pf, C_TX_YELLOW);
	else if (!ft_strncmp(pf->s, "blue", len))
		ft_put_string_text(pf, C_TX_BLUE);
	else if (!ft_strncmp(pf->s, "magenta", len))
		ft_put_string_text(pf, C_TX_MAGENTA);
	else if (!ft_strncmp(pf->s, "cyan", len))
		ft_put_string_text(pf, C_TX_CYAN);
	else if (!ft_strncmp(pf->s, "grey", len))
		ft_put_string_text(pf, C_TX_GREY);
	else if (!ft_strncmp(pf->s, "eoc", len))
		ft_put_string_text(pf, C_BASIC);
	else
		return (0);
	return (1);
}

void			ft_parse_color(t_pf *pf)
{
	size_t		len;

	if (*pf->s == '{' && ft_strchr(pf->s, '}'))
	{
		pf->s++;
		len = ft_strclen(pf->s, '}');
		if (ft_set_color(pf, len))
		{
			pf->s = ft_strchr(pf->s, '}');
			pf->s++;
		}
		else
			pf->s--;
	}
}
