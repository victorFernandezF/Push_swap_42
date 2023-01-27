/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:52:10 by victofer          #+#    #+#             */
/*   Updated: 2023/01/27 11:18:51 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	get_max_position(t_stack stack)
{
	int	i;
	int	max_stack;

	i = -1;
	max_stack = max(stack.a, stack.a_len);
	printf("max_val %i",max_stack);
	while (++i < stack.a_len)
		if (stack.a[i] == max_stack)
			return (i);
	return (0);
}

t_stack	complex_sort(t_stack stack)
{
	int	max;
	int	i;
	int	j;

	while (stack.a_len)
	{
		max = get_max_position(stack);
		i = stack.a_len - max;
		j = -1;
		printf("\n max %i\n", max);
		/* if (max == stack.a_len - 1)
			stack = rra(stack); */
		if (max == 0)
			stack = do_operation(PB, stack);
		else if (max <= stack.a_len / 2)
			while (++j < max)
				stack = ra(stack);
		else if (max > stack.a_len / 2)
			while (++j < max)
				stack = rra(stack);
		test_print_stacks(stack);
	}
	return (stack);
}
