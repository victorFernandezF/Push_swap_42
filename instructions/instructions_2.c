/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:12:46 by victofer          #+#    #+#             */
/*   Updated: 2023/03/03 13:53:30 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

/*
** Move the top element from 'a' and put it
** at last position of a (2 1 4 -> 1 4 2)
*/
void	ra(t_stack *stack)
{
	int	aux;

	if (!stack->a)
		return ;
	aux = stack->a[0];
	del_first_and_move_rest_a(stack);
	add_one_to_last_and_move_rest_a(stack, aux);
	stack->moves += 1;
	ft_printf("ra\n");
}

/*
** Move the top element from 'b' and put it
** at last position of a (2 1 4 -> 1 4 2)
*/
void	rb(t_stack *stack)
{
	int	aux;

	if (!stack->b)
		return ;
	aux = stack->b[0];
	del_first_and_move_rest_b(stack);
	add_one_to_last_and_move_rest_b(stack, aux);
	stack->moves += 1;
	ft_printf("rb\n");
}

// ra + rb
void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
	stack->moves += 1;
	ft_printf("rr\n");
}
