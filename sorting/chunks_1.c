/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:26:45 by victofer          #+#    #+#             */
/*   Updated: 2023/02/07 12:40:34 by victofer         ###   ########.fr       */
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
	while (i < 20)
	{
		first = get_first(stack, ini, len);
		last = get_last(stack, ini, len);
		stack = calculate_move(stack, first, last);
		stack = pb(stack);
		i++;
	}
	return (stack);
}
