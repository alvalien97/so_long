/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:06:29 by alvalien          #+#    #+#             */
/*   Updated: 2024/09/12 16:53:07 by alvalien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *dest, int c, size_t count)
{
	unsigned char	*s;
	size_t			i;

	i = 0;
	s = (unsigned char *)dest;
	while (i < count)
	{
		s[i] = (unsigned char)c;
		i++;
	}
	return (dest);
}
