/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:41:13 by victofer          #+#    #+#             */
/*   Updated: 2023/01/19 11:58:56 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "./push_swap.h"

// ----------- E N U M S ---------------
	// Enum with int limits
enum e_int
{
	INT_LIMIT = 2147483647,
	INT_LIMIT_NEG = -2147483648
};

	// enum with TRUE and FALSE (boolean)
enum e_bool
{
	TRUE = 1,
	FALSE = 0
};

// --------- S T R U C T S -------------

typedef struct s_free
{
	int	*new;
	int	*new2;
}		t_free;

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		a_len;
	int		b_len;
	int		a_del;
	int		b_del;
	t_free	free;		
}			t_stack;

#endif