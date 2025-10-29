/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hex_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:16:56 by hrahal            #+#    #+#             */
/*   Updated: 2025/09/22 17:30:27 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	upper_or_lower_case_check(int rem, char c)
{
	if (c == 'a')
	{
		if (rem >= 10 && rem <= 15)
			return ((rem - 10) + 'a');
		else
			return (rem + '0');
	}
	else if (c == 'A')
	{
		if (rem >= 10 && rem <= 15)
			return ((rem - 10) + 'A');
		else
			return (rem + '0');
	}
	return ('\0');
}

int	return_hexvalue_lower(unsigned int n)
{
	int		rem;
	int		count;
	char	str[30];
	int		i;

	i = 0;
	if (n == 0)
		return (ft_putchar('0'));
	count = 0;
	while (n != 0)
	{
		rem = n % 16;
		n /= 16;
		str[i] = upper_or_lower_case_check(rem, 'a');
		i++;
		count++;
	}
	while (i-- > 0)
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
	}
	return (count);
}

int	return_hexvalue_upper(unsigned int n)
{
	int		rem;
	int		count;
	char	str[30];
	int		i;

	i = 0;
	if (n == 0)
		return (ft_putchar('0'));
	count = 0;
	while (n != 0)
	{
		rem = n % 16;
		n /= 16;
		str[i] = upper_or_lower_case_check(rem, 'A');
		i++;
		count++;
	}
	str[i] = '\0';
	while (i-- > 0)
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
	}
	return (count);
}

int	return_address_and_convert_to_hex(void *address)
{
	int			rem;
	int			i;
	int			count;
	char		str[30];
	uintptr_t	n_address;

	count = 0;
	n_address = (uintptr_t)address;
	if (n_address == 0)
		return (ft_putstr("0x0"));
	i = 0;
	count += ft_putstr("0x");
	if (count == -1)
		return (-1);
	while (n_address != 0)
	{
		rem = n_address % 16;
		n_address /= 16;
		str[i++] = upper_or_lower_case_check(rem, 'a');
		count++;
	}
	while (i-- > 0)
		write(1, &str[i], 1);
	return (count);
}
