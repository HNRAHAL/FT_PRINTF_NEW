/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahal <hrahal@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 11:50:12 by hrahal            #+#    #+#             */
/*   Updated: 2025/10/29 11:40:11 by hrahal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	flag_check(const char *fmt, int *i, t_format *flag)
{
	flag->minus_flag = 0;
	flag->plus_flag = 0;
	flag->space_flag = 0;
	flag->hash_flag = 0;
	flag->zero_flag = 0;
	while (fmt[*i] == '0' || fmt[*i] == '-' || fmt[*i] == '+' || fmt[*i] == ' '
		|| fmt[*i] == '#')
	{
		if (fmt[*i] == '0')
			flag->zero_flag = 1;
		else if (fmt[*i] == '+')
			flag->plus_flag = 1;
		else if (fmt[*i] == ' ')
			flag->space_flag = 1;
		else if (fmt[*i] == '#')
			flag->hash_flag = 1;
		else if (fmt[*i] == '-')
			flag->minus_flag = 1;
		(*i)++;
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list		list;
	t_format	flg;
	int			i;
	int			count;
	int			w_nbr;
	int			p_nbr;
	int			len;

	len = 0;
	count = 0;
	va_start(list, fmt);
	i = 0;
	while (fmt[i])
	{
		p_nbr = -1;
		w_nbr = -1;
		if (fmt[i] == '%' && fmt[i + 1])
		{
			i++;
			flag_check(fmt, &i, &flg);
			if (fmt[i] >= '0' && fmt[i] <= '9')
			{
				w_nbr = 0;
				while (fmt[i] >= '0' && fmt[i] <= '9')
					w_nbr = (w_nbr * 10 + (fmt[i++] - '0'));
			}
			if (fmt[i] == '.')
			{
				i++;
				p_nbr = 0;
				while (fmt[i] >= '0' && fmt[i] <= '9')
					p_nbr = (p_nbr * 10 + (fmt[i++] - '0'));
			}
			if (fmt[i] == 'c')
				count += character_case(&list, &flg, w_nbr);
			else if (fmt[i] == 's')
				count += string_case(&list, &flg, w_nbr, p_nbr);
			else if ((fmt[i] == 'd') || (fmt[i] == 'i'))
				count += number_case(&list, &flg, w_nbr, p_nbr);
			else if (fmt[i] == 'u')
				count += u_number_case(&list, &flg, w_nbr, p_nbr);
			else if (fmt[i] == 'x')
				count += x_lower_number_case(&list, &flg, w_nbr, p_nbr);
			else if (fmt[i] == 'X')
				count += x_upper_number_case(&list, &flg, w_nbr, p_nbr);
			else if (fmt[i] == 'p')
				count += p_number_case(&list, &flg, w_nbr, p_nbr);
			else if (fmt[i] == '%')
				count += percent_case(&flg, w_nbr);
			i++;
		}
		else
		{
			count += write(1, &fmt[i], 1);
			if (count == -1)
				return (-1);
			i++;
		}
	}
	va_end(list);
	return (count);
}


// #include <stdio.h>
// int main()
// {
// 	int len1 = ft_printf("|%1.u, %1.u, %1.u, %1.u, %1.u, %1.u, %1.u, %1.u, %1.u, %1.u|\n", 0, 5, -1, -10, 100, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
// 	int len2 = printf("|%1.u, %1.u, %1.u, %1.u, %1.u, %1.u, %1.u, %1.u, %1.u, %1.u|\n", 0, 5, -1, -10, 100, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
	
// 	// int len1 = ft_printf("|%1.1u, %1.1u, %1.1u, %1.1u, %1.1u, %1.1u, %1.1u, %1.1u, %1.1u, %1.1u|\n", 0, 5, -1, -10, 100, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
// 	// int len2 = printf("|%1.1u, %1.1u, %1.1u, %1.1u, %1.1u, %1.1u, %1.1u, %1.1u, %1.1u, %1.1u|\n", 0, 5, -1, -10, 100, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
	
// 	// int len1 = ft_printf("|%01.1u, %01.1u, %01.1u, %01.1u, %01.1u, %01.1u, %01.1u, %01.1u, %01.1u, %01.1u|\n", 0, 5, -1, -10, 100, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
// 	// int len2 = printf("|%01.1u, %01.1u, %01.1u, %01.1u, %01.1u, %01.1u, %01.1u, %01.1u, %01.1u, %01.1u|\n", 0, 5, -1, -10, 100, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
	
// 	// int len1 = ft_printf("|%05.u, %05.u, %05.u, %05.u, %05.u, %05.u, %05.u, %05.u, %05.u, %05.u|\n", 0, 5, -1, -10, 100, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
// 	// int len2 = printf("|%05.u, %05.u, %05.u, %05.u, %05.u, %05.u, %05.u, %05.u, %05.u, %05.u|\n", 0, 5, -1, -10, 100, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
	
// 	// int len1 = ft_printf("|%05.0u, %05.0u, %05.0u, %05.0u, %05.0u, %05.0u, %05.0u, %05.0u, %05.0u, %05.0u|\n", 0, 5, -1, -10, 100, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
// 	// int len2 = printf("|%05.0u, %05.0u, %05.0u, %05.0u, %05.0u, %05.0u, %05.0u, %05.0u, %05.0u, %05.0u|\n", 0, 5, -1, -10, 100, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);

// 	// int len1 = ft_printf("|%010.1u, %010.1u, %010.1u, %010.1u, %010.1u, %010.1u, %010.1u, %010.1u, %010.1u, %010.1u|\n", 0, 5, -1, -10, 100, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
// 	// int len2 = printf("|%010.1u, %010.1u, %010.1u, %010.1u, %010.1u, %010.1u, %010.1u, %010.1u, %010.1u, %010.1u|\n", 0, 5, -1, -10, 100, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
	
// 	printf("len1: %d\n", len1);
// 	printf("len2: %d\n", len2);
// }
// #include <stdio.h>
// int main()
// {
// 	// int len1 = ft_printf("|%+.d, %+.d, %+.d, %+.d, %+.d, %+.d, %+.d, %+.d|\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
// 	// int len2 = printf("|%+.d, %+.d, %+.d, %+.d, %+.d, %+.d, %+.d, %+.d|\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);

// 	// int len1 = ft_printf("|%+.0d, %+.0d, %+.0d, %+.0d, %+.0d, %+.0d, %+.0d, %+.0d|\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
// 	// int len2 = printf("|%+.0d, %+.0d, %+.0d, %+.0d, %+.0d, %+.0d, %+.0d, %+.0d|\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);

// 	// int len1 = ft_printf("|%+1.d, %+1.d, %+1.d, %+1.d, %+1.d, %+1.d, %+1.d, %+1.d|\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
// 	// int len2 = printf("|%+1.d, %+1.d, %+1.d, %+1.d, %+1.d, %+1.d, %+1.d, %+1.d|\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);

// 	// int len1 = ft_printf("|%+1.0d, %+1.0d, %+1.0d, %+1.0d, %+1.0d, %+1.0d, %+1.0d, %+1.0d|\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
// 	// int len2 = printf("|%+1.0d, %+1.0d, %+1.0d, %+1.0d, %+1.0d, %+1.0d, %+1.0d, %+1.0d|\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);

// 	// int len1 = ft_printf("|%+1d, %+1d, %+1d, %+1d, %+1d, %+1d, %+1d, %+1d|\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
// 	// int len2 = printf("|%+1d, %+1d, %+1d, %+1d, %+1d, %+1d, %+1d, %+1d|\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);

// 	// int len1 = ft_printf("|%+5.d, %+5.d, %+5.d, %+5.d, %+5.d, %+5.d, %+5.d, %+5.d|\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
// 	// int len2 = printf("|%+5.d, %+5.d, %+5.d, %+5.d, %+5.d, %+5.d, %+5.d, %+5.d|\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);

// 	// int len1 = ft_printf("|%0+1.d, %0+1.d, %0+1.d, %0+1.d, %0+1.d, %0+1.d, %0+1.d, %0+1.d|\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
// 	// int len2 = printf("|%0+1.d, %0+1.d, %0+1.d, %0+1.d, %0+1.d, %0+1.d, %0+1.d, %0+1.d|\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);


// 	// int len1 = ft_printf("|%0+1.0d, %0+1.0d, %0+1.0d, %0+1.0d, %0+1.0d, %0+1.0d, %0+1.0d, %0+1.0d|\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
// 	// int len2 = printf("|%0+1.0d, %0+1.0d, %0+1.0d, %0+1.0d, %0+1.0d, %0+1.0d, %0+1.0d, %0+1.0d|\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);

// 	// int len1 = ft_printf("|%0+1.0d, %0+1.0d, %0+1.0d, %0+1.0d, %0+1.0d, %0+1.0d, %0+1.0d, %0+1.0d|\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
// 	// int len2 = printf("|%0+1.0d, %0+1.0d, %0+1.0d, %0+1.0d, %0+1.0d, %0+1.0d, %0+1.0d, %0+1.0d|\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	
// 	// int len1 = ft_printf("|%0+5.d, %0+5.d, %0+5.d, %0+5.d, %0+5.d, %0+5.d, %0+5.d, %0+5.d|\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
// 	// int len2 = printf("|%0+5.d, %0+5.d, %0+5.d, %0+5.d, %0+5.d, %0+5.d, %0+5.d, %0+5.d|\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);

// 	// int len1 = ft_printf("|%0 1.d, %0 1.d, %0 1.d, %0 1.d, %0 1.d, %0 1.d, %0 1.d, %0 1.d|\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
// 	// int len2 = printf("|%0 1.d, %0 1.d, %0 1.d, %0 1.d, %0 1.d, %0 1.d, %0 1.d, %0 1.d|\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);

// 	// int len1 = ft_printf("|%-+1.d, %-+1.d, %-+1.d, %-+1.d, %-+1.d, %-+1.d, %-+1.d, %-+1.d|\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
// 	// int len2 = printf("|%-+1.d, %-+1.d, %-+1.d, %-+1.d, %-+1.d, %-+1.d, %-+1.d, %-+1.d|\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	

// 	printf("len1: %d\n", len1);
// 	printf("len2: %d\n", len2);
// }

// #include <stdio.h>
// int main()
// {
// 	// int len1 = ft_printf(" |%04x| \n", 9);
// 	// int len2 = printf(" |%04x| \n", 9);

// 	// int len1 = ft_printf(" |%08.3x| \n", 8375);
// 	// int len2 = printf(" |%08.3x| \n", 8375);

// 	// int len1 = ft_printf(" |%.0x| \n", 0);
// 	// int len2 = printf(" |%.0x| \n", 0);
	
// 	// int len1 = ft_printf(" |%.x| \n", 0);
// 	// int len2 = printf(" |%.x| \n", 0);

// 	// int len1 = ft_printf(" |%5.0x| \n", 0);
// 	// int len2 = printf(" |%5.0x| \n", 0);
	
// 	// int len1 = ft_printf(" |%5.x| \n", 0);
// 	// int len2 = printf(" |%5.x| \n", 0);

// 	// int len1 = ft_printf(" |%-5.0x| \n", 0);
// 	// int len2 = printf(" |%-5.0x| \n", 0);

// 	// int len1 = ft_printf(" |^.^/%0#35.2x^.^/| \n",  -675812234);
// 	// int len2 = printf(" |^.^/%0#35.2x^.^/| \n",  -675812234);

// 	int len1 = ft_printf(" |%046.2x| \n", 868303272);
// 	int len2 = printf(" |%046.2x| \n",  868303272);
	
// 	printf("len1: %d\n", len1);
// 	printf("len2: %d\n", len2);
// }

// #include <stdio.h>
// int main()
// {

	
// // // // 	int len1 = ft_printf("|%3.s|\n", NULL);
// // // // 	int len2 = printf("|%3.s|\n", NULL);

// // // // 	int len1 = ft_printf("|%10.s|\n", NULL);
// // // // 	int len2 = printf("|%10.s|\n", NULL);

// // // // 	int len1 = ft_printf("|%-3.s|\n", NULL);
// // // // 	int len2 = printf("|%-3.s|\n", NULL);

// // // // 	int len1 = ft_printf("|%-8.s|\n", NULL);
// // // // 	int len2 = printf("|%-8.s|\n", NULL);

// // // // 	int len1 = ft_printf("|%3.1s|\n", NULL);
// // // // 	int len2 = printf("|%3.1s|\n", NULL);
	
// // // // 	int len1 = ft_printf("|%9.1s|\n", NULL);
// // // // 	int len2 = printf("|%9.1s|\n", NULL);

// // // // 	int len1 = ft_printf("|%-3.1s|\n", NULL);
// // // // 	int len2 = printf("|%-3.1s|\n", NULL);
	
// // // // 	int len1 = ft_printf("|%-9.1s|\n", NULL);
// // // // 	int len2 = printf("|%-9.1s|\n", NULL);

// // // // 	int len1 = ft_printf("|%20.6s|\n", NULL);
// // // // 	int len2 = printf("|%20.6s|\n", NULL);

// // // // 	int len1 = ft_printf("|%.03s|\n", NULL);
// // // // 	int len2 = printf("|%.03s|\n", NULL);
	
// // // // 	int len1 = ft_printf("|%.1s, %.1s, %.1s, %.1s|\n", (char *)NULL, "", "test", "joihwhhgsdkhksdgsdg\t\v\n\r\f\a25252\b6");
// // // // 	int len2 = printf("|%.1s, %.1s, %.1s, %.1s|\n", (char *)NULL, "", "test", "joihwhhgsdkhksdgsdg\t\v\n\r\f\a25252\b6");

// // // // 	int len1 = ft_printf("|%.5s, %.5s, %.5s, %.5s|\n", (char *)NULL, "", "test", "joihwhhgsdkhksdgsdg\t\v\n\r\f\a25252\b6");
// // // // 	int len2 = printf("|%.5s, %.5s, %.5s, %.5s|\n", (char *)NULL, "", "test", "joihwhhgsdkhksdgsdg\t\v\n\r\f\a25252\b6");

// // // // 	int len1 = ft_printf("|%1.1s, %1.1s, %1.1s, %1.1s|\n", (char *)NULL, "", "test", "joihwhhgsdkhksdgsdg\t\v\n\r\f\a25252\b6");
// // // // 	int len2 = printf("|%1.1s, %1.1s, %1.1s, %1.1s|\n", (char *)NULL, "", "test", "joihwhhgsdkhksdgsdg\t\v\n\r\f\a25252\b6");

// // // 	// int len1 = ft_printf("|%08.3d|\n", 8375);//done
// // // 	// int len2 = printf("|%08.3d|\n", 8375);

// // // 	// int len1 = ft_printf("|%08.3d|\n", -8375);//done
// // // 	// int len2 = printf("|%08.3d|\n", -8375);

// // // 	// int len1 = ft_printf("|%.0d|\n", 0);//done
// // // 	// int len2 = printf("|%.0d|\n", 0);

// // // 	// int len1 = ft_printf("|%.d|\n", 0);//done
// // // 	// int len2 = printf("|%.d|\n", 0);

// // // 	// int len1 = ft_printf("|%5.0d|\n", 0);//done
// // // 	// int len2 = printf("|%5.0d|\n", 0);

// // // 	// int len1 = ft_printf("|%5.d|\n", 0);//done
// // // 	// int len2 = printf("|%5.d|\n", 0);

// 	int len1 = ft_printf("|%.1d|\n", 0);//done
// 	int len2 = printf("|%.1d|\n", 0);

// 	// int len1 = ft_printf("|%.1i|\n", 0);//done
// 	// int len2 = printf("|%.1i|\n", 0);

// // // 	// int len1 = ft_printf("|%08.3i|\n", 8375);//done
// // // 	// int len2 = printf("|%08.3i|\n", 8375);

// // // 	// int len1 = ft_printf("|%08.3i|\n", -8375);//done
// // // 	// int len2 = printf("|%08.3i|\n", -8375);

// // // 	// int len1 = ft_printf("|%.0i|\n", 0);//done
// // // 	// int len2 = printf("|%.0i|\n", 0);

// // // 	// int len1 = ft_printf("|%.i|\n", 0);//done
// // // 	// int len2 = printf("|%.i|\n", 0);

// // // 	// int len1 = ft_printf("|%5.0i|\n", 0);//done
// // // 	// int len2 = printf("|%5.0i|\n", 0);

// // // 	// int len1 = ft_printf("|%3i|\n", 0);//done
// // // 	// int len2 = printf("|%3i|\n", 0);

// // // 	// int len1 = ft_printf("|%3d|\n", 0); //done
// // // 	// int len2 = printf("|%3d|\n", 0);

// // // 	// int len1 = ft_printf("|%-5.0i|\n", 0);//done
// // // 	// int len2 = printf("|%-5.0i|\n", 0);

// // // 	// int len1 = ft_printf("|%-5.i|\n", 0);//done
// // // 	// int len2 = printf("|%-5.i|\n", 0);

// // // 	// int len1 = ft_printf("|%-5.0d|\n", 0);//done
// // // 	// int len2 = printf("|%-5.0d|\n", 0);

// // // 	// int len1 = ft_printf("|%-5.d|\n", 0);//done
// // // 	// int len2 = printf("|%-5.d|\n", 0);

// // // 	// int len1 = ft_printf("|%-3i|\n", 0);//done
// // // 	// int len2 = printf("|%-3i|\n", 0);

// // // 	// int len1 = ft_printf("|%3d|\n", 0); //done
// // // 	// int len2 = printf("|%3d|\n", 0);

// // 	// int len1 = ft_printf("|42% 027.2d42|\n", -1868692962); //done
// // 	// int len2 = printf("|42% 027.2d42|\n", -1868692962);

// // 	// int len1 = ft_printf("|% -10.16d|\n", 1673910419); //done
// // 	// int len2 = printf("|% -10.16d|\n", 1673910419);

// // 	// int len1 = ft_printf("|\\!/%-60.1d\\!/|\n", 0); //done
// // 	// int len2 = printf("|\\!/%-60.1d\\!/|\n", 0);

// // 	// int len1 = ft_printf("|^.^/% 07d^.^/|\n", 0); //done
// // 	// int len2 = printf("|^.^/% 07d^.^/|\n", 0);

// // 	// int len1 = ft_printf("|!%+022.2d!|\n", 1476129440); //done
// // 	// int len2 = printf("|!%+022.2d!|\n", 1476129440);

// // 	// int len1 = ft_printf("|%08.3u|\n", 8375);
// // 	// int len2 = printf("|%08.3u|\n", 8375);

// // 	// int len1 = ft_printf("|%.0u|\n", 0);
// // 	// int len2 = printf("|%.0u|\n", 0);

// // 	// int len1 = ft_printf("|%.u|\n", 0);
// // 	// int len2 = printf("|%.u|\n", 0);

// // 	// int len1 = ft_printf("|%5.0u|\n", 0);
// // 	// int len2 = printf("|%5.0u|\n", 0);

// // 	// int len1 = ft_printf("|%5.u|\n", 0);
// // 	// int len2 = printf("|%5.u|\n", 0);

// // 	// int len1 = ft_printf("|%-5.0u|\n", 0);
// // 	// int len2 = printf("|%-5.0u|\n", 0);

// // 	// int len1 = ft_printf("|%-5.u|\n", 0);
// // 	// int len2 = printf("|%-5.u|\n", 0);

// // 	// int len1 = ft_printf("| %.1u |\n", 0);
// // 	// int len2 = printf("| %.1u |\n", 0);

// // 	// int len1 = ft_printf("| %-13u |\n", UINT_MAX);
// // 	// int len2 = printf("| %-13u |\n", UINT_MAX);


// // 	// int len1 = ft_printf("|%3u|\n", 0);
// // 	// int len2 = printf("|%3u|\n", 0);
	
// // 	// int len1 = ft_printf("|%-5.0u|\n", 0);
// // 	// int len2 = printf("|%-5.0u|\n", 0);

// // 	// int len1 = ft_printf("|%-5.u|\n", 0);
// // 	// int len2 = printf("|%-5.u|\n", 0);

// // 	// int len1 = ft_printf("|42%-2.1u42|\n", 0);
// // 	// int len2 = printf("|42%-2.1u42|\n", 0);

// // 	// int len1 = ft_printf("|%.0x|\n", 0);
// // 	// int len2 = printf("|%.0x|\n", 0);

// // 	// int len1 = ft_printf("|%.0X|\n", 0);
// // 	// int len2 = printf("|%.0X|\n", 0);
 
// // 	// int len1 = ft_printf("|%.x|\n", 0);
// // 	// int len2 = ft_printf("|%.x|\n", 0);
	
// // 	// int len1 = ft_printf("|%.X|\n", 0);
// // 	// int len1 = ft_printf("|%.X|\n", 0);

// // 	int len1 = ft_printf("|%5.0x|\n", 0);//stopped here
// // 	int len2 = printf("|%5.0x|\n", 0);

// // 	// int len1 = ft_printf("|%5.0X|\n", 0);
// // 	// int len1 = ft_printf("|%5.0X|\n", 0);

// // 	// int len1 = ft_printf("|%5.x|\n", 0);
// // 	// int len1 = ft_printf("|%5.x|\n", 0);

// // 	// int len1 = ft_printf("|%5.X|\n", 0);
// // 	// int len1 = ft_printf("|%5.X|\n", 0);

// // 	// int len1 = ft_printf("|%-5.0x|\n", 0);
// // 	// int len1 = ft_printf("|%-5.0x|\n", 0);

// // 	// int len1 = ft_printf("|%-5.0X|\n", 0);
// // 	// int len1 = ft_printf("|%-5.0X|\n", 0);

// // 	// int len1 = ft_printf("|%-5.x|\n", 0);
// // 	// int len1 = ft_printf("|%-5.x|\n", 0);

// // 	// int len1 = ft_printf("|%-5.X|\n", 0);
// // 	// int len1 = ft_printf("|%-5.X|\n", 0);
	
// // 	// int len1 = ft_printf("|%08.3x|\n", 8375);
// // 	// int len1 = ft_printf("|%08.3x|\n", 8375);

// // 	// int len1 = ft_printf("|%08.3X|\n", 8375);
// // 	// int len1 = ft_printf("|%08.3X|\n", 8375);

// // 	// int len1 = ft_printf("|%.0x|\n", 0);
// // 	// int len1 = ft_printf("|%.0x|\n", 0);

// // 	// int len1 = ft_printf("|%.0X|\n", 0);
// // 	// int len1 = ft_printf("|%.0X|\n", 0);
	
// // 	// int len1 = ft_printf("|%.x|\n", 0);
// // 	// int len1 = ft_printf("|%.x|\n", 0);

// // 	// int len1 = ft_printf("|%.X|\n", 0);
// // 	// int len1 = ft_printf("|%.X|\n", 0);
	
// // 	printf("len1: %d\n", len1);
// // 	printf("len2: %d\n", len2);
	
// }

// #include <stdio.h>
// int main()
// {
// 	// int len1 = ft_printf("|%.0i|\n", 0);
// 	// int len2 = printf("|%.0i|\n", 0);

// 	int len1 = ft_printf("|!% -.1d!|\n", 0);
// 	int len2 = printf("|!% -.1d!|\n", 0);

// 	printf("len1: %d\n", len1);
// 	printf("len2: %d\n", len2);
// }