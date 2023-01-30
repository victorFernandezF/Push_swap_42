/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:32:01 by victofer          #+#    #+#             */
/*   Updated: 2023/01/23 19:17:04 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	sort_three_aux(int a, int b, int c)
{
	if ((a < b) && (b > c) && (c < a))
		return (1);
	if ((a > b) && (b > c) && (c < a))
		return (2);
	if ((a > b) && (b < c) && (c > a))
		return (3);
	if ((a < b) && (b > c) && (c > a))
		return (4);
	if ((a > b) && (b < c) && (c < a))
		return (5);
	return (FALSE);
}

int	sort_five_aux(int n, t_stack stack)
{	
	if (n > stack.a[0] && n < stack.a[1])
		return (2);
	if (n > stack.a[1] && n < stack.a[2])
		return (3);
	if (n > stack.a[2] && n < stack.a[3])
		return (4);
	if (n > stack.a[3])
		return (5);
	if (n < stack.a[0])
		return (1);
	return (0);
}
