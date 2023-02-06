/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:12:54 by victofer          #+#    #+#             */
/*   Updated: 2023/02/06 13:39:06 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

/*
** Move the last element from 'a' and put it
** at firts position of a (2 1 4 ->  4 1 2)
*/
t_stack	rra(t_stack stack)
{
	int	aux;

	if (!stack.a)
		return (stack);
	aux = stack.a[stack.a_len - 1];
	stack = del_last_and_move_rest_a(stack);
	stack = add_one_to_first_and_move_rest_a(stack, aux);
	stack.moves += 1;
	ft_printf("rra\n");
	return (stack);
}

/*
** Move the last element from 'b' and put it
** at firts position of b (2 1 4 ->  4 1 2)
*/
t_stack	rrb(t_stack stack)
{
	int	aux;

	if (!stack.b)
		return (stack);
	aux = stack.b[stack.b_len - 1];
	stack = del_last_and_move_rest_b(stack);
	stack = add_one_to_first_and_move_rest_b(stack, aux);
	stack.moves += 1;
	ft_printf("rrb\n");
	return (stack);
}

// rra + rrb
t_stack	rrr(t_stack stack)
{
	stack = rra(stack);
	stack = rrb(stack);
	stack.moves += 1;
	ft_printf("rrr\n");
	return (stack);
}

// Splits the string with the instructions and execute them.
t_stack	pack_of_instructions(char *pack, t_stack stack)
{
	char	**inst;
	int		i;

	i = 0;
	inst = ft_split(pack, '_');
	while (inst[i])
	{
		stack = do_operation(inst[i], stack);
		free(inst[i]);
		i++;
	}
	i = 0;
	free(inst);
	return (stack);
}

// Evaluates the instruction received and execute it.
t_stack	do_operation(char *op, t_stack stack)
{
	if (ft_strncmp(op, "sa", 4) == 0)
		stack = sa(stack);
	else if (ft_strncmp(op, "sb", 4) == 0)
		stack = sb(stack);
	else if (ft_strncmp(op, "ss", 4) == 0)
		stack = ss(stack);
	else if (ft_strncmp(op, "pa", 4) == 0)
		stack = pa(stack);
	else if (ft_strncmp(op, "pb", 4) == 0)
		stack = pb(stack);
	else if (ft_strncmp(op, "ra", 4) == 0)
		stack = ra(stack);
	else if (ft_strncmp(op, "rb", 4) == 0)
		stack = rb(stack);
	else if (ft_strncmp(op, "rr", 4) == 0)
		stack = rr(stack);
	else if (ft_strncmp(op, "rra", 4) == 0)
		stack = rra(stack);
	else if (ft_strncmp(op, "rrb", 4) == 0)
		stack = rrb(stack);
	else if (ft_strncmp(op, "rrr", 4) == 0)
		stack = rrr(stack);
	return (stack);
}
