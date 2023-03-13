/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cheaper_move.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:36:46 by victofer          #+#    #+#             */
/*   Updated: 2023/03/10 10:51:35 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

static	int	find_place_in_b(int *stack, int len, int elem, char **rot_type)
{
	int	i;
	int	place;

	i = -1;
	place = 0;
	if (len == 2 && elem > stack[0] && elem < stack[len - 1])
		place = 0;
	else if (len == 2 && elem < stack[0] && elem > stack[len - 1])
		place = 1;
	else if (elem > stack[find_max_elem(stack, len)]
		|| elem < stack[find_min_elem(stack, len)])
		place = find_max_elem(stack, len);
	else
	{
		while (++i < len)
		{
			if (elem < stack[i] && ((i + 1 < len && elem > stack[i + 1])
					|| (i + 1 == len && elem > stack[0])))
			{
				place = i + 1;
				break ;
			}
		}
	}
	return (find_rotation_b(len, place, rot_type));
}

int	find_common(t_moves *moves)
{
	int		common;

	common = 0;
	if ((string_compare(moves->a_rotation_type, "rra")
			&& (string_compare(moves->b_rotation_type, "rrb")))
		|| (string_compare(moves->a_rotation_type, "ra")
			&& (string_compare(moves->b_rotation_type, "rb"))))
	{
		if (moves->a_moves > moves->b_moves)
			common = moves->b_moves;
		else
			common = moves->a_moves;
		if (common)
		{
			moves->common_rotation = ft_strcpy(moves->common_rotation,
					moves->a_rotation_type);
			moves->common_rotation[ft_strlen(moves->common_rotation) - 1] = 'r';
			moves->b_moves -= common;
			moves->a_moves -= common;
		}
	}
	return (common);
}

static t_moves	*calc_moves_from_a_to_b(t_stack *stack, int pos)
{
	t_moves	*moves;

	moves = (t_moves *)malloc(sizeof(t_moves));
	moves->a_rotation_type = new_str(3);
	moves->b_rotation_type = new_str(3);
	moves->common_rotation = new_str(3);
	moves->element = stack->a[pos];
	moves->a_moves = find_rotation_a(stack->a_len, pos,
			&(moves->a_rotation_type));
	moves->b_moves = find_place_in_b(stack->b, stack->b_len,
			stack->a[pos], &(moves->b_rotation_type));
	moves->common_moves = find_common(moves);
	moves->total = moves->a_moves + moves->b_moves + moves->common_moves + 1;
	return (moves);
}

t_moves	*cheapest_move_stack_a_to_b(t_stack *stack)
{
	int			i;
	t_moves		*best_move;
	t_moves		*moves;

	i = 0;
	while (i < stack->a_len)
	{
		moves = calc_moves_from_a_to_b(stack, i);
		if (i == 0)
			best_move = moves;
		else if (best_move->total > moves->total)
		{
			free_moves(best_move);
			best_move = moves;
		}
		else
			free_moves(moves);
		i++;
	}
	return (best_move);
}
