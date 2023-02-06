/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:48:14 by victofer          #+#    #+#             */
/*   Updated: 2023/02/06 12:13:33 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// Get the length of the numbers array.
int	get_stack_a_len(char **nbrs)
{
	int	cant;

	cant = 0;
	while (nbrs[cant])
		cant++;
	return (cant);
}

// Main function.
int	main(int argc, char **argv)
{
	t_stack	stack;
	char	**nbrs;

	if (argc == 0)
		return (0);
	init_stack(&stack);
	nbrs = args_handler(argc - 1, argv);
	stack.a_len = get_stack_a_len(nbrs);
	stack.a = fill_array(stack.a_len, nbrs);
	free_nbrs(nbrs);
	check_everything(stack.a_len, argv, stack.a);
	stack = start_sorting(stack);
	test_print_stacks(stack);
	free_stacks(stack);
	//atexit(show_leaks);
	return (0);
}
