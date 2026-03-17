/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:30:35 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/10/17 16:25:37 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

int	ft_stack_size(t_stack *stack)
{
	int		i;
	t_node	*current;

	i = 0;
	current = stack->top;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

void	add_node_bottom(t_stack *stack, int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	if (stack->size == 0)
	{
		stack->top = new;
		stack->bottom = new;
	}
	else
	{
		stack->bottom->next = new;
		new->prev = stack->bottom;
		stack->bottom = new;
	}
	stack->size++;
}

void	free_stack(t_stack *stack)
{
	t_node	*temp;

	while (stack->top)
	{
		temp = stack->top;
		stack->top = stack->top->next;
		free(temp);
	}
	stack->bottom = NULL;
	stack->size = 0;
}

t_stack	*create_empty_stack(void)
{
	t_stack	*st;

	st = malloc(sizeof(t_stack));
	if (!st)
		return (NULL);
	init_stack(st);
	return (st);
}

// #include <unistd.h>
// #include <stdlib.h>
// void printstack(t_stack *stack, char name)
// {
// 	t_node *temp;

// 	if(!stack)
// 	return;
// 	printf("      stack %c (size = %d):\n", name, stack->size);
// 	temp = stack->top;
// 	while (temp)
// 	{
// 	printf("   value:%-6d - index: %-3d\n",temp->value,temp->index);
// 	temp = temp->next;
// 	}
// 	printf("\t****done****\n");
// }
// int	main(int ac, char **av)
// {
// 	t_stack	*a;
// 	t_stack	*b;

// 	if (ac < 2)
// 		return (1);
// 	a = create_empty_stack();
// 	b = create_empty_stack();
// 	if (!a || !b)
// 	return (1);
// 	if (!parse_args(a, av))
// 	{
// 		write(2, "Error\n", 6);
// 		free_stack(a);
// 		free_stack(b);
// 		free(a);
// 		free(b);
// 		return (1);
// 	}
// 	set_index(a);
// 	// add_node_top(a, 1);
// 	printstack(a, 'a');
// 	if(is_sorted(a) == 1)
// 		printf("\nit works");
// 	// if (is_sorted(a))
// 		// return (free_stack(a), free_stack(b), 0);
// 	// sort_stack(a, b);
// 	free_stack(a);
// 	free_stack(b);
// 	free(a);
// 	free(b);
// 	// free_stack(b);
// 	return (0);
// }
// void	add_node_top(t_stack *stack, int value)
// {
// 	t_node	*new;

// 	new = malloc(sizeof(t_node));
// 	if (!new)
// 		return ;
// 	new->value = value;
// 	new->next = NULL;
// 	new->prev = NULL;
// 	if (stack->size == 0)
// 	{
// 		stack->top = new;
// 		stack->bottom = new;
// 	}
// 	else
// 	{
// 		new->next = stack->top;
// 		stack->top->prev = new;
// 		stack->top = new;
// 	}
// 	stack->size++;
// }