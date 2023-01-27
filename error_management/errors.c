/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:41:14 by victofer          #+#    #+#             */
/*   Updated: 2023/01/27 13:54:32 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

// Shows 'Error' message and call free function
void	ft_error_free(t_stack stack)
{
	ft_printf("Error\n");
	free_stacks(stack);
	exit(-1);
}

void	ft_error_free_array(int *nb)
{
	ft_printf("Error\n");
	free(nb);
	exit(-1);
}

void	free_nbrs(char **nbrs)
{
	int	i;

	i = -1;
	while (nbrs[++i])
		free(nbrs[i]);
	free(nbrs);
}

void	free_stacks(t_stack stack)
{
	if (stack.a)
		free (stack.a);
	if (stack.b)
		free(stack.b);
}

// Free array and exit
void	free_exit(int *nb)
{
	free(nb);
	exit(0);
}

// Shows error message and exit.
void	ft_error(void)
{
	ft_printf("Error\n");
	exit(-1);
}
