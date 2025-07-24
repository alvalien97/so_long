/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:18:57 by alvalien          #+#    #+#             */
/*   Updated: 2024/09/17 19:19:17 by alvalien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	a;
	char	*src;

	src = NULL;
	a = (char) c;
	while (*s != '\0')
	{
		if (*s == a)
			src = (char *) s;
		s++;
	}
	if (a == '\0')
		return ((char *) s);
	return (src);
}
