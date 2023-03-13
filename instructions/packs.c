/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:11:37 by victofer          #+#    #+#             */
/*   Updated: 2023/03/06 12:13:29 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

// Splits the string with the instructions and execute them.
void	pack_of_instructions(char *pack, t_stack *stack)
{
	char	**inst;
	int		i;

	i = 0;
	inst = ft_split(pack, '_');
	while (inst[i])
	{
		do_operation(inst[i], stack);
		free(inst[i]);
		i++;
	}
	i = 0;
	free(inst);
}

// Evaluates the instruction received and execute it.
void	do_operation(char *op, t_stack *stack)
{
	if (ft_strncmp(op, "sa", 4) == 0)
		sa(stack);
	else if (ft_strncmp(op, "sb", 4) == 0)
		sb(stack);
	else if (ft_strncmp(op, "ss", 4) == 0)
		ss(stack);
	else if (ft_strncmp(op, "pa", 4) == 0)
		pa(stack);
	else if (ft_strncmp(op, "pb", 4) == 0)
		pb(stack);
	else if (ft_strncmp(op, "ra", 4) == 0)
		ra(stack);
	else if (ft_strncmp(op, "rb", 4) == 0)
		rb(stack);
	else if (ft_strncmp(op, "rr", 4) == 0)
		rr(stack);
	else if (ft_strncmp(op, "rra", 4) == 0)
		rra(stack);
	else if (ft_strncmp(op, "rrb", 4) == 0)
		rrb(stack);
	else if (ft_strncmp(op, "rrr", 4) == 0)
		rrr(stack);
}
