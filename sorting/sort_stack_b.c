/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:35:11 by victofer          #+#    #+#             */
/*   Updated: 2023/03/01 14:19:25 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

// Returns the array postition of the min number of the array.
int	get_min_pos_stack_b(t_stack stack)
{
	int	i;
	int	min_stack;

	min_stack = min(stack.b, stack.b_len - 1);
	i = -1;
	while (++i < stack.b_len)
		if (stack.b[i] == min_stack)
			return (i);
	return (0);
}

// Returns the position of the max number of the stack.a
int	get_max_pos_stack_b(t_stack stack)
{
	int	i;
	int	max_stack;

	max_stack = max(stack.b, stack.b_len - 1);
	i = -1;
	while (++i < stack.b_len)
		if (stack.b[i] == max_stack)
			return (i);
	return (0);
}

/*
	Calculate the cheapest way to brint a number(min) to the
	top of stack b and makes the moves. Stack b is now ready to pa.
*/
t_stack	smart_rotate_b(int min, t_stack stack)
{
	int	moves;
	int	j;

	if (min > stack.b_len / 2)
	{
		moves = stack.b_len - min;
		j = -1;
		while (++j < moves)
			stack = rrb(stack);
	}
	else
	{
		moves = min;
		j = -1;
		while (++j < moves)
			stack = rb(stack);
	}
	return (stack);
}

// It makes what it says in the name. Sort stack b.
t_stack	sort_stack_b(t_stack stack, int limit)
{
	int	min_pos;
	int	i;

	i = -1;
	while (++i < limit)
	{
		min_pos = get_max_pos_stack_b(stack);
		stack = smart_rotate_b(min_pos, stack);
		stack = pa(stack);
	}
	i = -1;
	while (++i < limit)
		stack = pb(stack);
	return (stack);
}
