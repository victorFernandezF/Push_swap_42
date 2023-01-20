/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:12:46 by victofer          #+#    #+#             */
/*   Updated: 2023/01/20 12:13:52 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

t_stack	rr(t_stack stack)
{
	stack = ra(stack);
	stack = rb(stack);
	ft_printf("ss\n");
	return (stack);
}