/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:28:06 by victofer          #+#    #+#             */
/*   Updated: 2023/02/01 12:54:13 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	min(int *tab, unsigned int len)
{
	int				min;
	unsigned int	i;

	i = 0;
	min = tab[i];
	while (i <= len)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}
