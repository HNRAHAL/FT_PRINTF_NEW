/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 11:12:34 by hrahal            #+#    #+#             */
/*   Updated: 2025/10/26 11:44:33 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	case_check(const char *fmt, va_list list)
{
	if (*fmt == 'c')
		return (ft_putchar(va_arg(list, int)));
	else if (*fmt == 's')
		return (ft_putstr(va_arg(list, char *)));
	else if (*fmt == 'd' || *fmt == 'i')
		return (ft_putnbr(va_arg(list, int)));
	else if (*fmt == 'u')
		return (ft_putnbr_unsigned(va_arg(list, unsigned int)));
	else if (*fmt == 'x')
		return (return_hexvalue_lower(va_arg(list, unsigned int)));
	else if (*fmt == 'X')
		return (return_hexvalue_upper(va_arg(list, unsigned int)));
	else if (*fmt == 'p')
		return (return_address_and_convert_to_hex(va_arg(list, void *)));
	else if (*fmt == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *fmt, ...)
{
	int		count;
	va_list	list;

	va_start(list, fmt);
	count = 0;
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1))
		{
			fmt++;
			count += case_check(fmt, list);
			if (count == -1)
				return (-1);
			fmt++;
		}
		else
		{
			count += write(1, fmt, 1);
			if (count == -1)
				return (-1);
			fmt++;
		}
	}
	va_end(list);
	return (count);
}
