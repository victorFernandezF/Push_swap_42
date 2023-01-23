/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordering_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:32:01 by victofer          #+#    #+#             */
/*   Updated: 2023/01/23 19:07:50 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	order_five_aux(int n, t_stack stack)
{
	if (n > stack.a[stack.a_len - 1])
		return (1);
	if (n > stack.a[0] && n < stack.a[1])
		return (2);
	if (n > stack.a[0] && n < stack.a[stack.a_len - 1])
		return (3);
	if (n > stack.a[stack.a_len - 2] && n < stack.a[stack.a_len - 1])
		return (4);
	if (n < stack.a[0])
		return (5);
	return (0);
}

t_stack	rra_pa_ra_ra(t_stack stack)
{
	stack = rra(stack);
	stack = pa(stack);
	stack = ra(stack);
	stack = ra(stack);
	return (stack);
}

t_stack	rra_pa_ra(t_stack stack)
{
	stack = rra(stack);
	stack = pa(stack);
	stack = ra(stack);
	return (stack);
}

t_stack	ra_pa_rra(t_stack stack)
{
	stack = ra(stack);
	stack = pa(stack);
	stack = rra(stack);
	return (stack);
}