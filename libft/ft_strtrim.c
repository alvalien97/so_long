/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:33:37 by alvalien          #+#    #+#             */
/*   Updated: 2024/09/20 15:54:51 by alvalien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_checkchar(char s1, const char *set)
{
	while (*set != '\0')
	{
		if (s1 == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	s1_start;
	size_t	s1_end;
	size_t	len;

	if (!set || !s1)
		return (NULL);
	s1_start = 0;
	s1_end = ft_strlen(s1);
	while (s1[s1_start] != '\0' && ft_checkchar(s1[s1_start], set))
		s1_start++;
	while (s1_end > s1_start && ft_checkchar(s1[s1_end - 1], set))
		s1_end--;
	len = s1_end - s1_start;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1 + s1_start, len + 1);
	result[len] = '\0';
	return (result);
}
