/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_and_print_stacks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:12:09 by victofer          #+#    #+#             */
/*   Updated: 2023/01/20 13:45:49 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	show_leaks(void)
{
	system("leaks -q push_swap");
}

// TEMPORAL FUNCTION JUST TO TEST INSTRUCTION (DELETE BEFORE PRESENT)
void	test_print_stacks(t_stack stack)
{
	int		i;
	printf("\n---- TESTING PRINT ----");
	i = -1;
	printf("\n    stack_a ");
	while (++i < stack.a_len)
		printf("%i ", stack.a[i]);
	printf("\n    stack_b ");
	i = -1;
	while (++i < stack.b_len)
		printf("%i ", stack.b[i]);
}
