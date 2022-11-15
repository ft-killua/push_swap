/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 03:11:10 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/15 21:08:23 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"
# define YES 1
# define NO 0
/*             structs               */
typedef struct s_stack
{
	int	*number;
	int	size;
	int	u_size;
}	t_stack;

typedef struct s_both
{
	t_stack	stack_a;
	t_stack	stack_b;
}	t_both;

/*        opreation functions        */
void    ft_sa_or_sb(t_stack *stack, int print, char flag);
void    ft_sa_and_sb(t_both *stacks, int print);
void    ft_rotate_a(t_stack *stack_a, int print);
void    ft_rotate_b(t_stack *stack_b, int print);
void    ft_rotate_a_b(t_both *stacks,int print);

void    ft_shift_up(int *data, int u_size);
void    ft_shift_down(int *data, int u_size);
void    ft_push_stack_a(t_both *stacks, int print);
void    ft_push_stack_b(t_both *stacks, int print);

void	ft_reverse_rotate_a(t_stack *stack_a, int print);
void	ft_reverse_rotate_b(t_stack *stack_b, int print);
void	ft_reverse_rotate_a_b(t_both *stacks, int print);

int     ft_stack_sorted(t_stack *stack_a);
int	    ft_min_index(t_stack *stack_a);
void	ft_min_to_top_five(t_both *stacks);
void	ft_min_to_top_ten(t_both *stacks);
void    ft_sort_three(t_stack *stack_a);
void	ft_sort_five(t_both *stacks);
void	ft_sort_ten(t_both *stacks);
void    ft_sort_five_to_ten(t_both *stacks, int size);//
void    ft_sort_rest_one_handred(t_both *stacks);
void    ft_sort_rest_five_handred(t_both *stacks);

//not
int	    ft_get_index_of(t_both *stacks, int num);
void	ft_move_top(t_both *stacks, int index);
void	ft_push_under(t_both *stacks, int target);
void    ft_one_handred(t_both *stacks);
void    ft_swap(int *x, int *y);
int     *ft_init_array(t_stack *stack_a);
int     *ft_sort_array(t_stack *stack_a);
void    ft_five_handred(t_both *stacks);

//
void    ft_sort_five_to_ten(t_both *stacks, int size);
int     ft_magic(int *sorted_array, int size, int div, int chunks);
int     ft_get_max_index(t_stack *stack_b);
void    ft_max_to_top(t_both *stacks);

int	    ft_get_index_of(t_both *stacks, int target);
void	ft_move_top(t_both *stacks, int index);
void	ft_push_under(t_both *stacks, int num);
void    ft_one_handred(t_both *stacks);

int     ft_check_nbr(char *nbr);
int     ft_check_dup(t_both *stacks, int nbr);
int     ft_nbrs_counter(char *str);
int     ft_error(char *err_msg, int ret_val, t_both *stacks);

//change
char    **ft_new_stacks(char *str, t_both *stacks);
t_both	ft_store_numbers(char *str);
int     ft_check_arg(char *av);
char	*ft_av_to_string(char **av);
#endif






// int	ft_check_arg(char *av)
// {
// 	int i;

// 	i = 0;
// 	while (av[i])
// 	{
// 		if (!ft_isdigit(av[i]))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }