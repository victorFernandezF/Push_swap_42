/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:04:29 by victofer          #+#    #+#             */
/*   Updated: 2023/01/19 12:02:35 by victofer         ###   ########.fr       */
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

	i = -1;
	j = 0;
	new = (int *)malloc((stack.a_len + 1) * sizeof(int));
	if (!new)
		ft_error_free(stack.a);
	new[0] = n;
	stack.a_len += 1;
	while (++i < stack.a_len)
		new[++j] = stack.a[i];
	free(stack.a);
	stack.a = new;
	return (stack);
}

t_stack	add_one_to_first_and_move_rest_b(t_stack stack, int n)
{
	int	*new;
	int	i;
	int	j;

	i = -1;
	j = 0;
	new = (int *)malloc((stack.b_len + 1) * sizeof(int));
	if (!new)
		ft_error_free(stack.a);
	new[0] = n;
	stack.b_len += 1;
	while (++i < stack.b_len)
		new[++j] = stack.b[i];
	free(stack.b);
	stack.b = new;
	free(new);
	return (stack);
}
