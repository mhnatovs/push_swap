/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:41:16 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/10/18 14:36:37 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	chunk_size;

	i = 0;
	chunk_size = 25;
	if (ft_stack_size(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		chunk_sort(*stack_a, *stack_b, i, chunk_size);
}

static void	free_func(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (1);
	a = create_empty_stack();
	b = create_empty_stack();
	if (!a || !b)
		return (1);
	if (!parse_args(a, av))
	{
		write(2, "Error\n", 6);
		free_func(a, b);
		return (1);
	}
	set_index(a);
	if (is_sorted(a))
		return (free_func(a, b), 0);
	sort_stack(&a, &b);
	free_func(a, b);
	return (0);
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
// ./push_swap 3 2 1 &
// leaks $(pgrep push_swap)