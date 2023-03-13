/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:28:43 by victofer          #+#    #+#             */
/*   Updated: 2023/03/13 19:13:57 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "structs.h"
# include <stdio.h>
# include <limits.h>

//    I N S T R U C T I O N S

void		sa(t_stack *stack);
void		sb(t_stack *stack);
void		ss(t_stack *stack);
void		pa(t_stack *stack);
void		pb(t_stack *stack);
void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		rr(t_stack *stack);
void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rrr(t_stack *stack);

//    S O R T I N G

void		start_sorting(t_stack *stack);
void		minisort(t_stack *stack);
void		sort_two_elements(t_stack *stack);
void		sort_three_elements(t_stack *stack);
void		big_sort(t_stack *stack);
t_moves		*cheapest_move_stack_a_to_b(t_stack *stack);
int			find_rotation_a(int len, int pos, char **a_rot_type);
int			find_rotation_b(int len, int pos, char **b_rot_type);
int			find_min_elem(int *stack, int stack_len);
int			find_max_elem(int *stack, int stack_len);
int			find_min_position(int *stack, int len);
void		place_smallest_first_a(t_stack *stack);

//    C H E C K S

int			is_sorted(int *stack, int len);
int			over_the_limit(long long n);
int			check_duplicated(int *numbers, int cant);

//    F R E E 

void		free_stack(t_stack *stack);
void		free_moves(t_moves *moves);
void		free_argv(char **argv);

//    S T A C K   M A N A G E M E N T

void		init_stack_struct(t_stack *stack, int argc);

//    A R G S   M A N A G  E M E N T

t_stack		*parse_args(int argc, char **argv, t_stack *stack);
char		**split_args(char const *s, char c);

//    U T I L I T I E S

int			string_compare(char const *s1, char const *s2);
char		*new_str(size_t size);
int			get_optimus_stack(t_stack *stack);
long long	ft_special_atoi(const char *str);

//    E R R O R S

void		print_error(void);
void		free_stack_and_print_error(t_stack *stack);

#endif