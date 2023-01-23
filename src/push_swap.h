/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:32:37 by victofer          #+#    #+#             */
/*   Updated: 2023/01/23 19:08:00 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"
# include "./structs.h"

//	CHECKS BEFORE START
t_stack	init_stacks(t_stack stack);
int		is_sorted(int cant, int *nb);
int		check_bad_input(char *input);
int		check_int_limit(int cant, char **input);
int		check_duplicated_numbers(int cant, int *numbers);
int		check_everything(int cant, char **argv, int *numbers);

// INPUT MANAGEMENT
int		*fill_array(int cant, char **nb);

// ERROR MANAGEEMENT
void	ft_error_free(t_stack stack);
void	ft_error_free_array(int *nb);
void	free_stacks(t_stack stack);
void	ft_error(void);
void	free_exit(int *nb);

// ORDERING
t_stack	start_ordering(t_stack stack);
t_stack	order_two_elements(t_stack stack);
t_stack	order_three_elements(t_stack stack);
t_stack	order_five_elements(t_stack stack);
int		order_five_aux(int n, t_stack stack);
int		order_three_aux(int a, int b, int c);
t_stack	rra_pa_ra_ra(t_stack stack);
t_stack	rra_pa_ra(t_stack stack);
t_stack	ra_pa_rra(t_stack stack);

// ARRAY_MANAGEMENT
t_stack	del_first_and_move_rest_a(t_stack stack);
t_stack	del_last_and_move_rest_a(t_stack stack);
t_stack	add_one_to_first_and_move_rest_a(t_stack stack, int n);
t_stack	add_one_to_last_and_move_rest_a(t_stack stack, int n);
t_stack	del_first_and_move_rest_b(t_stack stack);
t_stack	del_last_and_move_rest_b(t_stack stack);
t_stack	add_one_to_first_and_move_rest_b(t_stack stack, int n);
t_stack	add_one_to_last_and_move_rest_b(t_stack stack, int n);

//	INSTRUCTIONS
t_stack	sa(t_stack stack);
t_stack	sb(t_stack stack);
t_stack	ss(t_stack stack);
t_stack	pb(t_stack stack);
t_stack	pa(t_stack stack);
t_stack	ra(t_stack stack);
t_stack	rb(t_stack stack);
t_stack	rr(t_stack stack);
t_stack	rra(t_stack stack);
t_stack	rrb(t_stack stack);
t_stack	rrr(t_stack stack);

// SHOW LEAKS (DELETE BEFORE PRESENT)
void	show_leaks(void);
void	test_print_stacks(t_stack stack);

#endif