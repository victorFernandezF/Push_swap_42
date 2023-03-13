/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:32:01 by victofer          #+#    #+#             */
/*   Updated: 2023/01/23 19:17:04 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

// Auxiliar function with the conditions to sort 3
int	sort_three_aux(int a, int b, int c)
{
	if ((a < b) && (b > c) && (c < a))
		return (1);
	if ((a > b) && (b > c) && (c < a))
		return (2);
	if ((a > b) && (b < c) && (c > a))
		return (3);
	if ((a < b) && (b > c) && (c > a))
		return (4);
	if ((a > b) && (b < c) && (c < a))
		return (5);
	return (FALSE);
}

// Returns the array postition of the min number of the array.
int	get_min_pos(t_stack stack)
{
	int	i;
	int	min_stack;

	min_stack = min(stack.a, stack.a_len - 1);
	i = -1;
	while (++i < stack.a_len)
		if (stack.a[i] == min_stack)
			return (i);
	return (0);
}

// Returns the array postition of the min number of the array.
int	get_min_pos_temp(t_stack stack)
{
	int	i;
	int	min_stack;

	min_stack = min(stack.temp, stack.aux_len - 1);
	i = -1;
	while (++i < stack.aux_len)
		if (stack.temp[i] == min_stack)
			return (i);
	return (0);
}

int	get_next_min_pos_temp(t_stack stack, int j)
{
	int	i;
	int	min_stack;

	min_stack = min(stack.temp, stack.aux_len - 1);
	i = -1;
	while (++i < stack.aux_len)
		if (stack.temp[i] == min_stack && stack.temp[i] != j)
			return (i);
	return (0);
}

// Returns the array postition of the max number of the array.
int	get_max_pos(t_stack stack)
{
	int	i;
	int	max_stack;

	i = -1;
	max_stack = max(stack.a, stack.a_len);
	while (++i < stack.a_len)
		if (stack.a[i] == max_stack)
			return (i);
	return (0);
}

