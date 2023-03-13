/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_and_p_instr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:52:06 by victofer          #+#    #+#             */
/*   Updated: 2023/03/09 18:13:22 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

/*
	Swap the first two elements at the top os stack a.
	Do nothing if there is only one or no elements.
*/
void	sa(t_stack *stack)
{
	int	tmp;

	if (stack->a_len < 2)
		return ;
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	if (stack->print_instr)
		ft_printf("sa\n");
	stack->total_moves++;
}

/*
	Swap the first two elements at the top os stack b.
	Do nothing if there is only one or no elements.
*/
void	sb(t_stack *stack)
{
	int	tmp;

	if (stack->b_len < 2)
		return ;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	if (stack->print_instr)
		ft_printf("sb\n");
	stack->total_moves++;
}

// Make sa and sb at the same time.
void	ss(t_stack *stack)
{
	int	tmp_instr;

	tmp_instr = stack->print_instr;
	stack->print_instr = 0;
	sa(stack);
	sb(stack);
	stack->print_instr = tmp_instr;
	if (stack->print_instr)
		ft_printf("ss\n");
	stack->total_moves++;
}

/*
	Take the top element of stack b and put it at the top of a.
	Do nothing if b is empty.
*/
void	pa(t_stack *stack)
{
	int	i;

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
	if (stack->print_instr)
		ft_printf("pa\n");
	stack->total_moves++;
}

/*
	Take the top element of stack a and put it at the top of b.
	Do nothing if b is empty.
*/
void	pb(t_stack *stack)
{
	int	i;

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
	if (stack->print_instr)
		ft_printf("pb\n");
	stack->total_moves++;
}
