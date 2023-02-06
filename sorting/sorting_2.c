/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:52:10 by victofer          #+#    #+#             */
/*   Updated: 2023/02/06 13:36:07 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

// Calculates the easier way to bring min element to the top
t_stack	smart_rotate(int min, t_stack stack)
{
	int	moves;
	int	j;

	if (min > stack.a_len / 2)
	{
		moves = stack.a_len - min;
		j = -1;
		while (++j < moves)
			stack = rra(stack);
	}
	else
	{
		moves = min;
		j = -1;
		while (++j < moves)
			stack = ra(stack);
	}
	return (stack);
}

// Sorts elements between 5 and 100 (both not included)
t_stack	medium_sort(t_stack stack)
{
	int	i;
	int	limit;
	int	min;

	limit = stack.a_len - 5;
	i = 0;
	while (i < limit)
	{
		min = get_min_pos(stack);
		stack = smart_rotate(min, stack);
		stack = pb(stack);
		i++;
	}
	stack = sort_five_elements(stack);
	i = 0;
	while (i < limit)
	{
		stack = pa(stack);
		i++;
	}
	return (stack);
}

// Sorts 100 elements (NOT WORKING YET)
t_stack	sort_100_elements(t_stack stack)
{
	ft_printf("NO");
	return (stack);
}
