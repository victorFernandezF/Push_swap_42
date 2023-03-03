/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:52:10 by victofer          #+#    #+#             */
/*   Updated: 2023/03/03 14:09:03 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

// Calculates the easier way to bring min element to the top
void	smart_rotate(int min, t_stack *stack)
{
	int	moves;
	int	j;

	if (min > stack->a_len / 2)
	{
		moves = stack->a_len - min;
		j = -1;
		while (++j < moves)
			rra(stack);
	}
	else
	{
		moves = min;
		j = -1;
		while (++j < moves)
			ra(stack);
	}
}

// Sorts elements between 5 and 100 (both not included)
void	medium_sort(t_stack *stack)
{
	int	i;
	int	limit;
	int	min;

	limit = stack->a_len - 5;
	i = 0;
	while (i < limit)
	{
		min = get_min_pos(*stack);
		smart_rotate(min, stack);
		pb(stack);
		i++;
	}
	sort_five_elements(stack);
	i = 0;
	while (i < limit)
	{
		pa(stack);
		i++;
	}
}
