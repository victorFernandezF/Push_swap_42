/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:41:14 by victofer          #+#    #+#             */
/*   Updated: 2023/03/01 18:23:32 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

// Prints 'Error' and call free_stack function
void	ft_error_free(t_stack stack)
{
	ft_putstr_fd("Error\n", 2);
	free_stacks(stack);
	exit(-1);
}

// Prints 'Error' and free array of ints
void	ft_error_free_array(int *nb)
{
	ft_putstr_fd("Error\n", 2);
	free(nb);
	exit(-1);
}

/*
* Frees every elements from array of arrays and free the array itself 
*/
void	free_nbrs(char **nbrs)
{
	int	i;

	i = -1;
	while (nbrs[++i])
		free(nbrs[i]);
	free(nbrs);
}

// If stack a or stack b are not empty, frees them
void	free_stacks(t_stack stack)
{
	if (stack.a)
		free(stack.a);
	if (stack.b)
		free(stack.b);
	//if (stack.aux)
	//	free(stack.aux);
	//if (stack.temp)
		//free(stack.temp);
}

// Print 'Error' and exit.
void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}
