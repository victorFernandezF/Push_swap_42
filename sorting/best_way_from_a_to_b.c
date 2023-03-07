/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_way_from_a_to_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:12:29 by victofer          #+#    #+#             */
/*   Updated: 2023/03/07 12:24:42 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	find_place_in_b(int *stack, int len, int elem, char **rot_type)
{
	int	i;
	int	place;

	i = 0;
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
		while (i < len)
		{
			if (elem < stack[i] && ((i + 1 < len && elem > stack[i + 1])
					|| (i + 1 == len && elem > stack[0])))
			{
				place = i + 1;
				break ;
			}
			i++;
		}
	}
	return (find_b_rot_type(len, place, rot_type));
}

int	find_common(t_moves *moves)
{
	int		common;

	common = 0;
	if ((ft_strequ(moves->a_rot_type, "rra") && (ft_strequ(moves->b_rot_type , "rrb"))) ||
			(ft_strequ(moves->a_rot_type, "ra") && (ft_strequ(moves->b_rot_type , "rb"))))
	{
		common = (moves->a_moves > moves->b_moves ? moves->b_moves : moves->a_moves);
		if (common)
		{
			moves->common_rot = ft_strcpy(moves->common_rot, moves->a_rot_type);
			moves->common_rot[ft_strlen(moves->common_rot) - 1] = 'r';
			moves->b_moves -= common;
			moves->a_moves -= common;
		}
	}
	printf("COMMON TEST %s \n", moves->a_rot_type);
	return (common);
}

t_moves	*calc_moves_from_a_to_b(t_stack *stack, int pos)
{
	t_moves *moves;

	moves = (t_moves *)malloc(sizeof(t_moves));
	moves->a_rot_type = ft_strnew(3);
	moves->b_rot_type = ft_strnew(3);
	moves->common_rot = ft_strnew(3);
	moves->elem = stack->a[pos];
	moves->a_moves = find_a_rot_type(stack->a_len, pos, &(moves->a_rot_type));
	moves->b_moves = find_place_in_b(stack->b, stack->b_len,
	stack->a[pos], &(moves->b_rot_type));
	moves->common_moves = find_common(moves);
	moves->total = moves->a_moves + moves->b_moves + moves->common_moves + 1;
	return (moves);
}

t_moves	*best_way_from_a_to_b(t_stack *stack)
{
	int		i;
	t_moves	*best_move;
	t_moves	*moves;

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
	//printf("\n TEST - %s\n", moves->total);
	return (best_move);
}
