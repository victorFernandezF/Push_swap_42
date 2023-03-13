/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:37:28 by victofer          #+#    #+#             */
/*   Updated: 2023/03/13 19:13:27 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../src/push_swap.h"

/*
*	Prints the word "Error" followed by a new line and
	Exit the program
*/
void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

void	free_stack_and_print_error(t_stack *stack)
{
	ft_putstr_fd("Error\n", 2);
	free_stack(stack);
	exit(-1);
}
