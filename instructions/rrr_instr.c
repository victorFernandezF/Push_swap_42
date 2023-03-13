/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_instr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:55:55 by victofer          #+#    #+#             */
/*   Updated: 2023/03/09 18:16:14 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

/*
	The lastfirst element of stack a becomes the first one.
*/
void	rra(t_stack *stack)
{
	int	i;
	int	tmp;

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
	if (stack->print_instr)
		ft_printf("rra\n");
	stack->total_moves++;
}

/*
	The lastfirst element of stack b becomes the first one.
*/
void	rrb(t_stack *stack)
{
	int	i;
	int	tmp;

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
	if (stack->print_instr)
		ft_printf("rrb\n");
	stack->total_moves++;
}

// Make rra and rrb at the same time.
void	rrr(t_stack *stack)
{
	int	tmp_instr;

	tmp_instr = stack->print_instr;
	stack->print_instr = 0;
	rra(stack);
	rrb(stack);
	stack->print_instr = tmp_instr;
	if (stack->print_instr)
		ft_printf("rrr\n");
	stack->total_moves++;
}
