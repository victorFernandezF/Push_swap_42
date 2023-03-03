/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:24:28 by victofer          #+#    #+#             */
/*   Updated: 2023/03/03 14:15:37 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

// Returns the first element (that is part of a chunk) found in stack a
int	get_first(t_stack stack, int f, int l)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stack.a_len)
	{
		j = f;
		while (j <= l)
		{
			if (stack.a[i] == j)
			{		
				return (i);
			}
			j++;
		}
	}
	return (-1);
}

// Returns the last element (that is part of a chunk) found in stack a
int	get_last(t_stack stack, int f, int l)
{
	int	i;
	int	j;

	i = stack.a_len;
	while (i--)
	{
		j = f;
		while (j <= l)
		{
			if (stack.a[i] == j)
			{		
				return (i);
			}
			j++;
		}
	}
	return (-1);
}

// Move everithing in stack b to stack a.
void	move_to_stack_a(t_stack *stack, int limit)
{
	int	i;

	(void)limit;
	i = stack->b_len;
	while (i--)
	{
		pa(stack);
	}
}

// Sorts 100 elements (<1.100 moves)
void	sort_100_elements(t_stack *stack, int n)
{
	*stack = init_aux_array(*stack);
	*stack = sort_aux(*stack);
	*stack = simplify(*stack);
	stack->a = stack->temp;
	chunck(stack, n, n + 20);
	sort_stack_b(stack, 20);
	stack->chunk_len = 20;
	n += 20;
	chunck(stack, n, n + 20);
	sort_stack_b(stack, 20);
	stack->chunk_len = 20;
	n += 20;
	chunck(stack, n, n + 20);
	sort_stack_b(stack, 20);
	stack->chunk_len = 20;
	n += 20;
	chunck(stack, n, n + 20);
	sort_stack_b(stack, 20);
	stack->chunk_len = 20;
	n += 20;
	chunck(stack, n, n + 20);
	sort_stack_b(stack, 20);
	move_to_stack_a(stack, 100);
}
