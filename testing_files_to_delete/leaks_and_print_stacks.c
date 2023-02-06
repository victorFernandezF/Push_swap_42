/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_and_print_stacks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:12:09 by victofer          #+#    #+#             */
/*   Updated: 2023/02/06 13:39:44 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

// Show leakys (need to be deleted)
void	show_leaks(void)
{
	system("leaks -q push_swap");
}

// TEMPORAL FUNCTION JUST TO TEST INSTRUCTION (DELETE BEFORE PRESENT)
void	test_print_stacks(t_stack stack)
{
	int		i;

	ft_printf("\n 🔴 ---- TESTING PRINT ---- 🔴");
	i = -1;
	ft_printf("\n    Stack_a ");
	while (++i < stack.a_len)
		ft_printf("%i ", stack.a[i]);
	ft_printf("\n    Stack_b ");
	i = -1;
	while (++i < stack.b_len)
		printf("%i ", stack.b[i]);
	printf("\n"BG_BLACK);
	ft_printf(REDY"\n    Moves: %i\n"WHITE BG_BLACK, stack.moves);
}
