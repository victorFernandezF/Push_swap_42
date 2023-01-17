/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:32:37 by victofer          #+#    #+#             */
/*   Updated: 2023/01/17 13:41:02 by victofer         ###   ########.fr       */
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

// SHOW LEAKS (DELETE BEFORE PRESENT)
void	show_leaks(void);

#endif