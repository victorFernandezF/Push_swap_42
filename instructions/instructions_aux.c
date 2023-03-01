/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_temp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:49:11 by victofer          #+#    #+#             */
/*   Updated: 2023/02/21 12:01:24 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

static t_stack	add_one_to_first_and_move_rest_temp(t_stack stack, int n)
{
	int	*new;
	int	i;
	int	j;

	j = 0;
	new = ft_calloc(stack.aux_len + 1, sizeof(int));
	i = 1;
	new[0] = n;
	stack.aux_len += 1;
	while (i < stack.aux_len)
		new[i++] = stack.temp[j++];
	if (stack.temp)
		free(stack.temp);
	stack.temp = new;
	return (stack);
}

static t_stack	del_first_and_move_rest_temp(t_stack stack)
{
	int	*new;
	int	i;
	int	j;

	i = 0;
	j = 0;
	new = (int *)malloc((stack.aux_len - 1) * sizeof(int));
	if (!new)
		ft_error_free(stack);
	while (++i < stack.aux_len)
		new[j++] = stack.temp[i];
	stack.aux_len -= 1;
	free(stack.temp);
	stack.temp = new;
	return (stack);
}

static t_stack	del_last_and_move_rest_temp(t_stack stack)
{
	int	*new;
	int	i;
	int	j;

	i = -1;
	j = 0;
	new = (int *)malloc((stack.aux_len - 1) * sizeof(int));
	if (!new)
		ft_error_free(stack);
	stack.aux_len -= 1;
	while (++i < stack.aux_len)
		new[j++] = stack.temp[i];
	free(stack.temp);
	stack.temp = new;
	return (stack);
}

/*
** Add the given element to last position of stack 'a'
*/
static t_stack	add_one_to_last_and_move_rest_temp(t_stack stack, int n)
{
	int	*new;
	int	i;
	int	j;

	j = 0;
	new = ft_calloc(stack.aux_len + 1, sizeof(int));
	i = 0;
	stack.aux_len += 1;
	while (i < stack.aux_len)
		new[i++] = stack.temp[j++];
	new[i - 1] = n;
	free(stack.temp);
	stack.temp = new;
	return (stack);
}

t_stack	ratemp(t_stack stack)
{
	int	temp;

	if (!stack.temp)
		return (stack);
	temp = stack.temp[0];
	stack = del_first_and_move_rest_temp(stack);
	stack = add_one_to_last_and_move_rest_temp(stack, temp);
	return (stack);
}

/*
** Get the top element from 'a' and put it
** at the top of 'b' (A -> 2 1 4 | B -> 5) -> (A - 1 4 | B - 2 5)
*/
t_stack	pbtemp(t_stack stack)
{
	int	temp;

	if (!stack.temp)
		return (stack);
	temp = stack.temp[0];
	stack = del_first_and_move_rest_temp(stack);
	return (stack);
}

t_stack	rratemp(t_stack stack)
{
	int	temp;

	if (!stack.temp)
		return (stack);
	temp = stack.temp[stack.aux_len - 1];
	stack = del_last_and_move_rest_temp(stack);
	stack = add_one_to_first_and_move_rest_temp(stack, temp);
	stack.moves += 1;
	ft_printf("rra\n");
	return (stack);
}
