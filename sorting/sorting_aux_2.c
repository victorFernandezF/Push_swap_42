/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_aux_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:05:52 by marvin            #+#    #+#             */
/*   Updated: 2023/01/31 18:50:32 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	get_min_pos(t_stack stack)
{
	int	i;
	int	min_array;

	min_array = min(stack.a, stack.a_len - 1);
	//printf("\nmin_value %i\n", min_array);
	i = -1;
	while (++i < stack.a_len)
		if (stack.a[i] == min_array)
			return (i);
	return (0);
}
