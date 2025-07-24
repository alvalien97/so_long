/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:19:37 by alvalien          #+#    #+#             */
/*   Updated: 2024/09/18 16:55:48 by alvalien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t n_elements, size_t size)
{
	size_t	full_size;
	void	*ptr;

	full_size = size * n_elements;
	ptr = malloc(full_size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, full_size);
	return (ptr);
}
