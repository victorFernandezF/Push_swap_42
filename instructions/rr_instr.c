/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_instr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:54:12 by victofer          #+#    #+#             */
/*   Updated: 2023/03/09 18:15:19 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

/*
	The first element of stack a becomes the last one.
*/
void	ra(t_stack *stack)
{
	int	i;
	int	tmp;

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
	if (stack->print_instr)
		ft_printf("ra\n");
	stack->total_moves++;
}

/*
	The first element of stack b becomes the last one.
*/
void	rb(t_stack *stack)
{
	int	i;
	int	tmp;

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
	if (stack->print_instr)
		ft_printf("rb\n");
	stack->total_moves++;
}

// Make ra and rb at the same time.
void	rr(t_stack *stack)
{
	int	tmp_instr;

	tmp_instr = stack->print_instr;
	stack->print_instr = 0;
	ra(stack);
	rb(stack);
	stack->print_instr = tmp_instr;
	if (stack->print_instr)
		ft_printf("rr\n");
	stack->total_moves++;
}
