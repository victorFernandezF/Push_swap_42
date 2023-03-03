/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:26:45 by victofer          #+#    #+#             */
/*   Updated: 2023/03/03 14:22:26 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

/*
	Calculates which number (first & last) cost less to bring it to
	the top and make the cheaper move. At the end stack is ready to pb.
*/
void	calculate_move(t_stack *stack, int first, int last)
{
	int	mid;
	int	i;

	mid = stack->a_len / 2;
	i = -1;
	if (first == 0)
		return ;
	if (last == stack->a_len)
		rra(stack);
	if (first < stack->a_len - last)
		while (++i < first)
			ra(stack);
	else
		while (++i < stack->a_len - last)
			rra(stack);
}

/*
	Takes all numbers included between [i and len] and put them in
	stack b trying to find the cheapest way.  
*/
void	chunck(t_stack *stack, int i, int len)
{
	int	first;
	int	last;
	int	ini;

	ini = i;
	i = 0;
	while (stack->chunk_len != 0)
	{
		first = get_first(*stack, ini, len);
		last = get_last(*stack, ini, len);
		calculate_move(stack, first, last);
		pb(stack);
		stack->chunk_len -= 1;
		i++;
	}
}
