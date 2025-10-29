/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 12:03:19 by hrahal            #+#    #+#             */
/*   Updated: 2025/10/28 09:47:26 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	b_ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	b_ft_putstr(char *s)
{
	int	count;
	int	res;

	count = 0;
	res = 0;
	if (!s)
		s = "(null)";
	while (*s)
	{
		res = write(1, s++, 1);
		if (res == -1)
			return (-1);
		count += res;
	}
	return (count);
}

size_t	b_ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
