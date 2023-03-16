/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:38:43 by victofer          #+#    #+#             */
/*   Updated: 2023/03/16 17:55:01 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	find_place_in_a(int *stack, int len, int elem, char **rotation_type)
{
	int	i;
	int	place;

	i = -1;
	place = 0;
	if (len == 2 && elem > stack[0] && elem < stack[1])
		place = 1;
	else if (len == 2 && elem < stack[0] && elem > stack[1])
		place = 0;
	else if (elem > stack[find_max_elem(stack, len)]
		|| elem < stack[find_min_elem(stack, len)])
		place = find_min_elem(stack, len);
	else
	{
		while (++i < len)
		{
			if (elem > stack[i] && ((i + 1 < len && elem < stack[i + 1])
					|| (i + 1 == len && elem < stack[0])))
			{
				place = i + 1;
				break ;
			}
		}
	}
	return (find_rotation_a(len, place, rotation_type));
}

static void	insert_back_in_a(t_stack *stack)
{
	int		num_of_rots;
	char	*rotation_type;

	num_of_rots = 0;
	rotation_type = new_str(3);
	while (stack->b_len)
	{
		num_of_rots = find_place_in_a(stack->a,
				stack->a_len, stack->b[0], &rotation_type);
		while (num_of_rots > 0)
		{
			if (string_compare(rotation_type, "ra"))
				ra(stack);
			else
				rra(stack);
			num_of_rots--;
		}
		pa(stack);
	}
	place_smallest_first_a(stack);
	free(rotation_type);
}

static void	insert_rest_to_b(t_stack *stack)
{
	int	idx;

	idx = 0;
	while (stack->a_len > 2)
	{
		idx = find_min_elem(stack->a, stack->a_len);
		if (idx == 0)
			pb(stack);
		else if (idx <= stack->a_len / 2)
			ra(stack);
		else if (idx > stack->a_len / 2)
			rra(stack);
	}
}

/*
*	Makes the correct rotation intruction depending on the
	move calculated before
*	@param best_move - struct whith the moves datas.
*	@param stack
*/
static void	process_moves(t_moves *best_move, t_stack *stack)
{
	while (best_move->a_moves)
	{
		if (string_compare(best_move->a_rotation_type, "ra"))
			ra(stack);
		else
			rra(stack);
		best_move->a_moves--;
	}
	while (best_move->b_moves)
	{
		if (string_compare(best_move->b_rotation_type, "rb"))
			rb(stack);
		else
			rrb(stack);
		best_move->b_moves--;
	}
}

/*
*	Sorts stack a as long as its size is more than 3 elements
*	@param stack
*/
void	big_sort(t_stack *stack)
{
	t_moves	*best_move;
	int		optimizer;

	optimizer = get_optimus_stack(stack);
	while (stack->b_len != 2)
		pb(stack);
	while (stack->a_len > optimizer)
	{
		best_move = cheapest_move_stack_a_to_b(stack);
		while (best_move->common_moves)
		{
			if (string_compare(best_move->common_rotation, "rr"))
				rr(stack);
			else
				rrr(stack);
			best_move->common_moves--;
		}
		process_moves(best_move, stack);
		pb(stack);
		free_moves(best_move);
	}
	insert_rest_to_b(stack);
	insert_back_in_a(stack);
}
