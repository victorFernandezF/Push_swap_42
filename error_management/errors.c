/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:41:14 by victofer          #+#    #+#             */
/*   Updated: 2023/02/06 13:17:10 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

// Shows 'Error' message and call free function
void	ft_error_free(t_stack stack)
{
	ft_putstr_fd("Error\n", 2);
	free_stacks(stack);
	exit(-1);
}

void	ft_error_free_array(int *nb)
{
	ft_putstr_fd("Error\n", 2);
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
		free(stack.a);
	if (stack.b)
		free(stack.b);
}

// Shows error message and exit.
void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}
