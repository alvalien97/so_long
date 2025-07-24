/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:57:29 by alvalien          #+#    #+#             */
/*   Updated: 2024/09/17 18:14:44 by alvalien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*c1;
	const unsigned char	*c2;

	c1 = (const unsigned char *) s1;
	c2 = (const unsigned char *) s2;
	while (n > 0)
	{
		if (*c1 != *c2)
			return (*c1 - *c2);
		n--;
		c1++;
		c2++;
	}
	return (0);
}
