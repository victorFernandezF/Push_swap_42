/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_moves_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:04:29 by victofer          #+#    #+#             */
/*   Updated: 2023/02/06 11:40:46 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

/*
** Remove the first element from the stack 'a' and move
** the rest of them one position to the left.
*/
t_stack	del_first_and_move_rest_a(t_stack stack)
{
	int	*new;
	int	i;
	int	j;

	i = 0;
	j = 0;
	new = (int *)malloc((stack.a_len - 1) * sizeof(int));
	if (!new)
		ft_error_free(stack);
	while (++i < stack.a_len)
		new[j++] = stack.a[i];
	stack.a_len -= 1;
	free(stack.a);
	stack.a = new;
	return (stack);
}

/*
** Add the given element to first position of stack 'a'
** and move the rest of them one position to the right.
*/
t_stack	add_one_to_first_and_move_rest_a(t_stack stack, int n)
{
	int	*new;
	int	i;
	int	j;

	j = 0;
	new = ft_calloc(stack.a_len + 1, sizeof(int));
	i = 1;
	new[0] = n;
	stack.a_len += 1;
	while (i < stack.a_len)
		new[i++] = stack.a[j++];
	if (stack.a)
		free(stack.a);
	stack.a = new;
	return (stack);
}

/*
** Remove the last element from the stack 'a'
*/
t_stack	del_last_and_move_rest_a(t_stack stack)
{
	int	*new;
	int	i;
	int	j;

	i = -1;
	j = 0;
	new = (int *)malloc((stack.a_len - 1) * sizeof(int));
	if (!new)
		ft_error_free(stack);
	stack.a_len -= 1;
	while (++i < stack.a_len)
		new[j++] = stack.a[i];
	free(stack.a);
	stack.a = new;
	return (stack);
}

/*
** Add the given element to last position of stack 'a'
*/
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
