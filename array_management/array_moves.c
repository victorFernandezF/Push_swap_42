/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:04:29 by victofer          #+#    #+#             */
/*   Updated: 2023/01/19 19:25:09 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	del_first_and_move_rest_a(t_stack stack)
{
	int	*new;
	int	i;
	int	j;

	i = 0;
	j = 0;
	new = (int *)malloc((stack.a_len - 1) * sizeof(int));
	if (!new)
		ft_error_free(stack.a);
	while (++i <= stack.a_len)
		new[j++] = stack.a[i];
	stack.a_len -= 1;
	free(stack.a);
	stack.a = new;
	return (stack);
}

t_stack	del_first_and_move_rest_b(t_stack stack)
{
	int	*new;
	int	i;
	int	j;

	i = 0;
	j = 0;
	new = (int *)malloc((stack.b_len - 1) * sizeof(int));
	if (!new)
		ft_error_free(stack.b);
	while (++i <= stack.b_len)
		new[j++] = stack.b[i];
	stack.b_len -= 1;
	free(stack.b);
	stack.b = new;
	return (stack);
}

t_stack	add_one_to_first_and_move_rest_a(t_stack stack, int n)
{
	int	*new;
	int	i;
	int	j;

	j = 0;
	if (stack.a_len == 0)
	{
		stack.a = (int *)malloc((1) * sizeof(int));
		if (!stack.a)
			ft_error_free(stack.b);
		stack.a[0] = n;
		stack.a_len += 1;
		return (stack);
	}
	new = ft_calloc(stack.a_len + 1, sizeof(int));
	i = 1;
	new[0] = n;
	stack.a_len += 1;
	while (i < stack.a_len)
		new[i++] = stack.a[j++];
	free(stack.a);
	stack.a = new;
	return (stack);
}

t_stack	add_one_to_first_and_move_rest_b(t_stack stack, int n)
{
	int	*new;
	int	i;
	int	j;

	j = 0;
	if (stack.b_len == 0)
	{
		stack.b = (int *)malloc((1) * sizeof(int));
		if (!stack.b)
			ft_error_free(stack.a);
		stack.b[0] = n;
		stack.b_len += 1;
		return (stack);
	}
	new = ft_calloc(stack.b_len + 1, sizeof(int));
	i = 1;
	new[0] = n;
	stack.b_len += 1;
	while (i < stack.b_len)
		new[i++] = stack.b[j++];
	free(stack.b);
	stack.b = new;
	return (stack);
}

t_stack	add_one_to_last_and_move_rest_a(t_stack stack, int n)
{
	int	*new;
	int	i;
	int	j;

	j = 0;
	new = ft_calloc(stack.a_len + 1, sizeof(int));
	i = 0;
	stack.a_len += 1;
	while (i < stack.a_len)
		new[i++] = stack.a[j++];
	new[i - 1] = n;
	free(stack.a);
	stack.a = new;
	return (stack);
}
