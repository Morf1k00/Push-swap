/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:45:30 by rkrechun          #+#    #+#             */
/*   Updated: 2024/02/23 16:00:56 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_sorting(t_stack_node **a, t_stack_node **b)
{
	if (!stack_sorted(*a))
	{
		if (stack_len(*a) == 2)
			sa(a, false);
		else if (stack_len(*a) == 3)
			sort_three(a);
		else
			sort_stacks(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = split(argv[1], ' ');
		init_stack(&a, argv + 1);
		free_matrix(argv + 1);
	}
	else
		init_stack(&a, argv + 1);
	check_sorting(&a, &b);
	free_stack(&a);
	return (0);
}
