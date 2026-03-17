/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:52:50 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/10/17 12:55:45 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*curent;

	if (!a || !a->top)
		return (1);
	curent = a->top;
	while (curent && curent->next)
	{
		if (curent->value > curent->next->value)
			return (0);
		curent = curent->next;
	}
	return (1);
}
