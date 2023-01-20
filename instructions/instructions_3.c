/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:12:54 by victofer          #+#    #+#             */
/*   Updated: 2023/01/20 13:35:11 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

/*
** Move the last element from 'a' and put it
** at firts position of a (2 1 4 ->  4 1 2)
*/
t_stack	rra(t_stack stack)
{
	int	aux;

	if (!stack.a)
		return (stack);
	aux = stack.a[stack.a_len - 1];
	stack = del_last_and_move_rest_a(stack);
	stack = add_one_to_first_and_move_rest_a(stack, aux);
	ft_printf("rra\n");
	return (stack);
}

/*
** Move the last element from 'b' and put it
** at firts position of b (2 1 4 ->  4 1 2)
*/
t_stack	rrb(t_stack stack)
{
	int	aux;

	if (!stack.b)
		return (stack);
	aux = stack.b[stack.b_len - 1];
	stack = del_last_and_move_rest_b(stack);
	stack = add_one_to_first_and_move_rest_b(stack, aux);
	ft_printf("rrb\n");
	return (stack);
}

// rra + rrb
t_stack	rrr(t_stack stack)
{
	stack = rra(stack);
	stack = rrb(stack);
	ft_printf("rrr\n");
	return (stack);
}
