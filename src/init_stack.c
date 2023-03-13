/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:50:32 by victofer          #+#    #+#             */
/*   Updated: 2023/03/09 19:00:00 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*	Initializes the stack struct with default datas ready to be
	modified in the future.
	Allocates memory for the arrays used as stack a and stack b.
*	@param *stack
*	@param argc number of arguments.
*/
void	init_stack_struct(t_stack *stack, int argc)
{
	stack->a = (int *)malloc(sizeof(int) * argc);
	stack->b = (int *)ft_calloc(sizeof(int), argc);
	stack->a_len = argc;
	stack->b_len = 0;
	stack->total_moves = 0;
	stack->print_instr = 1;
}
