/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:51:09 by alvalien          #+#    #+#             */
/*   Updated: 2024/09/20 12:27:38 by alvalien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	a;

	a = (char) c;
	while (*s != '\0')
	{
		if (*s == a)
			return ((char *) s);
		s++;
	}
	if (a == '\0')
		return ((char *) s);
	return (NULL);
}
