/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:52:10 by victofer          #+#    #+#             */
/*   Updated: 2023/02/21 12:12:58 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

// Calculates the easier way to bring min element to the top
t_stack	smart_rotate(int min, t_stack stack)
{
	int	moves;
	int	j;

	if (min > stack.a_len / 2)
	{
		moves = stack.a_len - min;
		j = -1;
		while (++j < moves)
			stack = rra(stack);
	}
	else
	{
		moves = min;
		j = -1;
		while (++j < moves)
			stack = ra(stack);
	}
	return (stack);
}

// Sorts elements between 5 and 100 (both not included)
t_stack	medium_sort(t_stack stack)
{
	int	i;
	int	limit;
	int	min;

	limit = stack.a_len - 5;
	i = 0;
	while (i < limit)
	{
		min = get_min_pos(stack);
		stack = smart_rotate(min, stack);
		stack = pb(stack);
		i++;
	}
	stack = sort_five_elements(stack);
	i = 0;
	while (i < limit)
	{
		stack = pa(stack);
		i++;
	}
	return (stack);
}

int	get_first(t_stack stack, int f, int l)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stack.aux_len)
	{
		j = f;
		while (j <= l)
		{
			if (stack.temp[i] == j)
			{		
				return (i);
			}
			j++;
		}
	}
	return (-1);
}

int	get_last(t_stack stack, int f, int l)
{
	int	i;
	int	j;

	i = stack.aux_len;
	while (i--)
	{
		j = f;
		while (j <= l)
		{
			if (stack.temp[i] == j)
			{		
				return (i);
			}
			j++;
		}
	}
	return (-1);
}

// Sorts 100 elements (NOT WORKING YET)
t_stack	sort_100_elements(t_stack stack)
{
	int	i;

	stack = init_aux_array(stack);
	stack = sort_aux(stack);
	stack = simplify(stack);
	test_print_stacks(stack);
	i = 0;
	/*stack = chunck(stack, 1, 20);
	stack = sort_stack_b(stack);
	stack.chunk_len = 20;
	stack = chunck(stack, 20, 40);
	stack = sort_stack_b(stack);
	stack.chunk_len = 20;
	stack = chunck(stack, 40, 60);
	stack = sort_stack_b(stack);
	stack.chunk_len = 20;
	stack = chunck(stack, 60, 80);
	stack = sort_stack_b(stack);
	stack.chunk_len = 20;
	stack = chunck(stack, 80, 98);
	stack = sort_stack_b(stack);

	while (i < 100)
	{
		stack = pa(stack);
		i++;
	} */
	return (stack);
}
