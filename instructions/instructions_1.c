/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:44:23 by victofer          #+#    #+#             */
/*   Updated: 2023/01/18 19:40:28 by victofer         ###   ########.fr       */
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

t_stack	del_first_and_move_rest(t_stack stack, char st)
{
	int	*new;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (st == 'a')
	{
		new = (int *)malloc((stack.a_len - 1) * sizeof(int));
		if (!new)
			ft_error_free(stack.stack_a);
		while (++i <= stack.a_len)
			new[j++] = stack.stack_a[i];
		stack.a_len -= 1;
	}
	return (stack);
}

t_stack	pb(t_stack stack)
{
	stack.stack_b = (int *)realloc(stack.stack_b,
			(stack.b_len + 1) * sizeof(int));
	if (!stack.stack_b)
		ft_error_free(stack.stack_a);
	stack.stack_b[0] = stack.stack_a[0];
	del_first_and_move_rest(stack, 'a');
	ft_printf("ss\n");
	return (stack);
}
