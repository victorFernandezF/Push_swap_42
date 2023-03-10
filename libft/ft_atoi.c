/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:48:27 by victofer          #+#    #+#             */
/*   Updated: 2023/03/09 12:39:30 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	ft_is_sign(char n)
{
	if (n == '+' || n == '-')
		return (1);
	return (0);
}

static int	ft_is_nbr(char n)
{
	if (n >= 48 && n <= 57)
		return (1);
	return (0);
}

long long	ft_atoi(const char *str)
{
	long long	result;
	int			sign;
	long long	i;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (ft_is_sign(str[i]))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_is_nbr(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}
