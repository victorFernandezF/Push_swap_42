/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:41:13 by victofer          #+#    #+#             */
/*   Updated: 2023/02/06 11:19:44 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "./push_swap.h"

// ---------- C O L O R S --------------

# define RED  "\x1B[31m"
# define GREEN  "\x1B[32m"
# define YELLOW  "\x1B[33m"
# define BG_YELLOW  "\x1b[103m"
# define BLUE  "\x1B[34m"
# define WHITE  "\x1B[37m"
# define BG_WHITE  "\x1b[47m"
# define MAG  "\x1B[35m"
# define REDY  "\x1b[91m"
# define BG_BLACK "\x1b[40m"

// ---- I N S T R U C T I O N S --------

# define PA  "pa"
# define PB  "pb"
# define SA  "sa"
# define SB  "sb"
# define SS  "ss"
# define RA  "ra"
# define RB  "rb"
# define RR  "rr"
# define RRA  "rra"
# define RRB  "rrb"
# define RRR  "rrr"

// ----------- E N U M S ---------------
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
	char	*tmp;
	int		a_len;
	int		b_len;
	int		moves;
	int		pb_count;
	t_free	free;		
}			t_stack;

#endif