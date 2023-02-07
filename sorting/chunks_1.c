/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:26:45 by victofer          #+#    #+#             */
/*   Updated: 2023/02/07 19:09:01 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

t_stack	chunck(t_stack stack, int i, int len)
{
	int	first;
	int	last;
	int	ini;

	ini = i;
	i = 0;
	while (stack.chunk_len != 0)
	{
		//printf("\nchunk_len %i\n", stack.chunk_len);
		first = get_first(stack, ini, len);
		last = get_last(stack, ini, len);
		stack = calculate_move(stack, first, last);
		stack = pb(stack);
		stack.chunk_len -= 1;
		i++;
	}
	return (stack);
}
