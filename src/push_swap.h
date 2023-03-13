/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:32:37 by victofer          #+#    #+#             */
/*   Updated: 2023/03/07 11:06:46 by victofer         ###   ########.fr       */
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
//# include "../leaks_checker/include/memory_leaks.h"
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

void	ft_error_free(t_stack *stack);
void	ft_error_free_array(int *nb);
void	free_stacks(t_stack *stack);
void	ft_error(void);
void	free_nbrs(char **nbrs);

// SORTING FUNCTIONS (file: sorting/sorting_1.c ...)

void	start_sorting(t_stack *stack);
void	sort_two_elements(t_stack *stack);
void	sort_three_elements(t_stack *stack);
void	sort_five_elements(t_stack *stack);
void	sort_four_elements(t_stack *stack);
void	medium_sort(t_stack *stack);
void	sort_100_elements(t_stack *stack, int n);
void	sort_500_elements(t_stack *stack);
int		sort_three_aux(int a, int b, int c);
int		get_min_pos(t_stack stack);
void	smart_rotate(int min, t_stack *stack);
int		get_max_pos(t_stack stack);

// ARRAY MOVES (file: array_management/array_moves_1.c ...)

void	del_first_and_move_rest_a(t_stack *stack);
void	del_last_and_move_rest_a(t_stack *stack);
void	add_one_to_first_and_move_rest_a(t_stack *stack, int n);
void	add_one_to_last_and_move_rest_a(t_stack *stack, int n);
void	del_first_and_move_rest_b(t_stack *stack);
void	del_last_and_move_rest_b(t_stack *stack);
void	add_one_to_first_and_move_rest_b(t_stack *stack, int n);
void	add_one_to_last_and_move_rest_b(t_stack *stack, int n);

//	INSTRUCTIONS (file: instructions/intructions_1.c ...)

void	pack_of_instructions(char *pack, t_stack *stack);
void	do_operation(char *op, t_stack *stack);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pb(t_stack *stack);
void	pa(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

void	apply_sa(t_stack *stack);
void	apply_sb(t_stack *stack);
void	apply_ss(t_stack *stack);
void	apply_pb(t_stack *stack);
void	apply_pa(t_stack *stack);
void	apply_ra(t_stack *stack);
void	apply_rb(t_stack *stack);
void	apply_rr(t_stack *stack);
void	apply_rra(t_stack *stack);
void	apply_rrb(t_stack *stack);
void	apply_rrr(t_stack *stack);

// SIMPLIFY STACK (to acept negatives numbers)

void	init_aux_array(t_stack *stack);
void	simplify(t_stack *stack);
void	sort_aux(t_stack *stack);
void	simplify_numbers(t_stack *stack);

// DIVIDE AND RULE

int		get_first(t_stack stack, int f, int l);
int		get_last(t_stack stack, int f, int l);
void	calculate_move(t_stack *stack, int first, int last);
void	chunck(t_stack *stack, int i, int len);
void	sort_stack_b(t_stack *stack, int limit);

// SHOW LEAKS (DELETE BEFORE PRESENT)
void	show_leaks(void);
void	test_print_stacks(t_stack *stack);
void	test(char *msg);
void	move_to_stack_a(t_stack *stack, int limit);

t_moves	*best_way_from_a_to_b(t_stack *stack);
int		ft_strequ(char const *s1, char const *s2);
void	free_moves(t_moves *moves);
char	*ft_strnew(size_t size);
t_moves	*calc_moves_from_a_to_b(t_stack *stack, int pos);
int		find_common(t_moves *moves);
void	place_smallest_first(t_stack *stack);

int		find_place_in_a(int *stack, int len, int elem, char **rot_type);
int		find_place_in_b(int *stack, int len, int elem, char **rot_type);
int		find_a_rot_type(int len, int pos, char **a_rot_type);
int		find_b_rot_type(int len, int pos, char **b_rot_type);

int		ft_strcmp(char const *s1, char const *s2);
char	*ft_strcpy(char *dest, char *src);

void	global_sort(t_stack *stack);
int		find_min_index(int *stack, int len);
int		find_max_index(int *stack, int len);
int		find_min_elem(int *stack, int stack_len);
int		find_max_elem(int *stack, int stack_len);
void	place_smallest_first_a(t_stack *stack);
t_stack	*parse_args(int argc, char **argv, t_stack *stack);
void	init_stack_struct(t_stack *stack, int argc);
char	**ft_strsplit(char const *s, char c);
void	minisort(t_stack *stack);


#endif