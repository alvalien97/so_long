/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:50:39 by alvalien          #+#    #+#             */
/*   Updated: 2024/09/24 16:59:55 by alvalien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*zero(int n)
{
	char	*integer;

	if (n == 0)
	{
		integer = malloc(2);
		if (integer == NULL)
			return (NULL);
		integer[0] = '0';
		integer[1] = '\0';
		return (integer);
	}
	return (NULL);
}

static char	*max_min(int n)
{
	char	*integer;

	if (n == -2147483648)
	{
		integer = malloc(12);
		if (integer == NULL)
			return (NULL);
		integer[0] = '-';
		integer[1] = '2';
		integer[2] = '1';
		integer[3] = '4';
		integer[4] = '7';
		integer[5] = '4';
		integer[6] = '8';
		integer[7] = '3';
		integer[8] = '6';
		integer[9] = '4';
		integer[10] = '8';
		integer[11] = '\0';
		return (integer);
	}
	return (NULL);
}

static char	*itoa_operation(int n, int sign)
{
	int		num;
	int		num_len;
	char	*integer;

	num_len = 0;
	num = n;
	while (num != 0)
	{
		num_len++;
		num /= 10;
	}
	integer = malloc(num_len + sign + 1);
	if (integer == NULL)
		return (NULL);
	integer[num_len + sign] = '\0';
	while (num_len > 0)
	{
		integer[num_len + sign - 1] = (n % 10) + '0';
		num_len--;
		n = n / 10;
	}
	if (sign)
		integer[0] = '-';
	return (integer);
}

char	*ft_itoa(int n)
{
	int	sign;
	int	number;

	if (n == -2147483648)
		return (max_min(n));
	if (n == 0)
		return (zero(n));
	sign = 0;
	number = n;
	if (n < 0)
		sign = 1;
	if (sign == 1)
		number = -n;
	return (itoa_operation(number, sign));
}
