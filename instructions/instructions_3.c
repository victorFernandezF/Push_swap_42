/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:12:54 by victofer          #+#    #+#             */
/*   Updated: 2023/01/24 12:25:05 by victofer         ###   ########.fr       */
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
	stack.moves += 1;
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
	stack.moves += 1;
	ft_printf("rrb\n");
	return (stack);
}

// rra + rrb
t_stack	rrr(t_stack stack)
{
	stack = rra(stack);
	stack = rrb(stack);
	stack.moves += 1;
	ft_printf("rrr\n");
	return (stack);
}

t_stack	do_operation(char *op, t_stack stack)
{
	if (ft_strncmp(op, "sa", 2) == 0)
		stack = sa(stack);
	if (ft_strncmp(op, "sb", 2) == 0)
		stack = sb(stack);
	if (ft_strncmp(op, "ss", 2) == 0)
		stack = ss(stack);
	if (ft_strncmp(op, "pa", 2) == 0)
		stack = pa(stack);
	if (ft_strncmp(op, "pb", 2) == 0)
		stack = pb(stack);
	if (ft_strncmp(op, "ra", 2) == 0)
		stack = ra(stack);
	if (ft_strncmp(op, "rb", 2) == 0)
		stack = rb(stack);
	if (ft_strncmp(op, "rr", 2) == 0)
		stack = rr(stack);
	if (ft_strncmp(op, "rra", 3) == 0)
		stack = rra(stack);
	if (ft_strncmp(op, "rrb", 3) == 0)
		stack = rrb(stack);
	if (ft_strncmp(op, "rrr", 3) == 0)
		stack = rrr(stack);
	return (stack);
}
