/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:48:14 by victofer          #+#    #+#             */
/*   Updated: 2023/01/17 13:57:12 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	*fill_array(int cant, char **nb)
{
	int	i;
	int	j;
	int	*numbers;

	numbers = (int *)malloc (cant * sizeof(int));
	if (!numbers)
		return (NULL);
	i = 0;
	j = 1;
	while (i < cant)
	{
		if (check_bad_input(nb[j]))
			ft_error_free(numbers);
		numbers[i++] = ft_atoi(nb[j]);
		j++;
	}
	return (numbers);
}

int	main(int argc, char **argv)
{
	int		*numbers;
	t_stack	stack_a;

	atexit(show_leaks);
	if (argc == 0)
		return (0);
	stack_a.cant = argc - 1;
	stack_a.numbers = fill_array(stack_a.cant, argv);
	check_everything(stack_a.cant, argv, stack_a.numbers);
	free (numbers);
	return (0);
}
