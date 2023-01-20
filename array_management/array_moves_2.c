/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_moves_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:04:29 by victofer          #+#    #+#             */
/*   Updated: 2023/01/20 12:12:24 by victofer         ###   ########.fr       */
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

t_stack	del_last_and_move_rest_a(t_stack stack)
{
	int	*new;
	int	i;
	int	j;

	i = -1;
	j = 0;
	new = (int *)malloc((stack.a_len - 1) * sizeof(int));
	if (!new)
		ft_error_free(stack.a);
	stack.a_len -= 1;
	while (++i <= stack.a_len)
		new[j++] = stack.a[i];
	free(stack.a);
	stack.a = new;
	return (stack);
}

t_stack	del_last_and_move_rest_b(t_stack stack)
{
	int	*new;
	int	i;
	int	j;

	i = -1;
	j = 0;
	new = (int *)malloc((stack.b_len - 1) * sizeof(int));
	if (!new)
		ft_error_free(stack.b);
	stack.b_len -= 1;
	while (++i <= stack.b_len)
		new[j++] = stack.b[i];
	free(stack.b);
	stack.b = new;
	return (stack);
}
