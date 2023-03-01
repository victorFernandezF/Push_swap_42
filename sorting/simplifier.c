/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplifier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:48:00 by victofer          #+#    #+#             */
/*   Updated: 2023/03/01 14:35:33 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

// Initialize auxiliar array with the numbers of stack a.
t_stack	init_aux_array(t_stack stack)
{
	int	i;

	stack.aux_len = stack.a_len;
	stack.aux = (int *)malloc(stack.aux_len * sizeof(int));
	if (!stack.aux)
		exit(-1);
	i = -1;
	while (++i < stack.aux_len)
		stack.aux[i] = stack.a[i];
	stack.temp = (int *)malloc(stack.aux_len * sizeof(int));
	if (!stack.temp)
		exit(-1);
	i = -1;
	while (++i < stack.aux_len)
		stack.temp[i] = stack.a[i];
	return (stack);
}

// Sorts the auxiliar stack.
t_stack	sort_aux(t_stack stack)
{
	int		i;
	int		tmp;

	i = 0;
	while (1)
	{
		if (is_sorted(stack.aux_len, stack.aux) == 1)
			break ;
		if (stack.aux[i] > stack.aux[i + 1])
		{
			tmp = stack.aux[i];
			stack.aux[i] = stack.aux[i + 1];
			stack.aux[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	return (stack);
}

/*
	Changes the numbers in stack a by indexes
	example (-1 2 -5 0 4) becomes (2 4 1 3 5)
	so now we dont care about negatives numbers
*/
t_stack	simplify(t_stack stack)
{
	int	i;
	int	j;
	int	x;
	int	len;

	i = 0;
	x = 1;
	len = stack.aux_len;
	while (i < stack.aux_len)
	{
		j = 0;
		while (j < len)
		{
			if (stack.aux[i] == stack.a[j])
			{
				stack.temp[j] = x;
				x++;
			}
			j++;
		}
		i++;
	}
	//free(stack.temp);
	return (stack);
}
