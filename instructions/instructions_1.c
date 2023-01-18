/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:44:23 by victofer          #+#    #+#             */
/*   Updated: 2023/01/18 13:32:21 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	sa(t_stack stack)
{
	int	aux;

	aux = stack.stack_a[0];
	stack.stack_a[0] = stack.stack_a[1];
	stack.stack_a[1] = aux;
	ft_printf("sa\n");
	return (stack);
}

t_stack	sb(t_stack stack)
{
	int	aux;

	aux = stack.stack_b[0];
	stack.stack_b[0] = stack.stack_b[1];
	stack.stack_b[1] = aux;
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
