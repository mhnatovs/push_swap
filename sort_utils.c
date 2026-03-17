/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:41:06 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/10/17 16:53:15 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*min(t_stack *stack)
{
	t_node	*curent;
	t_node	*min;

	if (!stack || !stack->top)
		return (NULL);
	curent = stack->top;
	min = curent;
	while (curent)
	{
		if (curent->value < min->value)
			min = curent;
		curent = curent->next;
	}
	return (min);
}
