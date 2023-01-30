/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:09:54 by victofer          #+#    #+#             */
/*   Updated: 2023/01/30 12:24:12 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

// Fill the array with the numbers given by user.
int	*fill_array(int cant, char **nbrs)
{
	int	i;
	int	j;
	int	*numbers;

	numbers = (int *)malloc(cant * sizeof(int));
	if (!numbers)
		exit(-1);
	i = 0;
	j = 0;
	while (i < cant)
	{
		if (check_bad_input(nbrs[j]))
			ft_error_free_array(numbers);
		numbers[i] = ft_atoi(nbrs[i]);
		i++;
	}
	return (numbers);
}

char	**args_handler(int argc, char **argv)
{
	int		i;
	char	**nbrs;
	char	*av_str;
	char	*tmp;

	av_str = ft_strdup("");
	i = 0;
	while (++i <= argc)
	{
		tmp = ft_strjoin(av_str, argv[i]);
		free (av_str);
		av_str = tmp;
		tmp = ft_strjoin(av_str, " ");
		free (av_str);
		av_str = tmp;
	}
	nbrs = ft_split(av_str, ' ');
	free (av_str);
	return (nbrs);
}
