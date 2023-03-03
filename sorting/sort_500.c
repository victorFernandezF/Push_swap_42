/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:56:04 by victofer          #+#    #+#             */
/*   Updated: 2023/03/03 14:15:56 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

/* t_moves	*calculate_best_way_a_to_b(t_stack *stack)
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
				*stack = ra(*stack);
			else
				*stack = rra(*stack);
			num_of_rots--;
		}
		*stack = pa(*stack);
	}
	place_smallest_first(stack);
	free(rot_type);
}

static void	process_moves(t_moves *best_move, t_stack *stack)
{
	while (best_move->a_moves)
	{
		if (ft_strequ(best_move->a_rot_type, "ra"))
			*stack = ra(*stack);
		else
			*stack = rra(*stack);
		best_move->a_moves--;
	}
	while (best_move->b_moves)
	{
		if (ft_strequ(best_move->b_rot_type, "rb"))
			*stack = rb(*stack);
		else
			*stack = rrb(*stack);
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
			*stack = pb(*stack);
		else if (index <= stack->a_len / 2)
			*stack = ra(*stack);
		else if (index > stack->a_len / 2)
			*stack = rra(*stack);
	}
}

//Sorts 100 elements (<1.100 moves)
t_stack	sort_500_elements(t_stack *stack)
{
	t_moves	*best_move;
	int		optimus;

	if (stack->a_len > 200)
		optimus = 50;
	else
		optimus = 2;
	while (stack->b_len != 2)
		*stack = pb(*stack);
	//test_print_stacks(*stack);
	while (stack->a_len > optimus)
	{	
		//test_print_stacks(*stack);
		best_move = calculate_best_way_a_to_b(stack);
		while (best_move->common_moves)
		{
			
			if (ft_strequ(best_move->com_rot, "rr"))
				*stack = rr(*stack);
			else
				*stack = rrr(*stack);
			best_move->common_moves--;
		}
		process_moves(best_move, stack);
		*stack = pb(*stack);
		
		free_moves(best_move);
	}
	insert_leftover_to_b(stack);
	insert_back_in_a(stack);
	return (*stack);
} */
