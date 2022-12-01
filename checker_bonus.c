/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:24:06 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/11/29 00:40:21 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_exec_instructions(t_stack **stack_a, t_stack **stack_b,
			char *instruction)
{
	if (!ft_strcmp(instruction, "sa\n"))
		ft_sa_sb_ss(stack_a, stack_b, NO, 'a');
	else if (!ft_strcmp(instruction, "sb\n"))
		ft_sa_sb_ss(stack_a, stack_b, NO, 'b');
	else if (!ft_strcmp(instruction, "ss\n"))
		ft_sa_sb_ss(stack_a, stack_b, NO, 'x');
	else if (!ft_strcmp(instruction, "ra\n"))
		ft_ra_rb_rr(stack_a, stack_b, NO, 'a');
	else if (!ft_strcmp(instruction, "rb\n"))
		ft_ra_rb_rr(stack_a, stack_b, NO, 'b');
	else if (!ft_strcmp(instruction, "rr\n"))
		ft_ra_rb_rr(stack_a, stack_b, NO, 'x');
	else if (!ft_strcmp(instruction, "rra\n"))
		ft_rra_rrb_rrr(stack_a, stack_b, NO, 'a');
	else if (!ft_strcmp(instruction, "rrb\n"))
		ft_rra_rrb_rrr(stack_a, stack_b, NO, 'b');
	else if (!ft_strcmp(instruction, "rrr\n"))
		ft_rra_rrb_rrr(stack_a, stack_b, NO, 'x');
	else if (!ft_strcmp(instruction, "pa\n"))
		ft_pa_pb(stack_a, stack_b, NO, 'a');
	else if (!ft_strcmp(instruction, "pb\n"))
		ft_pa_pb(stack_a, stack_b, NO, 'b');
	else
		exit(ft_error("Error", 0));
}

void	ft_checker(t_stack **stack_a, t_stack **stack_b)
{
	char	*instruction;

	instruction = get_next_line(0);
	while (instruction)
	{
		ft_exec_instructions(stack_a, stack_b, instruction);
		free(instruction);
		instruction = get_next_line(0);
	}
	if (ft_issorted(stack_a))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

void	ft_norm(int size, int *sorted_arr, t_stack **stack_a, t_stack **stack_b)
{
	ft_sort_array(sorted_arr, size);
	ft_fill_indexs(stack_a, sorted_arr, size);
	ft_checker(stack_a, stack_b);
}

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*sorted_arr;
	char	**splited;

	splited = NULL;
	if (ac == 2)
		splited = ft_split(av[1], ' ', &ac);
	if (ac > 2)
	{
		sorted_arr = malloc(sizeof(int) * (ac - 1));
		if (splited)
		{
			ft_init_stack_sorted_array2(&stack_a, sorted_arr, splited);
			ft_isdup2(splited);
		}
		else
		{
			ft_init_stack_sorted_array(&stack_a, sorted_arr, ac, av);
			ft_isdup(ac, av);
		}
		if (ft_issorted(&stack_a))
			return (0);
		ft_norm(ac - 1, sorted_arr, &stack_a, &stack_b);
	}
}
