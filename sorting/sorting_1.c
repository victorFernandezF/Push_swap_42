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

/*
* Evaluates the number of elements and
* call the functions for each case.
*/
void	start_sorting(t_stack *stack)
{

	if (stack->a_len == 2)
		sort_two_elements(stack);
	if (stack->a_len == 3)
		sort_three_elements(stack);
	if (stack->a_len == 4)
		sort_four_elements(stack);
	if (stack->a_len == 5)
		sort_five_elements(stack);
	if (stack->a_len > 5 && stack->a_len < 100)
		medium_sort(stack);
	if (stack->a_len == 100)
		sort_100_elements(stack, 0);
		//stack = sort_100_elements(stack, 0);
	if (stack->a_len == 500)
	{
		//stack = sort_500_elements(&stack);
		//test("NO QUIERO");
		//exit(-1);
	}
		//stack = sort_500_elements(stack);
}

// Sorts two elements.
void	sort_two_elements(t_stack *stack)
{
	if (stack->a[0] > stack->a[1])
		do_operation("sa", stack);
}

// Sorts three elements
void	sort_three_elements(t_stack *stack)
{
	if (sort_three_aux(stack->a[0], stack->a[1], stack->a[2]) == 1)
		rra(stack);
	if (sort_three_aux(stack->a[0], stack->a[1], stack->a[2]) == 2)
		pack_of_instructions("sa_rra", stack);
	if (sort_three_aux(stack->a[0], stack->a[1], stack->a[2]) == 3)
		sa(stack);
	if (sort_three_aux(stack->a[0], stack->a[1], stack->a[2]) == 4)
		pack_of_instructions("ra_sa_rra", stack);
	if (sort_three_aux(stack->a[0], stack->a[1], stack->a[2]) == 5)
		ra(stack);
}

// Sorts four elements
void	sort_four_elements(t_stack *stack)
{
	int	min;

	min = get_min_pos(*stack);
	if (min == 3)
		pack_of_instructions("rra_pb", stack);
	else if (min == 2)
		pack_of_instructions("rra_rra_pb", stack);
	else if (min == 1)
		pack_of_instructions("ra_pb", stack);
	else if (min == 0)
		pack_of_instructions("pb", stack);
	sort_three_elements(stack);
	pa(stack);
}

// Sorts five elements
void	sort_five_elements(t_stack *stack)
{
	int	min;

	min = get_min_pos(*stack);
	if (min == 4)
		pack_of_instructions("rra_pb", stack);
	if (min == 3)
		pack_of_instructions("rra_rra_pb", stack);
	else if (min == 2)
		pack_of_instructions("ra_ra_pb", stack);
	else if (min == 1)
		pack_of_instructions("ra_pb", stack);
	else if (min == 0)
		pack_of_instructions("pb", stack);
	sort_four_elements(stack);
	pa(stack);
}
