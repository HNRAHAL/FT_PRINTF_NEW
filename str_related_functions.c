/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_related_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:25:10 by hrahal            #+#    #+#             */
/*   Updated: 2025/09/22 15:29:27 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;
	int	count;
	int	res;

	count = 0;
	res = 0;
	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		res = write(1, &s[i], 1);
		if (res == -1)
			return (-1);
		count += res;
		i++;
	}
	return (count);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
