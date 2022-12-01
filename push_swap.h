/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:22:21 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/28 18:22:20 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# define YES 1
# define NO 0
# include "get_next_line/get_next_line.h"

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
}	t_stack;

long long	ft_atoi(char *str);
t_stack		*ft_create_node(long int a);
void		ft_add_node_back(t_stack **stack, long int a);
int			ft_error(char *err_msg, int ret);
void		ft_init_stack_sorted_array(t_stack **stack_a, int *sorted_arr,
				int ac, char **av);
void		ft_fill_indexs(t_stack **stack_a, int *sorted_arr, int size);
int			ft_issorted(t_stack	**stack_a);
void		ft_sort_array(int *array, int size);
void		ft_push_swap(t_stack **stack_a, t_stack **stack_b, int size);
void		ft_sa_sb_ss(t_stack **stack_a, t_stack **stack_b,
				int print, char stack);
void		ft_pa_pb(t_stack **stack_a, t_stack **stack_b,
				int print, char stack);
void		ft_ra_rb_rr(t_stack **stack_a, t_stack **stack_b,
				int print, char stack);
void		ft_rra_rrb_rrr(t_stack **stack_a, t_stack **stack_b,
				int print, char stack);
void		ft_rotate(t_stack **stack_a);
void		ft_sort_three(t_stack **stack_a, t_stack **stack_b);
void		ft_sort_five(t_stack **stack_a, t_stack **stack_b, int size);
void		ft_push_swap(t_stack **stack_a, t_stack **stack_b, int size);
int			ft_stack_used_size(t_stack *stack);
void		ft_sort_100_500(t_stack **stack_a, t_stack **stack_b,
				int size, int flag);
void		ft_putendl_fd(char *s, int fd);
void		ft_isdup(int ac, char **av);
int			ft_check_nbr(char *nbr);
void		ft_exec_instructions(t_stack **stack_a, t_stack **stack_b,
				char *instructon);
char		**ft_split(char const *s, char c, int *ac);
char		*ft_av_to_string(char **av);
void		ft_init_stack_sorted_array2(t_stack **stack_a,
				int *sorted_arr, char **av);
void		ft_isdup2(char **av);
#endif