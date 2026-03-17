/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:52:27 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/10/14 19:13:27 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, int print)
{
	t_node	*first;
	t_node	*second;
	int		tmp;

	if (!a || a->size < 2)
		return ;
	first = a->top;
	second = a->top->next;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
	if (print == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, int print)
{
	t_node	*first;
	t_node	*second;
	int		tmp;

	if (!b || b->size < 2)
		return ;
	first = b->top;
	second = b->top->next;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
	if (print == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, 0);
	sb(b, 0);
	write(1, "ss\n", 3);
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
	// ss(&a, 1);
	print_stack(&a);
	ss(&a, &b);
	print_stack(&a);
}*/