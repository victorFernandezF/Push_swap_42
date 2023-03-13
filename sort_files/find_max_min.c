/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:39:53 by victofer          #+#    #+#             */
/*   Updated: 2023/03/10 10:57:12 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

/*
*	Returns the position of the minimun element of the given stack.
*	@param *stack array of number [stack a or stack b]
*	@param len size of the given array.
*/
int	find_min_position(int *stack, int len)
{
	int	i;
	int	tmp;
	int	index;

	if (len == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = stack[i];
	while (i < len)
	{
		if (tmp > stack[i])
		{
			tmp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

/*
*	Returns minimun element of the given stack.
*	@param *stack array of number [stack a or stack b]
*	@param stack_len size of the given array.
*/
int	find_min_elem(int *stack, int stack_len)
{
	int	i;
	int	tmp;
	int	index;

	if (stack_len == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = stack[i];
	while (i < stack_len)
	{
		if (tmp > stack[i])
		{
			tmp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

/*
*	Returns the maximun element of the given stack.
*	@param *stack array of number [stack a or stack b]
*	@param stack_len size of the given array.
*/
int	find_max_elem(int *stack, int stack_len)
{
	int	i;
	int	tmp;
	int	index;

	if (stack_len == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = stack[i];
	while (i < stack_len)
	{
		if (tmp < stack[i])
		{
			tmp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}
