/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:48:14 by victofer          #+#    #+#             */
/*   Updated: 2023/01/23 19:04:12 by victofer         ###   ########.fr       */
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
	stack.a_del = 0;
	stack.b_del = 0;
	return (stack);
}

// Function that evaluate how to aproach the ordering.
t_stack	start_ordering(t_stack stack)
{
	if (stack.a_len == 2)
		stack = order_two_elements(stack);
	if (stack.a_len == 3)
		stack = order_three_elements(stack);
	if (stack.a_len == 5)
		stack = order_five_elements(stack);
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
	stack = start_ordering(stack);
	test_print_stacks(stack);
	free_stacks(stack);
	return (0);
}
