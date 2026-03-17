/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:31:51 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/10/18 14:11:56 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_value(t_stack *s_a, int *a, int *b, int *c)
{
	*a = s_a->top->value;
	*b = s_a->top->next->value;
	*c = s_a->top->next->next->value;
}

void	sort_for_three(t_stack *s_a)
{
	int	a;
	int	b;
	int	c;

	if (!s_a || s_a->size < 3)
		return ;
	set_value(s_a, &a, &b, &c);
	if (a < b && b < c)
		return ;
	else if (a > b && b < c && a < c)
		sa(s_a, 1);
	else if (a > b && b > c)
	{
		sa(s_a, 1);
		rra(s_a, 1);
	}
	else if (a > b && b < c && a > c)
		ra(s_a, 1);
	else if (a < b && b > c && a < c)
	{
		sa(s_a, 1);
		ra(s_a, 1);
	}
	else if (a < b && b > c && a > c)
		rra(s_a, 1);
}

void	sort_for_four(t_stack *a, t_stack *b)
{
	push_min_to_b(a, b);
	sort_for_three(a);
	pa(a, b);
}

void	sort_for_five(t_stack *a, t_stack *b)
{
	push_min_to_b(a, b);
	sort_for_four(a, b);
	pa(a, b);
}

void	simple_sort(t_stack **a, t_stack **b)
{
	int	size;

	(void) b;
	if (is_sorted(*a) || ft_stack_size(*a) == 0
		|| ft_stack_size(*a) == 1)
		return ;
	size = ft_stack_size(*a);
	if (size == 2)
		sa(*a, 1);
	else if (size == 3)
		sort_for_three(*a);
	else if (size == 4)
		sort_for_four(*a, *b);
	else if (size == 5)
		sort_for_five(*a, *b);
}
