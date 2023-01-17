/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:32:37 by victofer          #+#    #+#             */
/*   Updated: 2023/01/17 13:12:20 by victofer         ###   ########.fr       */
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

enum e_int
{
	INT_LIMIT = 2147483647,
	INT_LIMIT_NEG = -2147483648
};

enum e_bool
{
	TRUE = 1,
	FALSE = 0
};

void	show_leaks(void);
int		is_sorted(int cant, int *nb);
int		*fill_array(int cant, char **nb);
void	ft_error_free(int *nb);
int		check_bad_input(char *input);
int		check_int_limit(int cant, char **input);
void	ft_error(void);
int		check_duplicated_numbers(int cant, int *numbers);

#endif