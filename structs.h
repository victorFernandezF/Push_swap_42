/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:41:13 by victofer          #+#    #+#             */
/*   Updated: 2023/01/17 13:52:55 by victofer         ###   ########.fr       */
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

typedef struct s_stack
{
	int	*numbers;
	int	cant;	
}		t_stack;

#endif