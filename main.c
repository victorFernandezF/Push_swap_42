/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:48:14 by victofer          #+#    #+#             */
/*   Updated: 2023/01/19 11:55:43 by victofer         ###   ########.fr       */
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

void	start_ordering(t_stack stack)
{
	if (stack.a_len == 2)
		stack = order_two_elements(stack);
}

t_stack	init_stacks(t_stack stack)
{
	stack.b_len = 0;
	stack.a_del = 0;
	stack.b_del = 0;
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	int		i;

	i = -1;
	atexit(show_leaks);
	if (argc == 0)
		return (0);
	stack.a_len = argc - 1;
	stack = init_stacks(stack);
	stack.a = fill_array(stack.a_len, argv);
	check_everything(stack.a_len, argv, stack.a);
	//stack = pb(stack);
	stack = pb(stack);
	printf("\nstack b %i\nstack_a ", stack.b[0]);
	while (++i < stack.a_len)
		printf("%i ", stack.a[i]);
	//start_ordering(stack);
	free (stack.a);
	
	return (0);
}
