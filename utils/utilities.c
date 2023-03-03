/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:56:05 by victofer          #+#    #+#             */
/*   Updated: 2023/03/03 14:23:25 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../src/push_swap.h"

char	*ft_strcpy(char *dest, char *src)
{
	int				i;

	i = 0;
	while (dest[i++])
		dest[i] = src[i];
	return (dest);
}

int	ft_strequ(char const *s1, char const *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (!ft_strcmp(s1, s2))
		return (1);
	return (0);
}

char	*ft_strnew(size_t size)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (i < size)
		str[i++] = '\0';
	str[i] = '\0';
	return (str);
}

int	find_common(t_moves *moves)
{
	int		common;

	common = 0;
	if ((ft_strequ(moves->a_rot_type, "rra")
			&& (ft_strequ(moves->b_rot_type, "rrb")
			)) || (ft_strequ(moves->a_rot_type, "ra")
			&& (ft_strequ(moves->b_rot_type, "rb"))))
	{
		if (moves->a_moves > moves->b_moves)
			common = moves->b_moves;
		else
			common = moves->a_moves;
		if (common)
		{
			moves->com_rot = ft_strcpy(moves->com_rot, moves->a_rot_type);
			moves->com_rot[ft_strlen(moves->com_rot) - 1] = 'r';
			moves->b_moves -= common;
			moves->a_moves -= common;
		}
	}
	return (common);
}

t_moves	*calc_moves_from_a_to_b(t_stack *stack, int pos)
{
	t_moves	*moves;

	moves = (t_moves *)malloc(sizeof(t_moves));
	moves->a_rot_type = ft_strnew(3);
	moves->b_rot_type = ft_strnew(3);
	moves->com_rot = ft_strnew(3);
	moves->elem = stack->a[pos];
	moves->a_moves = find_a_rot(stack->a_len, pos, &(moves->a_rot_type));
	moves->a_moves = find_place_in_b(stack->b, stack->b_len,
			stack->a[pos], &(moves->b_rot_type));
	moves->common_moves = find_common(moves);
	moves->total = moves->a_moves + moves->b_moves + moves->common_moves + 1;
	return (moves);
}
