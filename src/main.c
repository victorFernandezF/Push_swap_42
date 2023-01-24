/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:48:14 by victofer          #+#    #+#             */
/*   Updated: 2023/01/24 11:33:37 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// Fill the array with the numbers given by user.
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
			ft_error_free_array(numbers);
		numbers[i++] = ft_atoi(nb[j]);
		j++;
	}
	return (numbers);
}

// initialize the stacks values to 0.
t_stack	init_stacks(t_stack stack)
{
	stack.b_len = 0;
	stack.moves = 0;
	return (stack);
}

// Function that evaluate how to aproach the sorting.
t_stack	start_sorting(t_stack stack)
{
	if (stack.a_len == 2)
		stack = sort_two_elements(stack);
	if (stack.a_len == 3)
		stack = sort_three_elements(stack);
	if (stack.a_len == 4)
		stack = sort_four_elements(stack);
	if (stack.a_len == 5)
		stack = sort_five_elements(stack);
	//if (stack.a_len > 5 && stack.a_len <= 100)
		//stack = complex_sort(stack);
	return (stack);
}

// Main function.
int	main(int argc, char **argv)
{
	t_stack	stack;

	//atexit(show_leaks);
	if (argc == 0)
		return (0);
	stack.a_len = argc - 1;
	stack = init_stacks(stack);
	stack.a = fill_array(stack.a_len, argv);
	check_everything(stack.a_len, argv, stack.a);
	stack = start_sorting(stack);
	//test_print_stacks(stack);
	ft_printf(REDY"\nMoves: %i\n"WHITE, stack.moves);
	free_stacks(stack);
	return (0);
}
