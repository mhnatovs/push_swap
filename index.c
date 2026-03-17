/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:42:45 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/10/16 19:43:40 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_stack *stack, t_node *node)
{
	t_node	*current;
	int		i;

	if (!stack || !node)
		return (-1);
	current = stack->top;
	i = 0;
	while (current)
	{
		if (current == node)
			return (i);
		current = current->next;
		i++;
	}
	return (-1);
}

void	set_index(t_stack *a)
{
	t_node	*i;
	t_node	*j;
	int		index;

	i = a->top;
	while (i)
	{
		index = 0;
		j = a->top;
		while (j)
		{
			if (j->value < i->value)
				index++;
			j = j->next;
		}
		i->index = index;
		i = i->next;
	}
}
