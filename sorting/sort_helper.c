/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:19:46 by iiliuk            #+#    #+#             */
/*   Updated: 2023/03/06 11:08:17 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int 	find_min_index(int *stack, int len)
{
	register int i;
	register int tmp;
	register int index;

	if (len == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = stack[i];
	while (i < len)
	{
		if (tmp > stack[i])
		{
			tmp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int 	find_max_index(int *stack, int len)
{
	register int i;
	register int tmp;
	register int index;

	if (len == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = stack[i];
	while (i < len)
	{
		if (tmp < stack[i])
		{
			tmp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int 	find_min_elem(int *stack, int stack_len)
{
	register int i;
	register int tmp;
	register int index;

	if (stack_len == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = stack[i];
	while (i < stack_len) 
	{
		if (tmp > stack[i])
		{
			tmp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int 	find_max_elem(int *stack, int stack_len)
{
	int i;
	int tmp;
	int index;

	if (stack_len == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = stack[i];
	while (i < stack_len) 
	{
		if (tmp < stack[i])
		{
			tmp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	place_smallest_first_a(t_stack *stack)
{
	register int min_index;

	min_index = find_min_index(stack->a, stack->a_len);
	if (min_index <= stack->a_len / 2)
		while (min_index--)
			ra(stack);
	else
		while ((stack->a_len - min_index) > 0)
		{
			rra(stack);
			min_index++;
		}
}
