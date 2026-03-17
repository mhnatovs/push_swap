/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:41:19 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/10/18 13:45:37 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

void		init_stack(t_stack *stack);
void		free_stack(t_stack *stack);
t_stack		*create_empty_stack(void);
int			ft_stack_size(t_stack *stack);
int			get_index(t_stack *stack, t_node *node);
void		set_index(t_stack *a);
void		free_split(char **arr);
void		add_node_bottom(t_stack *stack, int value);
int			parse_args(t_stack *a, char **av);

void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		rra(t_stack *a, int print);
void		rrb(t_stack *b, int print);
void		rrr(t_stack *a, t_stack *b);
void		ra(t_stack *a, int print);
void		rb(t_stack *b, int print);
void		rr(t_stack *a, t_stack *b);
void		sa(t_stack *a, int print);
void		sb(t_stack *b, int print);
void		ss(t_stack *a, t_stack *b);

int			is_sorted(t_stack *a);
void		sort_for_three(t_stack *s_a);
void		sort_for_four(t_stack *a, t_stack *b);
void		sort_for_five(t_stack *a, t_stack *b);
t_node		*min(t_stack *stack);
void		simple_sort(t_stack **a, t_stack **b);
void		chunk_sort(t_stack *a, t_stack *b, int i, int chunk_size);
void		push_min_to_b(t_stack *a, t_stack *b);

#endif