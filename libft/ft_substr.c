/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:46:01 by alvalien          #+#    #+#             */
/*   Updated: 2024/09/19 13:35:58 by alvalien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*solution;
	size_t	i;
	size_t	s_len;

	i = 0;
	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	solution = (char *) malloc((len + 1) * sizeof(char));
	if (solution == NULL)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		solution[i] = s[start + i];
		i++;
	}
	solution[i] = '\0';
	return (solution);
}
