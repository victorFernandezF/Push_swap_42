/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_moves_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:04:29 by victofer          #+#    #+#             */
/*   Updated: 2023/01/20 11:27:57 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	add_one_to_last_and_move_rest_b(t_stack stack, int n)
{
	int	*new;
	int	i;
	int	j;

	j = 0;
	new = ft_calloc(stack.b_len + 1, sizeof(int));
	i = 0;
	stack.b_len += 1;
	while (i < stack.b_len)
		new[i++] = stack.b[j++];
	new[i - 1] = n;
	free(stack.b);
	stack.b = new;
	return (stack);
}

t_stack	rr(t_stack stack)
{
	stack = ra(stack);
	stack = rb(stack);
	ft_printf("ss\n");
	return (stack);
}
