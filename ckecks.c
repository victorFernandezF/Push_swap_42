/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckecks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:48:56 by victofer          #+#    #+#             */
/*   Updated: 2023/01/17 13:17:39 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	check_bad_input(char *input)
{
	int	i;

	i = -1;
	while (input[++i])
		if (ft_isalpha(input[i]))
			return (TRUE);
	return (FALSE);
}

int	check_int_limit(int cant, char **input)
{
	int	i;

	i = -1;
	while (++i < cant)
		if (ft_atoi(input[i]) > INT_LIMIT
			|| ft_atoi(input[i]) < INT_LIMIT_NEG)
			return (TRUE);
	return (FALSE);
}

int	check_duplicated_numbers(int cant, int *numbers)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cant)
	{
		j = i + 1;
		while (j < cant)
		{
			if (numbers[i] == numbers[j])
				return (TRUE);
			j++;
		}
	}
	return (FALSE);
}
