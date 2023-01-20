/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordering_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:02:32 by victofer          #+#    #+#             */
/*   Updated: 2023/01/20 13:48:56 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

t_stack	order_two_elements(t_stack stack)
{
	stack = sa(stack);
	return (stack);
}

t_stack	order_three_elements(t_stack stack)
{
	if (stack.a[0] < stack.a[1] && stack.a[1] > stack.a[2])
	{
		stack = pb(stack);
		stack = sa(stack);
		stack = pa(stack);
		return (stack);
	}
	if (stack.a[0] > stack.a[1] && stack.a[1] < stack.a[2])
	{
		stack = rb(stack);
		return (stack);
	}
	return (stack);
}
