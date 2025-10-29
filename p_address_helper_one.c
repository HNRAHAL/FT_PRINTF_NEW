/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_address_helper_one.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 12:00:45 by hrahal            #+#    #+#             */
/*   Updated: 2025/10/29 15:52:05 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	p_else_case(char *str, int w_nbr, int p_nbr)
{
	int	count;
	int	len;

	count = 0;
	len = b_ft_strlen(str);
	while (w_nbr-- > 0)
		count += b_ft_putchar(' ');
	count += b_ft_putstr("0x");
	while (p_nbr-- > 0)
		count += b_ft_putchar('0');
	while (len-- > 0)
		count += write(1, &str[len], 1);
	return (count);
}

int	p_else_case2(char *str, int len, void *ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		count += b_ft_putstr("0x0");
	else
		count += b_ft_putstr("0x");
	while (len-- > 0)
		count += write(1, &str[len], 1);
	return (count);
}

int	p_number_edge_case1(void *ptr, int w_nbr, int len)
{
	int		count;
	char	*str;

	count = 0;
	str = b_return_address_and_convert_to_hex(ptr);
	if (ptr == 0)
		count += b_ft_putstr("0x0");
	else
		count += b_ft_putstr("0x");
	while (len-- > 0)
		count += write(1, &str[len], 1);
	while (w_nbr-- > 0)
		count += b_ft_putchar(' ');
	free(str);
	return (count);
}
