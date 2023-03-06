/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:17:05 by iiliuk            #+#    #+#             */
/*   Updated: 2023/03/06 13:12:22 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void 	apply_rra(t_stack *stack)
{
	register int i;
	register int tmp;

	if (stack->a_len == 0)
		return ;
	i = stack->a_len - 1;
	tmp = stack->a[i];
	while (i > 0) 
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = tmp;
	stack->print_instr ? ft_printf("rra\n") : 0;
	stack->moves++;
}

void 	apply_rrb(t_stack *stack)
{
	register int i;
	register int tmp;

	if (stack->b_len == 0)
		return ;
	i = stack->b_len - 1;
	tmp = stack->b[i];
	while (i > 0) 
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = tmp;
	stack->print_instr ? ft_printf("rrb\n") : 0;
	stack->moves++;
}

void 	apply_rrr(t_stack *stack)
{
	register int tmp_instr;

	tmp_instr = stack->print_instr;
	stack->print_instr = 0;
	stack->moves = 0;
	apply_rra(stack);
	apply_rrb(stack);
	stack->print_instr = tmp_instr;
	stack->print_instr ? ft_printf("rrr\n") : 0;
	stack->moves++;
}
