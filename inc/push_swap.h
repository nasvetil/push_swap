/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:24:46 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/27 21:26:50 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# include "../libs/inc/ft_printf.h"
# include "../libs/inc/libft.h"

typedef struct		s_ps_op
{
	int				ra_count;
	int				rb_count;
	int				rr_count;
	int				rra_count;
	int				rrb_count;
	int				rrr_count;
	int				check_alg_4_5;
}					t_ps_op;

typedef struct		s_ps_data
{
	int				check_v_flag;
	int				check_checker;
	t_list			*list_a;
	t_list			*list_b;
	t_list			*cmd;
	int				count;
	int				count_a;
	int				count_b;
	int				max;
	int				min;
	int				median;
}					t_ps_data;

void				ft_ps_debug(t_ps_data **data, char *cmd);

void				ft_ps_check_stack(t_list *list);
int					ft_ps_check_sort(t_list *lst);
void				ft_ps_data_del(t_ps_data **data);
void				ft_ps_exit(t_ps_data **data);
void				ft_ps_print_cmd(t_ps_data **data, char *str);

int					ft_ps_get_list_count(t_list *list);
int					ft_ps_check_arg(char *arg);
int					ft_ps_get_strsplit_count(char **array);
void				ft_ps_parse_arg(t_ps_data **data, char *arg);
void				ft_ps_set_stacks(t_ps_data **data, int argc, char **argv);

int					ft_get_max_value(t_list *elem);
int					ft_get_min_value(t_list *elem);
int					ft_get_median_value(t_list *elem);
int					ft_get_list_pos_min_max(t_list *elem, int n);

void				ft_ps_free_cnt(void *s, size_t n);
void				ft_ps_set_new_arg(int numb, t_list **lst);
void				ft_ps_print_list_int(t_list *elem);
void				ft_ps_error(char *str);
void				ft_ps_exit_not_error(t_ps_data **data);

void				ft_ps_cmd_ra(t_ps_data **data);
void				ft_ps_cmd_rb(t_ps_data **data);
void				ft_ps_cmd_rr(t_ps_data **data);

void				ft_ps_cmd_rra(t_ps_data **data);
void				ft_ps_cmd_rrb(t_ps_data **data);
void				ft_ps_cmd_rrr(t_ps_data **data);

void				ft_ps_cmd_sa(t_ps_data **data);
void				ft_ps_cmd_sb(t_ps_data **data);
void				ft_ps_cmd_ss(t_ps_data **data);

void				ft_ps_cmd_pa(t_ps_data **data);
void				ft_ps_cmd_pb(t_ps_data **data);

int					ft_ps_check_rotates_sort(t_list *lst, int min);
int					ft_ps_check_rotates_op(t_ps_op *rotate_1,
						t_ps_op *rotate_2);

void				ft_ps_set_basic_numbers(t_ps_data **data);
int					ft_ps_check_basic_numbers(t_ps_data **data);
void				ft_ps_push_a_to_b_spec(t_ps_data **data);
void				ft_ps_push_a_to_b(t_ps_data **data);
t_list				*ft_ps_algorithm(t_ps_data **data);

void				ft_ps_search_rotate(t_ps_data **data);

t_list				*ft_ps_rotate_cycle_list(t_ps_data **data);

t_list				*ft_ps_alg_3_elem(t_ps_data **data);
t_list				*ft_ps_alg_4_5_elem(t_ps_data **data);

void				ft_ps_alg_3_swap(t_ps_data **data);

int					ft_ps_check_rotates_sort_rev_new(t_ps_data **data);

#endif
