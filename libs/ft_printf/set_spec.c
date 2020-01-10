/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_spec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 09:30:33 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/15 11:15:36 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void			ft_set_flags(t_pf *pf)
{
	pf->spec.flags.minus = (*pf->s == '-') || pf->spec.flags.minus;
	pf->spec.flags.plus = (*pf->s == '+') || pf->spec.flags.plus;
	pf->spec.flags.space = (*pf->s == ' ') || pf->spec.flags.space;
	pf->spec.flags.hash = (*pf->s == '#') || pf->spec.flags.hash;
	pf->spec.flags.zero = (*pf->s == '0') || pf->spec.flags.zero;
	pf->s++;
}

void			ft_set_width(t_pf *pf)
{
	char		*str;

	pf->spec.width = 0;
	if (*pf->s == '*')
	{
		pf->spec.width = va_arg(pf->arg, int);
		pf->s++;
	}
	else
	{
		pf->spec.width = ft_atoi(pf->s);
		str = ft_itoa(pf->spec.width);
		if (pf->spec.width > 0)
			pf->s += sizeof(const char) * ft_strlen(str);
		else
			pf->s++;
		free(str);
	}
}

void			ft_set_prec(t_pf *pf)
{
	char		*str;

	pf->spec.check_prec = 1;
	pf->spec.prec = 0;
	pf->s++;
	if (*pf->s == '*')
	{
		pf->spec.prec = va_arg(pf->arg, int);
		pf->s++;
	}
	else
	{
		pf->spec.prec = ft_atoi(pf->s);
		str = ft_itoa(pf->spec.prec);
		if (pf->spec.prec > 0)
			pf->s += sizeof(const char) * ft_strlen(str);
		free(str);
	}
}

void			ft_set_size(t_pf *pf)
{
	int	i;

	i = 1;
	if (pf->s[0] == 'h')
	{
		while (pf->s[i] == 'h')
			i++;
		pf->spec.size.h = (i % 2) * 1;
		pf->spec.size.hh = !(i % 2) * 1;
	}
	else if (pf->s[0] == 'l')
	{
		while (pf->s[i] == 'l')
			i++;
		pf->spec.size.l = (i % 2) * 1;
		pf->spec.size.ll = !(i % 2) * 1;
	}
	else if (pf->s[0] == 'L')
		pf->spec.size.l_ = 1;
	else if (pf->s[0] == 'j')
		pf->spec.size.j = 1;
	else if (pf->s[0] == 'z')
		pf->spec.size.z = 1;
	pf->s += sizeof(const char) * i;
}

void			ft_set_type(t_pf *pf)
{
	pf->spec.type.c = (*pf->s == 'c');
	pf->spec.type.s = (*pf->s == 's');
	pf->spec.type.p = (*pf->s == 'p');
	pf->spec.type.d = (*pf->s == 'd');
	pf->spec.type.i = (*pf->s == 'i');
	pf->spec.type.o = (*pf->s == 'o');
	pf->spec.type.u = (*pf->s == 'u');
	pf->spec.type.u_ = (*pf->s == 'U');
	pf->spec.type.x = (*pf->s == 'x');
	pf->spec.type.x_ = (*pf->s == 'X');
	pf->spec.type.f = (*pf->s == 'f');
	pf->spec.type.per = (*pf->s == '%');
	pf->spec.type.b = (*pf->s == 'b');
	pf->s++;
}
