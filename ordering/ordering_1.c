/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordering_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:02:32 by victofer          #+#    #+#             */
/*   Updated: 2023/01/23 19:08:10 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

t_stack	order_two_elements(t_stack stack)
{
	if (stack.a[0] > stack.a[1])
		stack = sa(stack);
	return (stack);
}

int	order_three_aux(int a, int b, int c)
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

t_stack	order_three_elements(t_stack stack)
{
	if (order_three_aux(stack.a[0], stack.a[1], stack.a[2]) == 1)
		stack = rra(stack);
	if (order_three_aux(stack.a[0], stack.a[1], stack.a[2]) == 2)
	{
		stack = sa(stack);
		stack = rra(stack);
	}
	if (order_three_aux(stack.a[0], stack.a[1], stack.a[2]) == 3)
		stack = sa(stack);
	if (order_three_aux(stack.a[0], stack.a[1], stack.a[2]) == 4)
	{
		stack = pb(stack);
		stack = sa(stack);
		stack = pa(stack);
	}
	if (order_three_aux(stack.a[0], stack.a[1], stack.a[2]) == 5)
		stack = ra(stack);
	return (stack);
}

t_stack	order_five_elements(t_stack stack)
{
	int	i;

	i = -1;
	stack = pb(stack);
	stack = pb(stack);
	stack = order_three_elements(stack);
	while (++i < 2)
	{
		if (order_five_aux(stack.b[0], stack) == 1)
		{
			stack = pa(stack);
			stack = ra(stack);
		}
		else if (order_five_aux(stack.b[0], stack) == 2)
			stack = ra_pa_rra(stack);
		else if (order_five_aux(stack.b[0], stack) == 3)
			stack = rra_pa_ra_ra(stack);
		else if (order_five_aux(stack.b[0], stack) == 4)
			stack = rra_pa_ra(stack);
		else if (order_five_aux(stack.b[0], stack) == 5)
			stack = pa(stack);
	}
	return (stack);
}
