/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:48:14 by victofer          #+#    #+#             */
/*   Updated: 2023/01/17 13:18:45 by victofer         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int	*numbers;

	if (argc == 0)
		return (0);
	numbers = fill_array(argc -1, argv);
	if (is_sorted(argc -1, numbers))
		ft_printf("Sorted.\n");
	if (check_duplicated_numbers(argc - 1, numbers))
		ft_error_free(numbers);
	free (numbers);
	atexit(show_leaks);
	return (0);
}
