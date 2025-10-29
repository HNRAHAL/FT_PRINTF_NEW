/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:23:30 by hrahal            #+#    #+#             */
/*   Updated: 2025/09/22 13:35:24 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *fmt, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
size_t	ft_strlen(const char *str);
int		ft_putnbr(int n);
int		ft_putnbr_unsigned(unsigned int n);
int		return_hexvalue_lower(unsigned int n);
int		return_hexvalue_upper(unsigned int n);
int		return_address_and_convert_to_hex(void *address);
int		num_len(int n);

#endif