/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:12:46 by victofer          #+#    #+#             */
/*   Updated: 2023/01/20 13:35:07 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

/*
** Move the top element from 'a' and put it
** at last position of a (2 1 4 -> 1 4 2)
*/
t_stack	ra(t_stack stack)
{
	int	aux;

	if (!stack.a)
		return (stack);
	aux = stack.a[0];
	stack = del_first_and_move_rest_a(stack);
	stack = add_one_to_last_and_move_rest_a(stack, aux);
	ft_printf("ra\n");
	return (stack);
}

/*
** Move the top element from 'b' and put it
** at last position of a (2 1 4 -> 1 4 2)
*/
t_stack	rb(t_stack stack)
{
	int	aux;

	if (!stack.b)
		return (stack);
	aux = stack.b[0];
	stack = del_first_and_move_rest_b(stack);
	stack = add_one_to_last_and_move_rest_b(stack, aux);
	ft_printf("rb\n");
	return (stack);
}

// ra + rb
t_stack	rr(t_stack stack)
{
	stack = ra(stack);
	stack = rb(stack);
	ft_printf("ss\n");
	return (stack);
}
