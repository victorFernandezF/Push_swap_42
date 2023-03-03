/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:44:23 by victofer          #+#    #+#             */
/*   Updated: 2023/03/03 13:52:32 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

/*
** Swap the two top elements from  
** stack 'a' (2 1 4 -> 1 2 4)
*/
void	sa(t_stack *stack)
{
	int	aux;

	aux = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = aux;
	stack->moves += 1;
	ft_printf("sa\n");
}

/*
** Swap the two top elements from  
** stack 'b' (2 1 4 -> 1 2 4)
*/
void	sb(t_stack *stack)
{
	int	aux;

	aux = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = aux;
	stack->moves += 1;
	ft_printf("sb\n");
}

// sa + sb 
void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
	stack->moves += 1;
	ft_printf("ss\n");
}

/*
** Get the top element from 'a' and put it
** at the top of 'b' (A -> 2 1 4 | B -> 5) -> (A - 1 4 | B - 2 5)
*/
void	pb(t_stack *stack)
{
	int	aux;

	if (!stack->a)
		return ;
	aux = stack->a[0];
	add_one_to_first_and_move_rest_b(stack, aux);
	del_first_and_move_rest_a(stack);
	stack->moves += 1;
	stack->pb_count += 1;
	ft_printf("pb\n");
}

/*
** Get the top element from 'b' and put it
** at the top of 'a' (A -> 2 1 4 | B -> 5) -> (A - 5 2 1 4 | B -)
*/
void	pa(t_stack *stack)
{
	int	aux;

	if (!stack->b)
		return ;
	aux = stack->b[0];
	add_one_to_first_and_move_rest_a(stack, aux);
	del_first_and_move_rest_b(stack);
	stack->moves += 1;
	ft_printf("pa\n");
}
