/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:41:29 by victofer          #+#    #+#             */
/*   Updated: 2023/03/13 19:05:48 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../src/push_swap.h"

/*
*	Frees the memory used by arrays of stack a and stack b.
	Then free the stack structure.
*	@param *stack
*/
void	free_stack(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack);
	stack = NULL;
}

void	free_argv(char **argv, int aux)
{
	int	i;

	i = -1;
	if (aux == 1)
	{
		while (argv[++i])
			free(argv[i]);
		free(argv);
		argv = NULL;
	}
}

/*
*	Frees the memory used by the moves structure.
	Then free the moves structure.
*	@param *moves
*/
void	free_moves(t_moves *moves)
{
	free(moves->a_rotation_type);
	free(moves->b_rotation_type);
	free(moves->common_rotation);
	free(moves);
	moves = NULL;
}
