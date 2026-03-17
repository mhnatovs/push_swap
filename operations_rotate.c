/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:13:49 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/10/14 19:38:57 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, int print)
{
	t_node	*temp;

	if (!a || a->size < 2)
		return ;
	temp = a->top;
	a->top = temp->next;
	a->top->prev = NULL;
	temp->next = NULL;
	temp->prev = a->bottom;
	a->bottom->next = temp;
	a->bottom = temp;
	if (print == 1)
		write (1, "ra\n", 3);
}

void	rb(t_stack *b, int print)
{
	t_node	*temp;

	if (!b || b->size < 2)
		return ;
	temp = b->top;
	b->top = temp->next;
	b->top->prev = NULL;
	temp->next = NULL;
	temp->prev = b->bottom;
	b->bottom->next = temp;
	b->bottom = temp;
	if (print == 1)
		write (1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a, 0);
	rb(b, 0);
	write (1, "rr\n", 3);
}
/*#include <stdio.h>
	void	print_stack(t_stack *stack)
{
	t_node *current = stack->top;
	
	printf("Stack (size=%d): ", stack->size);
	while (current)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}
void init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}
t_node *new_node(int value)
{
	t_node *node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
void stack_push_back(t_stack *stack, int value)
{
	t_node *node = new_node(value);
	if (!node)
		return ;
	if (stack->size == 0)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		stack->bottom->next = node;
		node->prev = stack->bottom;
		stack->bottom = node;
	}
	stack->size++;
}
#include <string.h>
void load_stack_from_args(t_stack *stack, char **argv)
{
	int i = 1;
	while (argv[i])
	{
		stack_push_back(stack, atoi(argv[i]));
		i++;
	}
}
int main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	init_stack(&a);
	init_stack(&b);
	load_stack_from_args(&a, argv);
	load_stack_from_args(&b, argv);
	print_stack(&a);
	print_stack(&b);
	rr(&a, &b);
	ra(&a, 1);
	rb(&b, 1);
	rr(&a, &b);
	rb(&b, 1);
	print_stack(&a);
	print_stack(&b);
}*/