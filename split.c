/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:40:13 by rkrechun          #+#    #+#             */
/*   Updated: 2024/02/22 16:53:08 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	words(char *str, char separator)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == separator)
			str++;
		while (*str != separator && *str)
		{
			if (!inside_word)
			{
				count++;
				inside_word = true;
			}
			str++;
		}
	}
	return (count);
}

static char	*ft_next_value(char *str, char separator)
{
	static int	index = 0;
	char		*next;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[index] == separator)
		index++;
	while ((str[index + len] != separator) && str[index + len])
		len++;
	next = malloc((len * sizeof(char)) + 1);
	if (!next)
		return (NULL);
	while ((str[index] != separator) && str[index])
		next[i++] = str[index++];
	next[i] = '\0';
	return (next);
}

char	**split(char *str, char separator)
{
	char	**final;
	int		word;
	int		i;

	i = 0;
	word = words(str, separator);
	final = malloc(sizeof(char *) * (size_t)(word + 2));
	if (!final)
		return (NULL);
	while (word-- >= 0)
	{
		if (i == 0)
		{
			final[i] = malloc(sizeof(char));
			if (final[i] == NULL)
				return (NULL);
			final[i++][0] = '\0';
			continue ;
		}
		final[i++] = ft_next_value(str, separator);
	}
	final[i] = NULL;
	return (final);
}
