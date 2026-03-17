/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:21:34 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/10/18 14:22:28 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_max(t_stack *stack)
{
	t_node	*cur;
	t_node	*max;

	cur = stack->top;
	max = cur;
	while (cur)
	{
		if (cur->index > max->index)
			max = cur;
		cur = cur->next;
	}
	return (max);
}

static void	rotate_correctly(t_stack *stack, int pos, char name)
{
	if (pos <= stack->size / 2)
	{
		while (pos-- > 0)
		{
			if (name == 'a')
				ra(stack, 1);
			else if (name == 'b')
				rb(stack, 1);
		}
	}
	else
	{
		while (pos++ < stack->size)
		{
			if (name == 'a')
				rra(stack, 1);
			else if (name == 'b')
				rrb(stack, 1);
		}
	}
}

void	move_back_to_a(t_stack *a, t_stack *b)
{
	t_node	*max;
	int		pos;

	while (b->size > 0)
	{
		max = find_max(b);
		pos = get_index(b, max);
		rotate_correctly(b, pos, 'b');
		pa(a, b);
	}
}

static void	set_values(t_stack *a, int *pos, t_node **temp)
{
	*temp = a->top;
	*pos = 0;
}

void	chunk_sort(t_stack *a, t_stack *b, int i, int chunk_size)
{
	int		total_size;
	t_node	*temp;
	int		pos;
	int		pushed;

	total_size = a->size;
	while (i < total_size)
	{
		pushed = 0;
		while (pushed++ < chunk_size && a->size > 0)
		{
			set_values(a, &pos, &temp);
			while (temp && !(temp->index >= i && temp->index < i + chunk_size))
			{
				temp = temp->next;
				pos++;
			}
			if (!temp)
				break ;
			rotate_correctly(a, pos, 'a');
			pb(a, b);
		}
		i += chunk_size;
	}
	move_back_to_a(a, b);
}

// void	chunk_sort(t_stack *a, t_stack *b, int i)
// {
// 	int		chunk_size;
// 	int		total_size;
// 	t_node	*temp;
// 	int		pos;
// 	t_node	*max;

// 	chunk_size = 25;
// 	total_size = a->size;
// 	while (i < total_size)
// 	{
// 		temp = a->top;
// 		pos = 0;
// 		while (temp && !(temp->index >= i && temp->index < i + chunk_size))
// 		{
// 			temp = temp->next;
// 			pos++;
// 		}
// 		if (!temp)
// 		{
// 			i += chunk_size;
// 			continue ;
// 		}
// 		if (pos <= a->size / 2)
// 			while (pos-- > 0)
// 				ra(a, 1);
// 		else
// 			while (pos++ < a->size)
// 				rra(a, 1);
// 		pb(a, b);
// 	}
// 	while (b->size > 0)
// 	{
// 		max = find_max(b);
// 		pos = get_index(b, max);
// 		if (pos <= b->size / 2)
// 			while (pos-- > 0)
// 				rb(b, 1);
// 		else
// 			while (pos++ < b->size)
// 				rrb(b, 1);
// 		pa(a, b);
// 	}
// }
// #include <unistd.h>
// #include <stdlib.h>
// static void	sort_stack(t_stack **stack_a, t_stack **stack_b);
// void printstack(t_stack *stack, char name)
// {
// 	t_node *temp;
// 	printf("\t****start****\n");
// 	if(!stack)
// 	return;
// 	printf("      stack %c (size = %d):\n", name, stack->size);
// 	temp = stack->top;
// 	while (temp)
// 	{
// 	printf("   value:%-6d - index: %-3d\n",temp->value,temp->index);
// 	temp = temp->next;
// 	}
// 	printf("\t****finish****\n");
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
// 	// printstack(a, 'a');
// 	// printstack(b, 'b');
// 	if(is_sorted(a) == 1)
// 		printf("The stack is sorted already!");
// 	if (is_sorted(a))
// 		return (free_stack(a), free_stack(b), 0);
// 	sort_stack(&a, &b);
// 	printstack(a, 'a');
// 	printstack(b, 'b');
// 	free_stack(a);
// 	free_stack(b);
// 	free(a);
// 	free(b);
// 	// free_stack(b);
// 	return (0);
// }
// void	radix_sort(t_stack *a, t_stack *b)
// {
// 	int	max_bits;
// 	int	size;
// 	int	i;
// 	int	j;
// 	int	pushed;
// 	max_bits = 0;
// 	size = a->size;
// 	i = 0;
// 	while ((size - 1) >> max_bits)
// 		max_bits++;
// 	while (i < max_bits)
// 	{
// 		j = 0;
// 		pushed = 0;
// 		while (j < size)
// 		{
// 			if (((a->top->index >> i) & 1) == 0)
// 			{
// 				pb(a, b);
// 				pushed++;
// 			}
// 			else
// 				ra(a, 1);
// 			j++;
// 		}
// 		while (pushed--)
// 			pa(a, b);
// 		i++;
// 	}
// }
// void	chunk_sort(t_stack *a, t_stack *b, int i)
// {
// 	int		chunk_size;
// 	int		total_size;
// 	t_node	*temp;
// 	int		pos;
// 	t_node	*max;

// 	chunk_size = 25;
// 	total_size = a->size;
// 	while (i < total_size)
// 	{
// 		temp = a->top;
// 		pos = 0;
// 		while (temp && !(temp->index >= i && temp->index < i + chunk_size))
// 		{
// 			temp = temp->next;
// 			pos++;
// 		}
// 		if (!temp)
// 		{
// 			i += chunk_size;
// 			continue ;
// 		}
// 		if (pos <= a->size / 2)
// 			while (pos-- > 0)
// 				ra(a, 1);
// 		else
// 			while (pos++ < a->size)
// 				rra(a, 1);
// 		pb(a, b);
// 	}
// 	while (b->size > 0)
// 	{
// 		max = find_max(b);
// 		pos = get_index(b, max);
// 		if (pos <= b->size / 2)
// 			while (pos-- > 0)
// 				rb(b, 1);
// 		else
// 			while (pos++ < b->size)
// 				rrb(b, 1);
// 		pa(a, b);
// 	}
// }