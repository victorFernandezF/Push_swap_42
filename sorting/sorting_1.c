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

// Function that evaluate how to aproach the sorting.
t_stack	start_sorting(t_stack stack)
{
	if (stack.a_len == 2)
		stack = sort_two_elements(stack);
	if (stack.a_len == 3)
		stack = sort_three_elements(stack);
	if (stack.a_len == 4)
		stack = sort_four_elements(stack);
	if (stack.a_len == 5)
		stack = sort_five_elements(stack);
	if (stack.a_len > 5 && stack.a_len <= 100)
		stack = medium_sort(stack);
	return (stack);
}

t_stack	sort_two_elements(t_stack stack)
{
	if (stack.a[0] > stack.a[1])
		stack = do_operation("sa", stack);
	return (stack);
}

t_stack	sort_three_elements(t_stack stack)
{
	if (sort_three_aux(stack.a[0], stack.a[1], stack.a[2]) == 1)
		stack = rra(stack);
	if (sort_three_aux(stack.a[0], stack.a[1], stack.a[2]) == 2)
		stack = pack_of_instructions("sa_rra", stack);
	if (sort_three_aux(stack.a[0], stack.a[1], stack.a[2]) == 3)
		stack = sa(stack);
	if (sort_three_aux(stack.a[0], stack.a[1], stack.a[2]) == 4)
		stack = pack_of_instructions("ra_sa_rra", stack);
	if (sort_three_aux(stack.a[0], stack.a[1], stack.a[2]) == 5)
		stack = ra(stack);
	return (stack);
}

t_stack	sort_four_elements(t_stack stack)
{
	int	min;

	min = get_min_pos(stack);
	if (min == 3)
		stack = pack_of_instructions("rra_pb", stack);
	else if (min == 2)
		stack = pack_of_instructions("rra_rra_pb", stack);
	else if (min == 1)
		stack = pack_of_instructions("ra_pb", stack);
	else if (min == 0)
		stack = pack_of_instructions("pb", stack);
	stack = sort_three_elements(stack);
	stack = pa(stack);
	return (stack);
}

t_stack	sort_five_elements(t_stack stack)
{
	int	min;

	min = get_min_pos(stack);
	if (min == 4)
		stack = pack_of_instructions("rra_pb", stack);
	if (min == 3)
		stack = pack_of_instructions("rra_rra_pb", stack);
	else if (min == 2)
		stack = pack_of_instructions("ra_ra_pb", stack);
	else if (min == 1)
		stack = pack_of_instructions("ra_pb", stack);
	else if (min == 0)
		stack = pack_of_instructions("pb", stack);
	stack = sort_four_elements(stack);
	stack = pa(stack);
	return (stack);
}
