/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:11:28 by victofer          #+#    #+#             */
/*   Updated: 2023/03/01 18:23:16 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// Initializes datas from stack. Used in main
void	init_stack(t_stack *stack)
{
	stack->b = (int *)malloc(1 * sizeof(int));
	stack->temp = (int *)malloc(1 * sizeof(int));
	stack->a_len = 0;
	stack->chunk_len = 20;
	stack->pb_count = 0;
	stack->b_len = 0;
	stack->moves = 0;
}
