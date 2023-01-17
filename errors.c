/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:41:14 by victofer          #+#    #+#             */
/*   Updated: 2023/01/17 13:00:57 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_error_free(int *nb)
{
	ft_printf("Error\n");
	free(nb);
	exit(-1);
}

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(-1);
}
