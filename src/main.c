/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:32:43 by victofer          #+#    #+#             */
/*   Updated: 2023/03/15 10:31:01 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		aux;

	aux = 0;
	if (argc-- == 1)
		exit(0);
	argv++;
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (argc == 1)
	{
		aux = 1;
		argv = split_args(argv[0], ' ');
		argc = 0;
		while (argv && argv[argc])
			argc++;
		if (argc == 0)
			print_error();
	}
	init_stack_struct(stack, argc);
	stack = parse_args(argc, argv, stack);
	check_duplicated(stack->a, stack->a_len, stack);
	free_argv(argv, aux);
	start_sorting(stack);
	free_stack(stack);
	return (0);
}
