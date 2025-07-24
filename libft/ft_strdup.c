/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:53:59 by alvalien          #+#    #+#             */
/*   Updated: 2024/09/20 11:39:04 by alvalien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*src;
	char	*src1;

	src = malloc((ft_strlen(s) + 1) * 1);
	if (src == NULL)
		return (NULL);
	src1 = src;
	while (*s != '\0')
	{
		*src = *s;
		src++;
		s++;
	}
	*src = '\0';
	return (src1);
}
