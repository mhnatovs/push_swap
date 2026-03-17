/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:53:14 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/10/15 09:44:48 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (!b || b->size == 0)
		return ;
	temp = b->top;
	b->top = temp->next;
	if (b->top)
		b->top->prev = NULL;
	else
		b->bottom = NULL;
	b->size--;
	temp->next = a->top;
	temp->prev = NULL;
	if (a->top)
		a->top->prev = temp;
	else
		a->bottom = temp;
	a->top = temp;
	a->size++;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (!a || a->size == 0)
		return ;
	temp = a->top;
	a->top = temp->next;
	if (a->top)
		a->top->prev = NULL;
	else
		a->bottom = NULL;
	a->size--;
	temp->next = b->top;
	temp->prev = NULL;
	if (b->top)
		b->top->prev = temp;
	else
		b->bottom = temp;
	b->top = temp;
	b->size++;
	write(1, "pb\n", 3);
}
