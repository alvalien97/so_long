/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 20:44:20 by alvalien          #+#    #+#             */
/*   Updated: 2024/10/11 20:44:23 by alvalien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	char	a;

	a = (char)c;
	while (*s)
	{
		if (*s == a)
			return (s);
		s++;
	}
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	i;

	if (!nmemb || !size)
		return (NULL);
	str = malloc((nmemb * size));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	s1_len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	s1_len = ft_strlen(s1);
	str = malloc(((s1_len + ft_strlen(s2)) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	len;
	size_t	i;

	len = ft_strlen((char *)s1);
	copy = malloc(len + 1);
	if (copy == NULL)
	{
		free(copy);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[len] = '\0';
	return (copy);
}
