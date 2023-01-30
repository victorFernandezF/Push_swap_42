/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:44:23 by victofer          #+#    #+#             */
/*   Updated: 2023/01/30 10:49:06 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

/*
** Swap the two top elements from  
** stack 'a' (2 1 4 -> 1 2 4)
*/
t_stack	sa(t_stack stack)
{
	int	aux;

	aux = stack.a[0];
	stack.a[0] = stack.a[1];
	stack.a[1] = aux;
	stack.moves += 1;
	ft_printf("sa\n");
	return (stack);
}

/*
** Swap the two top elements from  
** stack 'b' (2 1 4 -> 1 2 4)
*/
t_stack	sb(t_stack stack)
{
	int	aux;

	aux = stack.b[0];
	stack.b[0] = stack.b[1];
	stack.b[1] = aux;
	stack.moves += 1;
	ft_printf("sb\n");
	return (stack);
}

// sa + sb 
t_stack	ss(t_stack stack)
{
	stack = sa(stack);
	stack = sb(stack);
	stack.moves += 1;
	ft_printf("ss\n");
	return (stack);
}

/*
** Get the top element from 'a' and put it
** at the top of 'b' (A -> 2 1 4 | B -> 5) -> (A - 1 4 | B - 2 5)
*/
t_stack	pb(t_stack stack)
{
	int	aux;

	if (!stack.a)
		return (stack);
	aux = stack.a[0];
	stack = add_one_to_first_and_move_rest_b(stack, aux);
	stack = del_first_and_move_rest_a(stack);
	stack.moves += 1;
	ft_printf("pb\n");
	return (stack);
}

/*
** Get the top element from 'b' and put it
** at the top of 'a' (A -> 2 1 4 | B -> 5) -> (A - 5 2 1 4 | B -)
*/
t_stack	pa(t_stack stack)
{
	int	aux;

	if (!stack.b)
		return (stack);
	aux = stack.b[0];
	stack = add_one_to_first_and_move_rest_a(stack, aux);
	stack = del_first_and_move_rest_b(stack);
	stack.moves += 1;
	ft_printf("pa\n");
	return (stack);
}
