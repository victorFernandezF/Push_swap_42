/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 13:12:24 by iiliuk            #+#    #+#             */
/*   Updated: 2023/03/06 13:13:48 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void 	apply_sa(t_stack *stack)
{
	register int tmp;

	if (stack->a_len < 2)
		return ;
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	stack->print_instr ? ft_printf("sa\n") : 0;
	stack->moves++;
}

void 	apply_sb(t_stack *stack)
{
	register int tmp;

	if (stack->b_len < 2)
		return ;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	stack->print_instr ? ft_printf("sb\n") : 0;
	stack->moves++;
}

void 	apply_ss(t_stack *stack)
{
	register int tmp_instr;

	tmp_instr = stack->print_instr;
	stack->print_instr = 0;
	apply_sa(stack);
	apply_sb(stack);
	stack->print_instr = tmp_instr;
	stack->print_instr ? ft_printf("ss\n") : 0;
	stack->moves++;
}

void 	apply_pa(t_stack *stack)
{
	register int i;

	if (stack->b_len == 0)
		return ;
	i = stack->a_len;
	while (i-- > 0)
		stack->a[i + 1] = stack->a[i];
	stack->a[0] = stack->b[0];
	i = 0;
	while (i++ <= stack->b_len)
		stack->b[i - 1] = stack->b[i];
	stack->a_len++;
	stack->b_len--;
	stack->print_instr ? ft_printf("pa\n") : 0;
	stack->moves++;
}

void 	apply_pb(t_stack *stack)
{
	register int i;

	if (stack->a_len == 0)
		return ;
	i = stack->b_len;
	while (i-- > 0)
		stack->b[i + 1] = stack->b[i];
	stack->b[0] = stack->a[0];
	i = 0;
	while (i++ <= stack->a_len - 1)
		stack->a[i - 1] = stack->a[i];
	stack->b_len++;
	stack->a_len--;
	stack->print_instr ? ft_printf("pb\n") : 0;
	stack->moves++;
}
