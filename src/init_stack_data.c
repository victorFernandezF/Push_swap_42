/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:11:28 by victofer          #+#    #+#             */
/*   Updated: 2023/02/07 19:05:49 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// Initializes datas from stack. Used in main
void	init_stack(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	stack->b = (int *)malloc(1 * sizeof(int));
	stack->chunk_1 = (int *)malloc(19 * sizeof(int));
	if (!stack->chunk_1)
		ft_error_free(*stack);
	stack->a_len = 0;
	stack->chunk_len = 20;
	stack->pb_count = 0;
	stack->b_len = 0;
	stack->moves = 0;
}
