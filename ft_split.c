/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:45:56 by logkoege          #+#    #+#             */
/*   Updated: 2024/11/07 18:04:45 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	count_words(const char *str, char c)
{
	int		count;
	int		in_word;
	int		i;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			in_word = 0;
		}
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static const char	*next_word_start(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == c)
	{
		i++;
	}
	return (&str[i]);
}

static int	word_length(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	**ft_split(const char *str, char c)
{
	int		j;
	int		word_count;
	int		i;
	int		word_len;
	char	**result;

	word_count = count_words(str, c);
	i = 0;
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	while (*str && i < word_count)
	{
		str = next_word_start(str, c);
		word_len = word_length(str, c);
		result[i] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!result[i])
			return (NULL);
		j = 0;
		while (j < word_len)
			result[i][j++] = *str++;
		result[i++][word_len] = '\0';
	}
	result[word_count] = NULL;
	return (result);
}
