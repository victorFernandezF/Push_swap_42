/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:12:28 by victofer          #+#    #+#             */
/*   Updated: 2023/03/10 10:28:20 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../src/push_swap.h"

/*
*	Returns the optimus number to split the stack depending on
	its size.
*	@param *stack
*/
int	get_optimus_stack(t_stack *stack)
{
	if (stack->a_len > 200)
		return (50);
	else
		return (2);
}

/*
*	Compares two srings. Returns 1 if they are equals and 0 if not
*	@param *s1 First string.
*	@param *s1 Second string.
*/
int	string_compare(char const *s1, char const *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (!ft_strcmp(s1, s2))
		return (1);
	return (0);
}

/*
*	Creates a new string of the given size and fills it with '\0'
*	@param size size of the string to return.
*/
char	*new_str(size_t size)
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
