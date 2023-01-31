/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:32:37 by victofer          #+#    #+#             */
/*   Updated: 2023/01/31 19:03:31 by victofer         ###   ########.fr       */
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

// INIT STACK DATA (file: src/init_stack_data.c)
void	init_stack(t_stack *stack);

// GET STACK A LENGTH (file: src/main.c)
int		get_stack_a_len(char **nbrs);

// INPUT HANDLER (file: argument/handler/args_handler.c)
int		*fill_array(int cant, char **nbrs);
char	**args_handler(int argc, char **argv);

//	CHECKS BEFORE START (file:checks_files/checks.c)
int		is_sorted(int cant, int *nb);
int		check_bad_input(char *input);
int		check_int_limit(int cant, int *numbers);
int		check_duplicated_numbers(int cant, int *numbers);
int		check_everything(int cant, char **argv, int *numbers);

// ERROR MANAGEEMENT (file: error_management/errors.c)
void	ft_error_free(t_stack stack);
void	ft_error_free_array(int *nb);
void	free_stacks(t_stack stack);
void	ft_error(void);

// FREE STUFF (file: free/free_things.c)
void	free_exit(int *nb);
void	free_nbrs(char **nbrs);

// SORTING FUNCTIONS (file: sorting/sorting_1.c ...)
t_stack	start_sorting(t_stack stack);
t_stack	sort_two_elements(t_stack stack);
t_stack	sort_three_elements(t_stack stack);
t_stack	sort_five_elements(t_stack stack);
t_stack	sort_four_elements(t_stack stack);
int		sort_three_aux(int a, int b, int c);
int		get_min_pos(t_stack stack);
int		get_max_pos(t_stack stack);
t_stack	complex_sort(t_stack stack);

// ARRAY MOVES (file: array_management/array_moves_1.c ...)
t_stack	del_first_and_move_rest_a(t_stack stack);
t_stack	del_last_and_move_rest_a(t_stack stack);
t_stack	add_one_to_first_and_move_rest_a(t_stack stack, int n);
t_stack	add_one_to_last_and_move_rest_a(t_stack stack, int n);
t_stack	del_first_and_move_rest_b(t_stack stack);
t_stack	del_last_and_move_rest_b(t_stack stack);
t_stack	add_one_to_first_and_move_rest_b(t_stack stack, int n);
t_stack	add_one_to_last_and_move_rest_b(t_stack stack, int n);

//	INSTRUCTIONS (file: instructions/intructions_1.c ...)
t_stack	pack_of_instructions(char *pack, t_stack stack);
t_stack	do_operation(char *op, t_stack stack);
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