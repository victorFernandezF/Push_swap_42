/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:44:23 by victofer          #+#    #+#             */
/*   Updated: 2023/01/19 12:00:27 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	sa(t_stack stack)
{
	int	aux;

	aux = stack.a[0];
	stack.a[0] = stack.a[1];
	stack.a[1] = aux;
	ft_printf("sa\n");
	return (stack);
}

t_stack	sb(t_stack stack)
{
	int	aux;

	aux = stack.b[0];
	stack.b[0] = stack.b[1];
	stack.b[1] = aux;
	ft_printf("sb\n");
	return (stack);
}

t_stack	ss(t_stack stack)
{
	stack = sa(stack);
	stack = sb(stack);
	ft_printf("ss\n");
	return (stack);
}

t_stack	pb(t_stack stack)
{
	int	aux;

	stack.b = ft_calloc(stack.b_len + 1, sizeof(int));
	if (!stack.b)
		ft_error_free(stack.a);
	aux = stack.a[0];
	stack = del_first_and_move_rest_a(stack);
	stack = add_one_to_first_and_move_rest_b(stack, aux);

	return (stack);
}
