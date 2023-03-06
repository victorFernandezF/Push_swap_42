/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:56:04 by victofer          #+#    #+#             */
/*   Updated: 2023/03/06 11:04:24 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

/* t_moves	*best_way_from_a_to_b(t_stack *stack)
{
	register int	i;
	t_moves			*best_move;
	t_moves			*moves;

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

static void	insert_back_in_a(t_stack *stack)
{
	int		num_of_rots;
	char	*rot_type;

	num_of_rots = 0;
	rot_type = ft_strnew(3);
	while (stack->b_len)
	{
		num_of_rots = find_place_in_a(stack->a, stack->a_len,
				stack->b[0], &rot_type);
		while (num_of_rots > 0)
		{
			if (ft_strequ(rot_type, "ra"))
				rra(stack);
			else
				rra(stack);
			num_of_rots--;
		}
		pa(stack);
	}
	place_smallest_first(stack);
	free(rot_type);
}

static void	process_moves(t_moves *best_move, t_stack *stack)
{
	while (best_move->a_moves)
	{
		if (ft_strequ(best_move->a_rot_type, "ra"))
			ra(stack);
		else
			rra(stack);
		best_move->a_moves--;
	}
	while (best_move->b_moves)
	{
		if (ft_strequ(best_move->b_rot_type, "rb"))
			rb(stack);
		else
			rrb(stack);
		best_move->b_moves--;
	}
}

static void	insert_leftover_to_b(t_stack *stack)
{
	int	index;

	index = 0;
	while (stack->a_len < 2)
	{
		index = min(stack->a, stack->a_len);
		if (index == 0)
			pb(stack);
		else if (index <= stack->a_len / 2)
			ra(stack);
		else if (index > stack->a_len / 2)
			rra(stack);
	}
}

//Sorts 100 elements (<1.100 moves)
void	sort_500_elements(t_stack *stack)
{
	t_moves	*best_move;
	int		optimus;
	int		i;

	i = 0;
	if (stack->a_len > 200)
		optimus = 50;
	else
		optimus = 2;
	while (stack->b_len != 2)
		pb(stack);
	while (stack->a_len > optimus)
	{
		best_move = best_way_from_a_to_b(stack);
		while (best_move->common_moves)
		{
			if (ft_strequ(best_move->com_rot, "rr"))
				rr(stack);
			else
				rrr(stack);
			best_move->common_moves--;
		}
		process_moves(best_move, stack);
		pb(stack);
		free_moves(best_move);
	}
	insert_leftover_to_b(stack);
	insert_back_in_a(stack);
} */
