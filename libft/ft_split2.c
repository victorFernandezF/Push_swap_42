/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:43:24 by victofer          #+#    #+#             */
/*   Updated: 2023/03/06 18:45:39 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int	count_words(char *str)
{
	int	cont;

	cont = 0;
	while (*str)
	{
		while (*str && is_space(*str))
			str++;
		if (*str && !is_space(*str))
		{
			cont++;
			while (*str && !is_space(*str))
				str++;
		}
	}
	return (cont);
}

char	*write_word(char *str)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && !is_space(str[i]))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !is_space(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split2(char *str)
{
	int		i;
	char	**split;

	i = 0;
	split = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
	while (*str)
	{
		while (*str && is_space(*str))
		str++;
		if (*str && !is_space(*str))
		{
			split[i] = write_word(str);
			i++;
			while (*str && !is_space(*str))
				str++;
		}
	}
	split[i] = NULL;
	return (split);
}
