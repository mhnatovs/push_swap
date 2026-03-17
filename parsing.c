/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:07:04 by mhnatovs          #+#    #+#             */
/*   Updated: 2025/10/18 13:31:34 by mhnatovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	inner_loop(t_stack *a, char *arg);

static int	has_duplicates(t_stack *a, int value)
{
	t_node	*tmp;

	tmp = a->top;
	while (tmp)
	{
		if (tmp->value == value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int	ft_isnumber(const char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	parse_args(t_stack *a, char **av)
{
	char	**split;
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		split = ft_split(av[i], ' ');
		if (!split || !split[0])
			return (free_split(split), 0);
		j = 0;
		while (split[j])
		{
			if (!inner_loop(a, split[j]))
			{
				free_split(split);
				return (0);
			}
			j++;
		}
		free_split(split);
		i++;
	}
	return (1);
}

static int	inner_loop(t_stack *a, char *arg)
{
	long	value;

	if (!ft_isnumber(arg))
		return (0);
	value = ft_atol(arg);
	if (value < INT_MIN || value > INT_MAX
		|| has_duplicates(a, (int)value))
		return (0);
	add_node_bottom(a, (int)value);
	return (1);
}

// #include <stdio.h>

// void	push_back(t_stack *stack, int value)
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
// 		new->prev = stack->bottom;
// 		stack->bottom->next = new;
// 		stack->bottom = new;
// 	}
// 	stack->size++;
// }
// int main(int ac, char **av)
// {
//char **split;
//int i;
//if (ac < 2)
//	return (0);
//split = ft_split(av[1], ' ');
//if (!split)
//	return (1);
//i = 0;
//while (split[i])
//{
//	printf("[%s]\n", split[i]);
//	i++;
//}
//i = 0;
//while (split[i])
//    free(split[i++]);
//free(split);
//return (0);
// }
// static int	is_valid_int(char **av)
// {
// 	int		i;
// 	int		j;
// 	long	num;
// 	i = 1;
// 	while (av[i])
// 	{
// 		j = 0;
// 		if (av[i][j] == '+' || av[i][j] == '-')
// 			j++;
// 		if (!av[i][j])
// 			return (1);
// 		while (av[i][j])
// 		{
// 			if (!ft_isdigit((unsigned char)av[i][j]))
// 				return (1);
// 			j++;
// 		}
// 		num = ft_atol(av[i]);
// 		if (num < INT_MIN || num > INT_MAX)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }
// typedef struct    s_list
// {
// 	int          *data;
//     struct s_list *next;
// }                 t_list;
// int main()
// {
// 	t_list node4 = {4, NULL};
// 	t_list node3 = {3, &node4};
// 	t_list node2 = {2, &node3};
// 	t_list node1 = {1, &node2};
// }