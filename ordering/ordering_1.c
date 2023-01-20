/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordering_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:02:32 by victofer          #+#    #+#             */
/*   Updated: 2023/01/20 19:15:09 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

t_stack	order_two_elements(t_stack stack)
{
	stack = sa(stack);
	return (stack);
}

static int	order_three_aux(int a, int b, int c)
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
