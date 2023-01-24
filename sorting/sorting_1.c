/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:02:32 by victofer          #+#    #+#             */
/*   Updated: 2023/01/23 19:26:27 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

t_stack	sort_two_elements(t_stack stack)
{
	if (stack.a[0] > stack.a[1])
		stack = sa(stack);
	return (stack);
}

t_stack	sort_three_elements(t_stack stack)
{
	if (sort_three_aux(stack.a[0], stack.a[1], stack.a[2]) == 1)
		stack = rra(stack);
	if (sort_three_aux(stack.a[0], stack.a[1], stack.a[2]) == 2)
	{
		stack = sa(stack);
		stack = rra(stack);
	}
	if (sort_three_aux(stack.a[0], stack.a[1], stack.a[2]) == 3)
		stack = sa(stack);
	if (sort_three_aux(stack.a[0], stack.a[1], stack.a[2]) == 4)
	{
		stack = pb(stack);
		stack = sa(stack);
		stack = pa(stack);
	}
	if (sort_three_aux(stack.a[0], stack.a[1], stack.a[2]) == 5)
		stack = ra(stack);
	return (stack);
}

t_stack	sort_four_elements(t_stack stack)
{
	int	b;

	stack = pb(stack);
	stack = sort_three_elements(stack);
	test_print_stacks(stack);
	b = stack.b[0];
	if (b < stack.a[0])
		stack = pa(stack);
	if (b > stack.a[2])
	{
		stack = pa(stack);
		stack = ra(stack);
	}
	if (b > stack.a[0] && b < stack.a[1])
	{
		stack = ra(stack);
		stack = pa(stack);
		stack = rra(stack);
	}
	if (b > stack.a[1] && b < stack.a[2])
		stack = rra_pa_ra_ra(stack);
	return (stack);
}

t_stack	sort_five_elements(t_stack stack)
{
	int	i;

	i = -1;
	stack = pb(stack);
	stack = pb(stack);
	stack = sort_three_elements(stack);
	while (++i < 2)
	{
		if (sort_five_aux(stack.b[0], stack) == 1)
		{
			stack = pa(stack);
			stack = ra(stack);
		}
		else if (sort_five_aux(stack.b[0], stack) == 2)
			stack = ra_pa_rra(stack);
		else if (sort_five_aux(stack.b[0], stack) == 3)
			stack = rra_pa_ra_ra(stack);
		else if (sort_five_aux(stack.b[0], stack) == 4)
			stack = rra_pa_ra(stack);
		else if (sort_five_aux(stack.b[0], stack) == 5)
			stack = pa(stack);
	}
	return (stack);
}
