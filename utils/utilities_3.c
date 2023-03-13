/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:12:28 by victofer          #+#    #+#             */
/*   Updated: 2023/03/06 11:14:35 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../src/push_swap.h"

char	*ft_strcpy(char *dest, char *src)
{
	int				i;

	i = 0;
	while (dest[i++])
		dest[i] = src[i];
	return (dest);
}

int	ft_strequ(char const *s1, char const *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (!ft_strcmp(s1, s2))
		return (1);
	return (0);
}

char	*ft_strnew(size_t size)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (i < size)
		str[i++] = '\0';
	str[i] = '\0';
	return (str);
}