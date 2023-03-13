/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:46:13 by victofer          #+#    #+#             */
/*   Updated: 2023/03/09 19:11:54 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

//   S T R U C T U R E S

// Structure with the datas of ths stack.
typedef struct s_stack
{
	int			*a;
	int			*b;
	int			a_len;
	int			b_len;
	int			total_moves;
	int			print_instr;
}				t_stack;

// Structure with the datas of the moves.
typedef struct s_moves
{
	int			element;
	int			a_moves;
	int			b_moves;
	char		*a_rotation_type;
	char		*b_rotation_type;
	char		*common_rotation;
	int			common_moves;
	int			total;
}				t_moves;
#endif