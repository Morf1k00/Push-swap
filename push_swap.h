/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:32:45 by rkrechun          #+#    #+#             */
/*   Updated: 2024/03/04 15:11:21 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

//FIND node
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

//Handle errors
int				error_syntax(char *str_n);
int				error_duplicate(t_stack_node *a, int n);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **stack, char **argv,
					bool flag_argc_2);
void			free_matrix(char **argv);

//Initialization
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
void			init_node_a(t_stack_node*a, t_stack_node *b);
void			init_stack(t_stack_node **a, char **argv, bool flag_argc_2);
void			prep_for_push(t_stack_node **stack, t_stack_node *top_node,
					char stack_name);
char			**split(char *s, char c);

//Sorting
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			sort_three(t_stack_node **stack);
void			rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);
void			rev_rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);
void			min_on_top(t_stack_node **a);
int				stack_len(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);

//Commands
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);

//GET_NEXT_LINE
char			*get_next_line(int fd);
size_t			ft_strlen(char *s);
char			*ft_strchr(char *s, int c);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strjoin(char *str, char *buffer);
int				ft_clean(char *str);

#endif