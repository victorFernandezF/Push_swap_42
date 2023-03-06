/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:48:14 by victofer          #+#    #+#             */
/*   Updated: 2023/03/06 19:17:31 by victofer         ###   ########.fr       */
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
	t_stack	*stack;

	if (argc-- == 1)
		exit(0);
	else
		argv++;
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (argc == 1)
	{
		argv = ft_strsplit(argv[0], ' ');
		argc = 0;
		while (argv && argv[argc])
			argc++;
		if (argc == 0)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
	}
	init_stack_struct(stack, argc);
	stack = parse_args(argc, argv, stack);
	start_sorting(stack);
	test_print_stacks(stack);
	free_stacks(stack);
	//atexit(show_leaks);
	return (0);
}
