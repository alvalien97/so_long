/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:04:59 by alvalien          #+#    #+#             */
/*   Updated: 2024/10/01 14:25:02 by alvalien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

static char	**free_all(char **lst, int i)
{
	while (i >= 0)
	{
		free(lst[i]);
		i--;
	}
	free(lst);
	return (NULL);
}

static char	*extract_word(const char *s, size_t *word_len, char c)
{
	*word_len = 0;
	while (s[*word_len] != '\0' && s[*word_len] != c)
		(*word_len)++;
	return (ft_substr(s, 0, *word_len));
}

char	**ft_split(char const *s, char c)
{
	int		i;
	size_t	word_len;
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			result[i] = extract_word(s, &word_len, c);
			if (!result[i])
				return (free_all(result, i));
			s += word_len;
			i++;
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}
