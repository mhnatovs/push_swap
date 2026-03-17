/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:39:38 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/10/14 19:50:24 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a, int print)
{
	t_node	*temp;

	if (!a || a->size < 2)
		return ;
	temp = a->bottom;
	a->bottom = temp->prev;
	if (a->bottom)
		a->bottom->next = NULL;
	temp->prev = NULL;
	temp->next = a->top;
	a->top->prev = temp;
	a->top = temp;
	if (print == 1)
		write (1, "rra\n", 4);
}

void	rrb(t_stack *b, int print)
{
	t_node	*temp;

	if (!b || b->size < 2)
		return ;
	temp = b->bottom;
	b->bottom = temp->prev;
	if (b->bottom)
		b->bottom->next = NULL;
	temp->prev = NULL;
	temp->next = b->top;
	b->top->prev = temp;
	b->top = temp;
	if (print == 1)
		write (1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, 0);
	rrb(b, 0);
	write (1, "rrr\n", 4);
}
