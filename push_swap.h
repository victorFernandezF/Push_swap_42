/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:32:37 by victofer          #+#    #+#             */
/*   Updated: 2023/01/18 18:15:26 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"
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
void	ft_error_free(int *nb);
void	ft_error(void);
void	free_exit(int *nb);

// ORDERING
void	start_ordering(t_stack stack);
t_stack	order_two_elements(t_stack stack);

//	INSTRUCTIONS
t_stack	sa(t_stack stack);
t_stack	sb(t_stack stack);
t_stack	ss(t_stack stack);

// SHOW LEAKS (DELETE BEFORE PRESENT)
void	show_leaks(void);

#endif