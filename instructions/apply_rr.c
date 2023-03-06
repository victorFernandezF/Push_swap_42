/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:17:05 by iiliuk            #+#    #+#             */
/*   Updated: 2023/03/06 13:14:20 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void 	apply_ra(t_stack *stack)
{
	register int i;
	register int tmp;

	if (stack->a_len == 0)
		return ;
	i = 1;
	tmp = stack->a[0];
	while (i < stack->a_len) 
	{
		stack->a[i - 1] = stack->a[i];
		i++;
	}
	stack->a[i - 1] = tmp;
	stack->print_instr ? ft_printf("ra\n") : 0;
	stack->moves++;
}

void 	apply_rb(t_stack *stack)
{
	register int i;
	register int tmp;

	if (stack->b_len == 0)
		return ;
	i = 1;
	tmp = stack->b[0];
	while (i < stack->b_len) 
	{
		stack->b[i - 1] = stack->b[i];
		i++;
	}
	stack->b[i - 1] = tmp;
	stack->print_instr ? ft_printf("rb\n") : 0;
	stack->moves++;
}

void 	apply_rr(t_stack *stack)
{
	register int tmp_instr;

	tmp_instr = stack->print_instr;
	stack->print_instr = 0;
	apply_ra(stack);
	apply_rb(stack);
	stack->print_instr = tmp_instr;
	stack->print_instr ? ft_printf("rr\n") : 0;
	stack->moves++;
}
