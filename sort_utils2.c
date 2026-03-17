/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:10:53 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/10/18 14:12:13 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min_to_b(t_stack *a, t_stack *b)
{
	t_node	*min_node;
	int		index;

	min_node = min(a);
	index = get_index(a, min_node);
	if (index <= a->size / 2)
		while (index-- > 0)
			ra(a, 1);
	else
		while (index++ < a->size)
			rra(a, 1);
	pb(a, b);
}
