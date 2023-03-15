/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:33:56 by victofer          #+#    #+#             */
/*   Updated: 2023/03/15 11:04:57 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

/*
*	Checks if the input is bigger or smaller than the integer limits.
*	@param n input number to check.
*/
int	over_the_limit(long long n)
{
	long long	max;
	long long	min;

	max = 2147483647;
	min = -2147483648;
	return (n > max || n < min);
}

int	check_duplicated(int *numbers, int cant, t_stack *stack)
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
				free_stack_and_print_error(stack);
			j++;
		}
	}
	return (0);
}

/*
*	Make some checks to the input.
	If some of them fails, return error and exit the program.
*	@param **argv array whith args.
*	@param *arg char whith one of the arguments.
*	@param start int by whitch it is going to start.
*/
static int	check_args(char **argv, char *arg, int start)
{
	int			i;

	i = 0;
	while (*arg && arg[i] != '\0')
	{
		if (!ft_isdigit(arg[i]) && arg[i] != '-' && arg[i] != '+')
			return (0);
		if ((arg[i] == '-' && arg[i + 1] == '-')
			|| (arg[i] == '+' && arg[i + 1] == '+'))
			return (0);
		if ((ft_isdigit(arg[i])) && (arg[i + 1] == '-' || arg[i + 1] == '+'))
			return (0);
		if ((arg[i] == '-' || arg[i] == '+') && (!ft_isdigit(arg[i + 1])))
			return (0);
		i++;
	}
	if (over_the_limit(ft_special_atoi(arg)))
		return (0);
	while (argv[start] && argv && arg)
	{
		if (string_compare(argv[start], arg))
			return (0);
		start++;
	}
	return (1);
}

/*
*	Make some checks to the input.
	If everything is fine we can continue, if not prints error and exit.
	@param *argc number of arguments.
*	@param **argcv array whith args.
*	@param stack.
*/
t_stack	*parse_args(int argc, char **argv, t_stack *stack)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (check_args(argv, argv[i], i + 1))
			stack->a[i] = ft_special_atoi(argv[i]);
		else
		{
			free_stack(stack);
			print_error();
			exit(1);
		}
		i++;
	}
	return (stack);
}
