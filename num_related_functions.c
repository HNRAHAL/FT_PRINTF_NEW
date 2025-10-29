/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_related_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:21:23 by hrahal            #+#    #+#             */
/*   Updated: 2025/09/22 17:30:48 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == INT_MIN)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		count += ft_putchar('-');
		if (count == -1)
			return (-1);
		n = -n;
	}
	if (n >= 10)
	{
		count += ft_putnbr(n / 10);
		if (count == -1)
			return (-1);
	}
	count += ft_putchar((n % 10) + '0');
	if (count == -1)
		return (-1);
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putnbr_unsigned(n / 10);
		if (count == -1)
			return (-1);
	}
	count += ft_putchar((n % 10) + '0');
	if (count == -1)
		return (-1);
	return (count);
}

int	num_len(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}
