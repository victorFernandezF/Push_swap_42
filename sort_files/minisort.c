/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:39:47 by victofer          #+#    #+#             */
/*   Updated: 2023/03/10 11:26:24 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

static int	sort_3_aux(int a, int b, int c)
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
	return (0);
}

/*
*	Sort stack a as long as its size is 3 elements
*	@param stack
*/
void	sort_three_elements(t_stack *stack)
{
	if (sort_3_aux(stack->a[0], stack->a[1], stack->a[2]) == 1)
		rra(stack);
	if (sort_3_aux(stack->a[0], stack->a[1], stack->a[2]) == 2)
	{
		sa(stack);
		rra(stack);
	}
	if (sort_3_aux(stack->a[0], stack->a[1], stack->a[2]) == 3)
		sa(stack);
	if (sort_3_aux(stack->a[0], stack->a[1], stack->a[2]) == 4)
	{
		ra(stack);
		sa(stack);
		rra(stack);
	}
	if (sort_3_aux(stack->a[0], stack->a[1], stack->a[2]) == 5)
		ra(stack);
}

/*
*	Sort stack a as long as its size is 2 elements
*	@param stack
*/
void	sort_two_elements(t_stack *stack)
{
	if (stack->a[0] > stack->a[1])
		sa(stack);
}
