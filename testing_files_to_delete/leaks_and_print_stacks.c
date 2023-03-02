/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_and_print_stacks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:12:09 by victofer          #+#    #+#             */
/*   Updated: 2023/03/02 18:50:54 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

// Show leakys (need to be deleted)
void	show_leaks(void)
{
	system("leaks -q push_swap");
}

static void	print_rest(t_stack stack)
{
	int		i;
	int		limit;

	limit = 20;
	i = -1;
	ft_printf(GREEN"\n ▫️ Stack_aux "WHITE);
	i = -1;
	// AUX
	while (++i < stack.aux_len)
	{
		if (stack.aux[i] <= limit)
			ft_printf(YELLOW"%i "WHITE, stack.aux[i]);
		else
			printf("%i ", stack.aux[i]);
	}
	printf("\n"BG_BLACK);
	ft_printf(GREEN"\n ▫️ Stack_temp "WHITE);
	i = -1;
	// TEMP
	while (++i < stack.aux_len)
	{
		if (stack.temp[i] <= limit)
			printf(YELLOW"%i "WHITE, stack.temp[i]);
		else
			printf("%i ", stack.temp[i]);
	}
	printf("\n"BG_BLACK);
}

// TEMPORAL FUNCTION JUST TO TEST INSTRUCTION (DELETE BEFORE PRESENT)
void	test_print_stacks(t_stack stack)
{
	int		i;
	int		limit;
	int		more;

	more = 0;
	limit = 0;
	ft_printf("\n 🔴 ---- TESTING PRINT ---- 🔴");
	i = -1;
	ft_printf(GREEN"\n ▫️ Stack_a "WHITE);
	// STACK A
	while (++i < stack.a_len)
	{
		if (stack.a[i] % 100 == 0)
			ft_printf(GREEN"%i "WHITE, stack.a[i]);
		else if (stack.a[i] <= limit)
			ft_printf(YELLOW"%i "WHITE, stack.a[i]);
		else
			ft_printf("%i ", stack.a[i]);
	}
	ft_printf(" \n");
	ft_printf(GREEN"\n ▫️ Stack_b "WHITE);
	i = -1;
	// STACK B
	while (++i < stack.b_len)
	{
		if (stack.b[i] <= limit)
			ft_printf(YELLOW"%i "WHITE, stack.b[i]);
		else
			printf("%i ", stack.b[i]);
	}
	if (more)		
		print_rest(stack);
	printf("\n"BG_BLACK);
	ft_printf(REDY"\n    Moves: %i\n"WHITE BG_BLACK, stack.moves);
}

void	test(char *msg)
{
	printf("\n%s\n", msg);
}

