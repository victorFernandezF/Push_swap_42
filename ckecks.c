/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckecks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:48:56 by victofer          #+#    #+#             */
/*   Updated: 2023/01/18 12:57:28 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// Checks if any value from args isn't numeric.
int	check_bad_input(char *input)
{
	int	i;

	i = -1;
	while (input[++i])
		if (ft_isalpha(input[i]))
			return (TRUE);
	return (FALSE);
}

// Checks if any numbers is bigger than int limit. (NOT WOKING YET)
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

// Checks if any of the numbers is duplicated. 
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

// Checks if user inputs the numbers already sorted.
int	is_sorted(int cant, int *nb)
{
	int	i;

	i = 0;
	while (i < cant - 1)
	{
		if (nb[i] > nb[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

// Call the checker functions and return error if needed.
int	check_everything(int cant, char **argv, int *numbers)
{
	(void)argv;
	if (check_duplicated_numbers(cant, numbers))
		ft_error_free(numbers);
	if (is_sorted(cant, numbers))
	{
		ft_printf("Sorted\n");
		free_exit(numbers);
	}	
	return (0);
}