/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:26:45 by victofer          #+#    #+#             */
/*   Updated: 2023/02/06 19:32:54 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

t_stack	chunck(t_stack stack, int i, int len)
{
	int	first;
	int	last;

	while (i++ < len)
	{
		first = get_first(stack);
		last = get_last(stack);
		test_print_stacks(stack);
		stack = calculate_move(stack, first, last);
		stack = pb(stack);
		test_print_stacks(stack);
	}
	return (stack);
}
