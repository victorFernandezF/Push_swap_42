/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:26:45 by victofer          #+#    #+#             */
/*   Updated: 2023/02/21 12:10:48 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

t_stack	calculate_move(t_stack stack, int first, int last)
{
	int	mid;
	int	i;

	mid = stack.aux_len / 2;
	i = -1;
	if (first == 0)
	{
		return (stack);
	}
	if (last == stack.aux_len)
	{
		stack = rra(stack);
		stack = rra_temp(stack);
		return (stack);
	}
	if (first < stack.aux_len - last)
		while (++i < first)
		{
			stack = ra(stack);
			stack = ra_temp(stack);
		}
	else
		while (++i < stack.aux_len - last)
		{
			stack = rra(stack);
			stack = rra_temp(stack);
		}
	return (stack);
}

t_stack	chunck(t_stack stack, int i, int len)
{
	int	first;
	int	last;
	int	ini;

	ini = i;
	i = 0;
	while (stack.chunk_len != 0)
	//while (i < 2)
	{
		first = get_first(stack, ini, len);
		last = get_last(stack, ini, len);
		printf("\n%i %i\n", stack.a[first], stack.a[last]);
		stack = calculate_move(stack, first, last);
		stack = pb(stack);
		stack = pb_temp(stack);
		stack.chunk_len -= 1;
		i++;
	}
	return (stack);
}
