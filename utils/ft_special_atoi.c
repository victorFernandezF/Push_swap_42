/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_atoi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:29:05 by victofer          #+#    #+#             */
/*   Updated: 2023/03/13 18:49:59 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

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

/*
*	This functions is like the original atoi but in this case if
	the given number is "-0" or "+0" it returns a number bigger
	than the max_int. so it will cause a controled error. This is becouse
	zero can not be negative or positive so if an argument is one of this
	will be considered an error.
*	@param str String to convert to int. 
*/
long long	ft_special_atoi(const char *str)
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
