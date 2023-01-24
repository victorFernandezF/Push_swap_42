/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:52:10 by victofer          #+#    #+#             */
/*   Updated: 2023/01/24 12:53:21 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	get_max_position(t_stack stack)
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

t_stack	complex_sort(t_stack stack)
{
	int	max;
	int	i;

	i = -1;
	stack = do_operation(PB, stack);
	stack = do_operation(PB, stack);
	if (stack.b[0] < stack.b[1])
		stack = do_operation (SB, stack);
	while (++i < stack.a_len - 1)
	{
		//test_print_stacks(stack);
		max = get_max_position(stack);
		//printf("i = %i max_pos %i < %i\n", i, max, stack.a_len / 2);
		if (max == 0)
			stack = do_operation(PB, stack);
		else if (max < stack.a_len / 2)
		{
			while (max--)
			{
				stack = do_operation(RA, stack);
				stack = do_operation(PB, stack);
			}
		}
		else if (max >= stack.a_len / 2)
			while (max--)
				stack = do_operation(RRA, stack);
		
	}
	//printf("max_pos: %i\n", get_max_position(stack));
	return (stack);
}
