/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:44:23 by victofer          #+#    #+#             */
/*   Updated: 2023/01/20 11:42:17 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// swap two top element of the stack a
t_stack	sa(t_stack stack)
{
	int	aux;

	aux = stack.a[0];
	stack.a[0] = stack.a[1];
	stack.a[1] = aux;
	ft_printf("sa\n");
	return (stack);
}

// swap two top element of the stack b
t_stack	sb(t_stack stack)
{
	int	aux;

	aux = stack.b[0];
	stack.b[0] = stack.b[1];
	stack.b[1] = aux;
	ft_printf("sb\n");
	return (stack);
}

// sa + sb 
t_stack	ss(t_stack stack)
{
	stack = sa(stack);
	stack = sb(stack);
	ft_printf("ss\n");
	return (stack);
}

/*
** Get the top element from a and put t on
** top position of b
*/
t_stack	pb(t_stack stack)
{
	int	aux;

	if (!stack.a)
		return (stack);
	aux = stack.a[0];
	stack = add_one_to_first_and_move_rest_b(stack, aux);
	stack = del_first_and_move_rest_a(stack);
	ft_printf("pb\n");
	return (stack);
}

/*
** Get the top element from b and put t on
** top position of a
*/
t_stack	pa(t_stack stack)
{
	int	aux;

	if (!stack.b)
		return (stack);
	aux = stack.b[0];
	stack = add_one_to_first_and_move_rest_a(stack, aux);
	stack = del_first_and_move_rest_b(stack);
	ft_printf("pa\n");
	return (stack);
}
