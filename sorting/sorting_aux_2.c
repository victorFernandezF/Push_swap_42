/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_aux_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:05:52 by marvin            #+#    #+#             */
/*   Updated: 2023/01/28 13:05:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

t_stack   rra_rra_pa_ra_ra(t_stack stack)
{
    stack = rra(stack);
    stack = rra(stack);
    stack = pa(stack);
    stack = ra(stack);
    stack = ra(stack);
    return (stack);
}