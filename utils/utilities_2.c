/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:21:40 by victofer          #+#    #+#             */
/*   Updated: 2023/03/03 14:23:02 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../src/push_swap.h"

void	place_smallest_first(t_stack *stack)
{
	int	min_index;

	min_index = get_min_pos(*stack);
	if (min_index <= stack->a_len / 2)
		while (min_index--)
			ra(stack);
	else
	{
		while ((stack->a_len - min_index) > 0)
		{
			rra(stack);
			min_index++;
		}
	}		
}

int	find_place_in_b(int *stack, int len, int elem, char **rot_type)
{
	int	i;
	int	place;

	i = 0;
	place = 0;
	if (len == 2 && elem > stack[0] && elem < stack[len - 1])
		place = 0;
	else if (len == 2 && elem < stack[0] && elem > stack[len - 1])
		place = 1;
	else if (elem > stack[max(stack, len)]
		|| elem < stack[min(stack, len)])
		place = max(stack, len);
	else
	{
		while (i < len)
		{
			if (elem < stack[i] && ((i + 1 < len && elem > stack[i + 1])
					|| (i + 1 == len && elem > stack[0])))
			{
				place = i + 1;
				break ;
			}
			i++;
		}
	}
	return (find_b_rot(len, place, rot_type));
}

int	find_place_in_a(int *stack, int len, int elem, char **rot_type)
{
	int	i;
	int	place;

	i = 0;
	place = 0;
	if (len == 2 && elem > stack[0] && elem < stack[1])
		place = 1;
	else if (len == 2 && elem < stack[0] && elem > stack[1])
		place = 0;
	else if (elem > stack[max(stack, len)]
		|| elem < stack[min(stack, len)])
		place = min(stack, len);
	else
	{
		while (i < len)
		{
			if (elem > stack[i] && ((i + 1 < len && elem < stack[i + 1])
					|| (i + 1 == len && elem < stack[0])))
			{
				place = i + 1;
				break ;
			}
			i++;
		}
	}
	return (find_a_rot(len, place, rot_type));
}

int	find_a_rot(int len, int pos, char **a_rot_type)
{
	if (pos > len / 2)
	{
		*a_rot_type = ft_strcpy(*a_rot_type, "rra");
		if (len > 2)
			pos = len - pos;
	}
	else
		*a_rot_type = ft_strcpy(*a_rot_type, "ra");
	return (pos);
}

int	find_b_rot(int len, int pos, char **b_rot_type)
{
	if (pos > len / 2)
	{
		*b_rot_type = ft_strcpy(*b_rot_type, "rrb");
		if (len > 2)
			pos = len - pos;
	}
	else
		*b_rot_type = ft_strcpy(*b_rot_type, "rb");
	return (pos);
}
