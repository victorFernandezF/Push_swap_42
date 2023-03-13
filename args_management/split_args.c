/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:14:33 by victofer          #+#    #+#             */
/*   Updated: 2023/03/09 18:55:22 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

static int	count_words(const char *s, char c)
{
	int	flag;
	int	word;

	flag = 0;
	word = 0;
	if (!s || !c)
		return (0);
	while (*s)
	{
		if (*s == c && flag == 1)
			flag = 0;
		if (*s != c && flag == 0)
		{
			flag = 1;
			word++;
		}
		s++;
	}
	return (word);
}

static int	word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

/*
*	If given argument has more than 1 character split it by spaces and
	returns an array of strings.
*	@param *s string to split.
*	@param c char used as separator.
*/
char	**split_args(char const *s, char c)
{
	int		i;
	int		nb_words;
	char	**array;

	i = 0;
	nb_words = count_words((const char *)s, c);
	array = (char **)malloc(sizeof(*array) * (nb_words + 1));
	if (array == NULL)
		return (NULL);
	while (nb_words--)
	{
		while (*s == c && *s != '\0')
			s++;
		array[i] = ft_substr((const char *)s, 0, word_len((const char *)s, c));
		s = s + word_len((const char *)s, c);
		i++;
	}
	array[i] = NULL;
	return (array);
}
