/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:35:42 by victofer          #+#    #+#             */
/*   Updated: 2023/03/10 11:24:40 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

/*
*	Calls to sort_two_elements or sort_trhee_elements
	depending on stack a length.
*	@param stack
*/
void	minisort(t_stack *stack)
{
	if (stack->a_len == 2)
		sort_two_elements(stack);
	if (stack->a_len == 3)
		sort_three_elements(stack);
}

/*
*	Evaluates if stack is sorted.
	Calls minisort or big sort depending on stack a length.
*	@param stack
*/
void	start_sorting(t_stack *stack)
{
	if (is_sorted(stack->a, stack->a_len) && stack->b_len == 0)
		return ;
	if (stack->a_len <= 3)
		minisort(stack);
	else
		big_sort(stack);
}
