/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:48:14 by victofer          #+#    #+#             */
/*   Updated: 2023/01/30 11:58:56 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// Fill the array with the numbers given by user.
int	*fill_array(int cant, char **nbrs)
{
	int	i;
	int	j;
	int	*numbers;

	numbers = (int *)malloc (cant * sizeof(int));
	if (!numbers)
		exit(-1);
	i = 0;
	j = 0;
	while (i < cant)
	{
		if (check_bad_input(nbrs[j]))
			ft_error_free_array(numbers);
		numbers[i] = ft_atoi(nbrs[i]);
		i++;
	}
	return (numbers);
}

// initialize the stacks values to 0.
static void	init_stack(t_stack *stack)
{
	stack->b = (int *)malloc(1 * sizeof(int));
	stack->a_len = 0;
	stack->b_len = 0;
	stack->moves = 0;
}

int	get_stack_a_len(char **nbrs)
{
	int	cant;

	cant = 0;
	while (nbrs[cant])
		cant++;
	return (cant);
}

char	**args_handler(int argc, char **argv)
{
	int		i;
	char	**nbrs;
	char	*av_str;
	char	*tmp;

	av_str = ft_strdup("");
	i = 0;
	while (++i <= argc)
	{
		tmp = ft_strjoin(av_str, argv[i]);
		free (av_str);
		av_str = tmp;
		tmp = ft_strjoin(av_str, " ");
		free (av_str);
		av_str = tmp;
	}
	nbrs = ft_split(av_str, ' ');
	free (av_str);
	return (nbrs);
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
	//ft_printf(REDY"\nMoves: %i\n"WHITE, stack.moves);
	//atexit(show_leaks);
	return (0);
}
