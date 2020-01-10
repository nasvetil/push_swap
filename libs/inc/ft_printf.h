/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:56:08 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/27 16:36:01 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <math.h>
# include "libft.h"

# define C_TX_BLACK "\033[30m"
# define C_TX_RED "\033[31m"
# define C_TX_GREEN "\033[32m"
# define C_TX_YELLOW "\033[33m"
# define C_TX_BLUE "\033[34m"
# define C_TX_MAGENTA "\033[35m"
# define C_TX_CYAN "\033[36m"
# define C_TX_GREY "\033[37m"
# define C_BASIC "\033[0m"

typedef struct			s_pf_param
{
	char				*str;
	int					str_len;
	char				*buff;
	int					buff_len;
	int					type_d;
	int					d_neg;
	int					d_zero;
	intmax_t			n;
}						t_pf_param;

typedef struct			s_pf_flags
{
	int					minus;
	int					plus;
	int					space;
	int					hash;
	int					zero;
}						t_pf_flags;

typedef struct			s_pf_size
{
	int					hh;
	int					h;
	int					l;
	int					ll;
	int					l_;
	int					j;
	int					z;
}						t_pf_size;

typedef	struct			s_pf_type
{
	int					c;
	int					s;
	int					p;
	int					d;
	int					i;
	int					o;
	int					u;
	int					u_;
	int					x;
	int					x_;
	int					f;
	int					per;
	int					b;
}						t_pf_type;

typedef struct			s_pf_spec
{
	struct s_pf_flags	flags;
	int					width;
	int					check_prec;
	int					prec;
	struct s_pf_size	size;
	struct s_pf_type	type;
	struct s_pf_param	param;
}						t_pf_spec;

typedef struct			s_pf
{
	va_list				arg;
	char				*s;
	char				*buff;
	size_t				buff_len;
	struct s_pf_spec	spec;
}						t_pf;

int						ft_check_flag(int c);
int						ft_check_type(int c);
int						ft_check_size(char *s);
int						ft_str_check_type(t_pf *pf);

void					ft_parse_color(t_pf *pf);

void					ft_get_float_digit(long double *n,
							char **str, int prec);
void					ft_get_float(long double n, char **s, int prec);
void					ft_put_float(t_pf *pf);

char					*ft_itoa_base_max(intmax_t n, int base);
char					*ft_itoa_u_base_max(uintmax_t n, int base);

int						ft_printf(const char *s, ...);
int						ft_dprintf(int fd, const char *s, ...);
void					ft_pf_buff(t_pf *pf, void *cnt, size_t len);

intmax_t				ft_get_number_u(t_pf *pf);
intmax_t				ft_get_number(t_pf *pf);
char					*ft_get_str_number(t_pf *pf, intmax_t n);

void					ft_put_number_param(t_pf *pf);
void					ft_put_clear_number(t_pf *pf);
void					ft_put_neg_number(t_pf *pf);
void					ft_put_number(t_pf *pf);
void					ft_put_digit(t_pf *pf);

int						ft_str_check_z(t_pf *pf);
void					ft_parse_correct(t_pf *pf);
void					ft_parse_spec_step(t_pf *pf);
int						ft_parse_spec(t_pf *pf);

void					ft_put_string_text(t_pf *pf, char *str);
void					ft_put_arg(t_pf *pf);

void					ft_put_str(t_pf *pf);

void					ft_put_number_sign(t_pf *pf, int *i_pos);
void					ft_set_empty_str(t_pf *pf);
void					ft_set_number_hash_flags(t_pf *pf);
void					ft_set_number_flags(t_pf *pf);
void					ft_set_number_width(t_pf *pf);

void					ft_set_flags(t_pf *pf);
void					ft_set_width(t_pf *pf);
void					ft_set_prec(t_pf *pf);
void					ft_set_size(t_pf *pf);
void					ft_set_type(t_pf *pf);

void					ft_put_param_string(t_pf *pf);
void					ft_set_string_buff(t_pf *pf);
void					ft_set_string_flags(t_pf *pf);
void					ft_put_string(t_pf *pf, char **str_str);
void					*ft_strsplit_del(char ***ap);

#endif
