/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:06:57 by rkrechun          #+#    #+#             */
/*   Updated: 2024/02/23 15:51:19 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(char *str_1, char *str_2)
{
	while (*str_1 == *str_2 && *str_1)
	{
		++str_1;
		++str_2;
	}
	return (*str_1 - *str_2);
}

static void	error(t_stack_node **a, t_stack_node **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "ERROR\n", 6);
	exit (1);
}

static void	checker(t_stack_node **a, t_stack_node **b, char *command)
{
	if (!ft_strcmp(command, "pa\n"))
		pa(a, b, true);
	else if (!ft_strcmp(command, "pb\n"))
		pb(b, a, true);
	else if (!ft_strcmp(command, "sa\n"))
		sa(a, true);
	else if (!ft_strcmp(command, "sb\n"))
		sb(b, true);
	else if (!ft_strcmp(command, "ss\n"))
		ss(a, b, true);
	else if (!ft_strcmp(command, "ra\n"))
		ra(a, true);
	else if (!ft_strcmp(command, "rb\n"))
		rb(b, true);
	else if (!ft_strcmp(command, "rr\n"))
		rr(a, b, true);
	else if (!ft_strcmp(command, "rra\n"))
		rra(a, true);
	else if (!ft_strcmp(command, "rrb\n"))
		rrb(b, true);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(a, b, true);
	else
		error(a, b);
}

static void	call_get_next(t_stack_node **a, t_stack_node **b)
{
	int		len;
	char	*next_line;
	int		len_f;

	len = stack_len(*a);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		checker(a, b, next_line);
		free(next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	len_f = stack_len(*a);
	if (stack_sorted(*a) && len_f == len)
		write(1, "OK\n", 3);
	else
	{
		write(1, "KO\n", 3);
		printf("stack len in start : %d\n", len);
		printf("stack len in end: %d\n", len_f);
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		argv = split(argv[1], ' ');
		init_stack(&a, argv + 1);
	}
	else
		init_stack(&a, argv + 1);
	call_get_next(&a, &b);
	free_stack(&a);
	return (0);
}