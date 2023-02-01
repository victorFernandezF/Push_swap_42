/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:16:13 by victofer          #+#    #+#             */
/*   Updated: 2023/02/01 13:11:34 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	max(int *tab, unsigned int len)
{
	int				max;
	unsigned int	i;

	i = 0;
	max = tab[i];
	while (i <= len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}
