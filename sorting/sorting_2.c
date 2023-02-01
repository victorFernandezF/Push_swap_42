/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:52:10 by victofer          #+#    #+#             */
/*   Updated: 2023/02/01 12:27:09 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

t_stack	medium_sort(t_stack stack)
{
	int	i;
	int	j;
	int	limit;
	int	moves;
	int	min;

	limit = stack.a_len - 5;
	printf("\n TEST limit -> %i\n", limit);
	i = 0;
	while (i < limit)
	{
		printf("\n REPEAT %i\n", i);
		min = get_min_pos(stack);
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
		stack = pb(stack);
		i++;
	}
	stack = sort_five_elements(stack);
	i = -1;
	while (++i < limit)
		stack = pa(stack);
	return (stack);
}