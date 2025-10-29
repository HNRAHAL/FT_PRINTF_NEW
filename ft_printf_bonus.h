/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 11:47:31 by hrahal            #+#    #+#             */
/*   Updated: 2025/10/29 20:30:50 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
typedef struct s_conversion
{
	int w_nbr;
	int p_nbr;
	int i;
}		t_conv;

typedef struct s_format
{
	int	zero_flag;
	int	minus_flag;
	int	plus_flag;
	int	hash_flag;
	int	space_flag;
}		t_format;

int		ft_printf(const char *fmt, ...);
void	flag_check(const char *fmt, int *i, t_format *flag);

// string and character functions:
int		b_ft_putchar(char c);
int		b_ft_putstr(char *s);
size_t	b_ft_strlen(char *str);
// number functions:
int		b_ft_putnbr(int n);
int		b_ft_putnbr_unsigned(unsigned int n);
int		b_num_len(int n);
int		b_unsigned_num_len(unsigned int n);
// hexadecimal number functions:
int		print_string(char *str, int len);
char	*b_return_hexvalue_lower(unsigned int n);
char	*b_return_hexvalue_upper(unsigned int n);
char	*b_return_address_and_convert_to_hex(void *address);

// All Cases for the %c and %s format
int		character_case(va_list *list, t_format *flg, int w_nbr);
int		string_case(va_list *list, t_format *flg, int w_nbr, int p_nbr);
int		string_case_one(char *str, t_format *flg, int w_nbr, int len);
int		string_case_two(char *str, t_format *flg, int w_nbr, int p_nbr);
int		string_null_edge_case(t_format *flg, char *str, int w_nbr, int p_nbr);
int		string_edge_case1(t_format *flg, char *temp, int w_nbr, int p_nbr);
int		string_edge_case2(t_format *flg, char *str, int w_nbr, int len);

// All Cases for the %d and %i format
int		sign_case(t_format *flg, int c);
int		width_padding(int w_nbr);

int		number_case(va_list *list, t_format *flg, int w_nbr, int p_nbr);
int		number_case_one(t_format *flg, int c, int p_nbr, int w_nbr);
int		number_case_two(t_format *flg, int c, int len, int p_nbr);
int		number_case_three(t_format *flg, int c, int w_nbr, int p_nbr);
int		number_edge_case1(t_format *flg, int c, int p_nbr);
int		number_edge_case2(t_format *flg, int c, int w_nbr, int p_nbr);
int		number_edge_case3(t_format *flg, int c, int w_nbr, int p_nbr);
int		number_edge_case4(t_format *flg, int c, int w_nbr, int p_nbr);
int		number_edge_case5(t_format *flg, int c, int w_nbr, int p_nbr);
int		number_edge_case6(t_format *flg, int c, int w_nbr, int p_nbr);
int		number_edge_case7(t_format *flg, int c, int w_nbr, int p_nbr);
int		number_combined_flags(t_format *flg, int w_nbr, int p_nbr, int c);
int		number_combined_flags_2(t_format *flg, int w_nbr, int p_nbr, int c);
int		number_individual_flags(t_format *flg, int w_nbr, int p_nbr, int c);
int		number_individual_flags_2(t_format *flg, int w_nbr, int p_nbr, int c);

// All Cases for %u:
int		u_number_case(va_list *list, t_format *flg, int w_nbr, int p_nbr);
int		u_number_case_one(t_format *flg, int c, int w_nbr, int len);
int		u_number_case_two(int c, int p_nbr, int len);
int		u_number_case_three(t_format *flg, int c, int w_nbr, int p_nbr);
int		u_edge_case1(int c, int w_nbr, int p_nbr);
int		u_edge_case2(int c, int w_nbr, int p_nbr);
int		u_edge_case3(int c, int w_nbr, int p_nbr);
int		u_edge_case4(int c, int w_nbr, int p_nbr);

// All Cases for %x:
int		x_lower_else_number_case(t_format *flg, char *str, unsigned int num,
			int len);
int		x_lower_number_case(va_list *list, t_format *flg, int w_nbr, int p_nbr);
int		x_lower_number_case_one(t_format *flg, int p_nbr, unsigned int num,
			int w_nbr);
int		x_lower_number_case_two(t_format *flg, char *str, unsigned int num,
			int p_nbr);
int		x_lower_number_case_three(t_format *flg, unsigned int num, int w_nbr,
			int p_nbr);
int		x_lower_number_else_case(t_format *flg, char *str, int w_nbr, int len);
int		x_lower_number_else_case2(t_format *flg, char *str, int w_nbr,
			int p_nbr);
int		x_lower_number_combined_flags(t_format *flg, unsigned int num,
			int w_nbr, int p_nbr);
int		x_lower_number_combined_flags2(t_format *flg, char *str, int w_nbr,
			int p_nbr);
int		x_lower_edge_case1(t_format *flg, int num, int w_nbr, int p_nbr);
int		x_lower_edge_case2(t_format *flg, int num, int w_nbr, int p_nbr);
int		x_lower_edge_case3(char *str, int w_nbr, int len);
int		x_lower_edge_case4(char *str, int w_nbr, int len);
int		x_lower_edge_case5(char *str, int w_nbr, int len);
int		x_lower_edge_case6(char *str, int w_nbr, int p_nbr);
int		x_lower_edge_case7(char *str, int w_nbr, int p_nbr);
int		lower_zero_case(t_format *flg, int w_nbr);
int		lower_zero_case2(t_format *flg, int w_nbr, int p_nbr);

// All Cases for %X
int		x_upper_else_number_case(t_format *flg, char *str, unsigned int num,
			int len);
int		x_upper_number_case(va_list *list, t_format *flg, int w_nbr, int p_nbr);
int		x_upper_number_case_one(t_format *flg, int p_nbr, unsigned int num,
			int w_nbr);
int		x_upper_number_case_two(t_format *flg, char *str, unsigned int num,
			int p_nbr);
int		x_upper_number_case_three(t_format *flg, unsigned int num, int w_nbr,
			int p_nbr);
int		x_upper_number_else_case(t_format *flg, char *str, int w_nbr, int len);
int		x_upper_number_else_case2(t_format *flg, char *str, int w_nbr,
			int p_nbr);
int		x_upper_number_combined_flags(t_format *flg, unsigned int num,
			int w_nbr, int p_nbr);
int		x_upper_number_combined_flags2(t_format *flg, char *str, int w_nbr,
			int p_nbr);
int		x_upper_edge_case1(t_format *flg, int num, int w_nbr, int p_nbr);
int		x_upper_edge_case2(t_format *flg, int num, int w_nbr, int p_nbr);
int		x_upper_edge_case3(char *str, int w_nbr, int len);
int		x_upper_edge_case4(char *str, int w_nbr, int len);
int		x_upper_edge_case5(char *str, int w_nbr, int len);
int		x_upper_edge_case6(char *str, int w_nbr, int p_nbr);
int		x_upper_edge_case7(char *str, int w_nbr, int p_nbr);
int		upper_zero_case(t_format *flg, int w_nbr);
int		upper_zero_case2(t_format *flg, int w_nbr, int p_nbr);
// All Cases for %p
int		p_number_case(va_list *list, t_format *flg, int w_nbr, int p_nbr);
int		p_number_edge_case1(void *ptr, int w_nbr, int len);
int		p_number_case_one(t_format *flg, void *ptr, int w_nbr, int len);
int		p_number_case_two(char *str, void *ptr, int p_nbr, int len);
int		p_number_case_three(t_format *flg, void *ptr, int w_nbr, int p_nbr);
int		p_else_case(char *str, int w_nbr, int p_nbr);
int		p_else_case2(char *str, int len, void *ptr);

// All Cases for percent %:
int		percent_case(t_format *flg, int w_nbr);
#endif