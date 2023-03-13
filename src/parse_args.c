/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:26:09 by iiliuk            #+#    #+#             */
/*   Updated: 2023/03/06 18:31:28 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = (void *)malloc(size);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, 0, size);
	return (mem);
}

void	init_stack_struct(t_stack *stack, int argc)
{
	stack->a = (int *)malloc(sizeof(int) * argc);
	stack->b = (int *)ft_memalloc(sizeof(int) * argc);
	stack->a_len = argc;
	stack->b_len = 0;
	stack->moves = 0;
	stack->print_instr = 1;
}

static int	validate_args(char **argv, char *arg, int start)
{
	int	i;

	i = 0;
	while (*arg && arg[i] != '\0')
	{
		if (!ft_isdigit(arg[i]) && arg[i] != '-')
			return (0);
		i++;
	}
	if (ft_atoi(arg) > INT_MAX || ft_atoi(arg) < INT_MIN)
		return (0);
	while (argv[start] && argv && arg)
	{
		if (ft_strequ(argv[start], arg))
			return (0);
		start++;
	}
	return (1);
}

t_stack		*parse_args(int argc, char **argv, t_stack *stack)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (validate_args(argv, argv[i], i + 1))
			stack->a[i] = ft_atoi(argv[i]);
		else
		{
			free_stacks(stack);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
	return (stack);
}
