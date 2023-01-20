/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_moves_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:04:29 by victofer          #+#    #+#             */
/*   Updated: 2023/01/20 13:08:42 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
** Remove the first element from the stack 'b' and move
** the rest of them one position to the left.
*/
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

/*
** Add the given element to first position of stack 'b'
** and move the rest of them one position to the right.
*/
t_stack	add_one_to_first_and_move_rest_b(t_stack stack, int n)
{
	int	*new;
	int	i;
	int	j;

	j = 0;
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

/*
** Remove the last element from the stack 'b'
*/
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

/*
** Add the given element to last position of stack 'b'
*/
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
