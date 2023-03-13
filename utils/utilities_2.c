/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:08:30 by victofer          #+#    #+#             */
/*   Updated: 2023/03/10 11:26:12 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

/*
*	Checks if the stack is already sorted.
*	@param *stack array of numbers
*	@param len lenght of array.
*/
int	is_sorted(int *stack, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (stack[i] < stack[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

/*
*	Find the min element os stack b and moves to a.
*	@param *stack
*/
void	place_smallest_first_a(t_stack *stack)
{
	int	min_index;

	min_index = find_min_position(stack->a, stack->a_len);
	if (min_index <= stack->a_len / 2)
		while (min_index--)
			ra(stack);
	else
	{
		while ((stack->a_len - min_index) > 0)
		{
			rra(stack);
			min_index++;
		}
	}
}
