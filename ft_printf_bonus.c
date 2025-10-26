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

#include <stdio.h>
int	ft_printf(const char *fmt, ...)
{
	va_list		list;
	t_format	flg;

	int i, count, w_nbr, p_nbr, c, len;
	char *str;
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
			if(fmt[i] == 'c')
				count += character_case(&list, &flg, w_nbr);
			else if(fmt[i] == 's')
				count += string_case(&list, &flg, w_nbr, p_nbr);
			else if((fmt[i] == 'd' )||( fmt[i] == 'i'))
				count += number_case(&list, &flg, w_nbr, p_nbr);
			else if(fmt[i] == 'u')
				count += u_number_case(&list, &flg, w_nbr, p_nbr);
			else if(fmt[i] == 'x')
				count += x_lower_number_case(&list, &flg, w_nbr, p_nbr);
			else if(fmt[i] == 'X')
				count += x_upper_number_case(&list, &flg, w_nbr, p_nbr);
			else if(fmt[i] == 'p')
				count += p_number_case(&list, &flg, w_nbr, len);
			else if(fmt[i] == '%')
				count += percent_case(&flg, w_nbr, len);
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
 
#include <stdio.h>
int main()
{
	//char test cases: 

	// int len1 = ft_printf("|%c|\n", '0');
	// int len2 = printf("|%c|\n", '0');

	// int len1 = ft_printf("|%-1c|\n", '0');
	// int len2 = printf("|%-1c|\n", '0');

	// int len1 = ft_printf("|%1c|\n", '0');
	// int len2 = printf("|%1c|\n", '0');

	// int len1 = ft_printf("|%-10c|\n", '0');
	// int len2 = printf("|%-10c|\n", '0');

	// 	int len1 = ft_printf("|%10c|\n", '0');
	// int len2 = printf("|%10c|\n", '0');

	// int len1 = ft_printf("|%10c||%-10c||%c||%-1c||%-2c||%1c||%2c|\n", '0',50,'p', '%', 90, '*','=');
	// int len2 = printf("|%10c||%-10c||%c||%-1c||%-2c||%1c||%2c|\n", '0',50,'p', '%', 90, '*','=');

	//string test cases: 

	// int len1 = ft_printf("|%-10s|\n", "mar7aba");
	// int len2 = printf("|%-10s|\n", "mar7aba");

	// int len1 = ft_printf("|%10s|\n", "mar7aba");
	// int len2 = printf("|%10s|\n", "mar7aba");

	// int len1 = ft_printf("|%2s||%10s||%-10s|\n", "mar7aba","mar7aba","mar7aba");
	// int len2 = printf("|%2s||%10s||%-10s|\n", "mar7aba","mar7aba","mar7aba");

	// int len1 = ft_printf("|%5s|\n", "mar7aba");
	// int len2 = printf("|%5s|\n", "mar7aba");

	// int len1 = ft_printf("|%.20s|\n", "mar7aba");
	// int len2 = printf("|%.20s|\n", "mar7aba");

	// int len1 = ft_printf("|%.100s|\n", "mar7aba");
	// int len2 = printf("|%.100s|\n", "mar7aba");

	// int len1 = ft_printf("|%.2s|\n", "mar7aba");
	// int len2 = printf("|%.2s|\n", "mar7aba");

	// int len1 = ft_printf("|%.0s|\n", "mar7aba");
	// int len2 = printf("|%.0s|\n", "mar7aba");

	// int len1 = ft_printf("|%+-0 #.20s|\n", "mar7aba");
	// int len2 = printf("|%+-0 #.20s|\n", "mar7aba");

	// int len1 = ft_printf("|%10s||%-10s||%s||%-.1s||%-.2s||%.10s||%2s|\n", "one", "two", "salaammm", "peacee", "todayy", "janaah","hayattt");
	// int len2 = printf("|%10s||%-10s||%s||%-.1s||%-.2s||%.10s||%2s|\n", "one", "two", "salaammm", "peacee", "todayy", "janaah","hayattt");

	// int len1 = ft_printf("|%1.0s|\n", "mar7aba");
	// int len2 = printf("|%1.0s|\n", "mar7aba");

	// int len1 = ft_printf("|%0.0s|\n", "mar7aba");
	// int len2 = printf("|%0.0s|\n", "mar7aba");

	// int len1 = ft_printf("|%0.100s|\n", "mar7aba");
	// int len2 = printf("|%0.100s|\n", "mar7aba");

	// int len1 = ft_printf("|%10.100s|\n", "mar7aba");
	// int len2 = printf("|%10.100s|\n", "mar7aba");

	// int len1 = ft_printf("|%100.100s|\n", "mar7aba");
	// int len2 = printf("|%100.100s|\n", "mar7aba");

	// int len1 = ft_printf("|%-1.1s|\n", "mar7aba");
	// int len2 = printf("|%-1.1s|\n", "mar7aba");

	// 	int len1 = ft_printf("|%-0.1s|\n", "mar7aba");
	// int len2 = printf("|%-0.1s|\n", "mar7aba");
	
	// 	int len1 = ft_printf("|%-1.0s|\n", "mar7aba");
	// int len2 = printf("|%-1.0s|\n", "mar7aba");

	// int len1 = ft_printf("|%-0.0s|\n", "mar7aba");
	// int len2 = printf("|%-0.0s|\n", "mar7aba");

	// int len1 = ft_printf("|%-0.100s|\n", "mar7aba");
	// int len2 = printf("|%-0.100s|\n", "mar7aba");

	// int len1 = ft_printf("|%-100.100s||%-0.100s||%-1.0s||%-1.1s||%-0.1s||%100.100s||%0.100s||%1.0s||%1.1s||%0.1s|\n", "mar7aba", "mar7aba", "mar7aba", "mar7aba", "mar7aba", "mar7aba", "mar7aba", "mar7aba", "mar7aba", "mar7aba");
	// int len2 = printf("|%-100.100s||%-0.100s||%-1.0s||%-1.1s||%-0.1s||%100.100s||%0.100s||%1.0s||%1.1s||%0.1s|\n", "mar7aba", "mar7aba", "mar7aba", "mar7aba", "mar7aba", "mar7aba", "mar7aba", "mar7aba", "mar7aba", "mar7aba");

	// int len1 = ft_printf("|%10c||%-10c||%c||%-1c||%-2c||%1c||%2c||%-1.0s||%-1.1s||%-0.1s||%1.0s||%1.1s||%0.1s|\n", '0',50,'p', '%', 90, '*','=', "mar7aba","mar7aba","mar7aba","mar7aba","mar7aba","mar7aba");
	// int len2 = printf("|%10c||%-10c||%c||%-1c||%-2c||%1c||%2c||%-1.0s||%-1.1s||%-0.1s||%1.0s||%1.1s||%0.1s|\n", '0',50,'p', '%', 90, '*','=', "mar7aba","mar7aba","mar7aba","mar7aba","mar7aba","mar7aba");

	//signed numbers d and i:

	//  int len1 = ft_printf("|%d||%i|\n", 0,0);
	//  int len2 = printf("|%d||%i|\n", 0,0);

	//  int len1 = ft_printf("|%d||%i|\n", 20,20);
	//  int len2 = printf("|%d||%i|\n", 20,20);

	// int len1 = ft_printf("|%d||%i|\n", -2147483648,-2147483648);
	// int len2 = printf("|%d||%i|\n", -2147483648,-2147483648);

	// int len1 = ft_printf("|%d||%i|\n", 2147483647,2147483647);
	// int len2 = printf("|%d||%i|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%d||%i|\n", 214748364756,214748364756);
	// int len2 = printf("|%d||%i|\n", 214748364756,214748364756);

	// int len1 = ft_printf("|%d||%i|\n", -214748364756,-214748364756);
	// int len2 = printf("|%d||%i|\n", -214748364756,-214748364756);

	//  int len1 = ft_printf("|%30d||%30i|\n", 20,20);
	//  int len2 = printf("|%30d||%30i|\n", 20,20);

	//  int len1 = ft_printf("|%30d||%30i|\n", 0,0);
	//  int len2 = printf("|%30d||%30i|\n", 0,0);

	// int len1 = ft_printf("|%30d||%30i|\n", -20,-20); 
	// int len2 = printf("|%30d||%30i|\n", -20,-20);

	// 	int len1 = ft_printf("|%-+30d||%-+30i|\n", 0,0); 
	// int len2 = printf("|%-+30d||%-+30i|\n", 0,0);
	
	// int len1 = ft_printf("|%-+30d||%-+30i|\n", -20,-20); 
	// int len2 = printf("|%-+30d||%-+30i|\n", -20,-20);

	// int len1 = ft_printf("|%-+30d||%-+30i|\n", 20,20);
	// int len2 = printf("|%-+30d||%-+30i|\n", 20,20);

	// int len1 = ft_printf("|%-+30d||%-+30i|\n", -2147483648,-2147483648); 
	// int len2 = printf("|%-+30d||%-+30i|\n", -2147483648,-2147483648);

	// int len1 = ft_printf("|%-+30d||%-+30i|\n", 2147483647 ,2147483647 ); 
	// int len2 = printf("|%-+30d||%-+30i|\n", 2147483647 ,2147483647 );

	// int len1 = ft_printf("|%-+30d||%-+30i|\n", 214748364756,214748364756); 
	// int len2 = printf("|%-+30d||%-+30i|\n", 214748364756,214748364756);

	// int len1 = ft_printf("|%-+30d||%-+30i|\n", -214748364756,-214748364756); 
	// int len2 = printf("|%-+30d||%-+30i|\n", -214748364756,-214748364756);
	
	// int len1 = ft_printf("|% -30d||% -30i|\n", 0,0); 
	// int len2 = printf("|% -30d||% -30i|\n", 0,0);

	// int len1 = ft_printf("|% -30d||% -30i|\n", -20,-20); 
	// int len2 = printf("|% -30d||% -30i|\n", -20,-20);

	// int len1 = ft_printf("|% -30d||% -30i|\n", 20,20);
	// int len2 = printf("|% -30d||% -30i|\n", 20,20);

	// int len1 = ft_printf("|% -30d||% -30i|\n", -2147483648,-2147483648); 
	// int len2 = printf("|% -30d||% -30i|\n", -2147483648,-2147483648);

	// int len1 = ft_printf("|% -30d||% -30i|\n", 2147483647 ,2147483647 ); 
	// int len2 = printf("|% -30d||% -30i|\n", 2147483647 ,2147483647 );

	// int len1 = ft_printf("|% -30d||% -30i|\n", 214748364756,214748364756); 
	// int len2 = printf("|% -30d||% -30i|\n", 214748364756,214748364756);

	// int len1 = ft_printf("|% -30d||% -30i|\n", -214748364756,-214748364756); 
	// int len2 = printf("|% -30d||% -30i|\n", -214748364756,-214748364756);

	// int len1 = ft_printf("|%+030d||%+030i|\n",0,0); 
	// int len2 = printf("|%+030d||%+030i|\n",0,0);

	// int len1 = ft_printf("|%+030d||%+030i|\n",-20,-20); 
	// int len2 = printf("|%+030d||%+030i|\n",-20,-20);

	// int len1 = ft_printf("|%+030d||%+030i|\n", 20,20);
	// int len2 = printf("|%+030d||%+030i|\n", 20,20);

	// int len1 = ft_printf("|%+030d||%+030i|\n",-2147483648,-2147483648); 
	// int len2 = printf("|%+030d||%+030i|\n",-2147483648,-2147483648);

	// int len1 = ft_printf("|%+030d||%+030i|\n", 2147483647 ,2147483647 ); 
	// int len2 = printf("|%+030d||%+030i|\n", 2147483647 ,2147483647 );

	// int len1 = ft_printf("|%+030d||%+030i|\n", 214748364756,214748364756); 
	// int len2 = printf("|%+030d||%+030i|\n", 214748364756,214748364756);

	// int len1 = ft_printf("|%+030d||%+030i|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%+030d||%+030i|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|% 030d||% 030i|\n",0,0); 
	// int len2 = printf("|% 030d||% 030i|\n",0,0);

	// int len1 = ft_printf("|% 030d||% 030i|\n",-20,-20); 
	// int len2 = printf("|% 030d||% 030i|\n",-20,-20);

	// int len1 = ft_printf("|% 030d||% 030i|\n", 20,20);
	// int len2 = printf("|% 030d||% 030i|\n", 20,20);

	// int len1 = ft_printf("|% 030d||% 030i|\n",-2147483648,-2147483648); 
	// int len2 = printf("|% 030d||% 030i|\n",-2147483648,-2147483648);

	// int len1 = ft_printf("|% 030d||% 030i|\n", 2147483647 ,2147483647 ); 
	// int len2 = printf("|% 030d||% 030i|\n", 2147483647 ,2147483647 );

	// int len1 = ft_printf("|% 030d||% 030i|\n", 214748364756,214748364756); 
	// int len2 = printf("|% 030d||% 030i|\n", 214748364756,214748364756);

	// int len1 = ft_printf("|% 030d||% 030i|\n",-214748364756,-214748364756); 
	// int len2 = printf("|% 030d||% 030i|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%+30d||%+30i|\n",0,0); 
	// int len2 = printf("|%+30d||%+30i|\n",0,0);

	// int len1 = ft_printf("|%+30d||%+30i|\n",-20,-20); 
	// int len2 = printf("|%+30d||%+30i|\n",-20,-20);

	// int len1 = ft_printf("|%+30d||%+30i|\n", 20,20);
	// int len2 = printf("|%+30d||%+30i|\n", 20,20);

	// int len1 = ft_printf("|%+30d||%+30i|\n",-2147483648,-2147483648); 
	// int len2 = printf("|%+30d||%+30i|\n",-2147483648,-2147483648);

	// int len1 = ft_printf("|%+30d||%+30i|\n", 2147483647 ,2147483647 ); 
	// int len2 = printf("|%+30d||%+30i|\n", 2147483647 ,2147483647 );

	// int len1 = ft_printf("|%+30d||%+30i|\n", 214748364756,214748364756); 
	// int len2 = printf("|%+30d||%+30i|\n", 214748364756,214748364756);

	// int len1 = ft_printf("|%+30d||%+30i|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%+30d||%+30i|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%-30d||%-30i|\n",0,0); 
	// int len2 = printf("|%-30d||%-30i|\n",0,0);

	// int len1 = ft_printf("|%-30d||%-30i|\n",-20,-20); 
	// int len2 = printf("|%-30d||%-30i|\n",-20,-20);

	// int len1 = ft_printf("|%-30d||%-30i|\n", 20,20);
	// int len2 = printf("|%-30d||%-30i|\n", 20,20);

	// int len1 = ft_printf("|%-30d||%-30i|\n",-2147483648,-2147483648); 
	// int len2 = printf("|%-30d||%-30i|\n",-2147483648,-2147483648);

	// int len1 = ft_printf("|%-30d||%-30i|\n", 2147483647 ,2147483647 ); 
	// int len2 = printf("|%-30d||%-30i|\n", 2147483647 ,2147483647 );

	// int len1 = ft_printf("|%-30d||%-30i|\n", 214748364756,214748364756); 
	// int len2 = printf("|%-30d||%-30i|\n", 214748364756,214748364756);

	// int len1 = ft_printf("|%-30d||%-30i|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%-30d||%-30i|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%030d||%030i|\n",0,0); 
	// int len2 = printf("|%030d||%030i|\n",0,0);

	// int len1 = ft_printf("|%030d||%030i|\n",-20,-20); 
	// int len2 = printf("|%030d||%030i|\n",-20,-20);

	// int len1 = ft_printf("|%030d||%030i|\n", 20,20);
	// int len2 = printf("|%030d||%030i|\n", 20,20);

	// int len1 = ft_printf("|%030d||%030i|\n",-2147483648,-2147483648); 
	// int len2 = printf("|%030d||%030i|\n",-2147483648,-2147483648);

	// int len1 = ft_printf("|%030d||%030i|\n", 2147483647 ,2147483647 ); 
	// int len2 = printf("|%030d||%030i|\n", 2147483647 ,2147483647 );

	// int len1 = ft_printf("|%030d||%030i|\n", 214748364756,214748364756); 
	// int len2 = printf("|%030d||%030i|\n", 214748364756,214748364756);

	// int len1 = ft_printf("|%030d||%030i|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%030d||%030i|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|% 30d||% 30i|\n",0,0); 
	// int len2 = printf("|% 30d||% 30i|\n",0,0);

	// int len1 = ft_printf("|% 30d||% 30i|\n",-20,-20); 
	// int len2 = printf("|% 30d||% 30i|\n",-20,-20);

	// int len1 = ft_printf("|% 30d||% 30i|\n", 20,20);
	// int len2 = printf("|% 30d||% 30i|\n", 20,20);

	// int len1 = ft_printf("|% 30d||% 30i|\n",-2147483648,-2147483648); 
	// int len2 = printf("|% 30d||% 30i|\n",-2147483648,-2147483648);

	// int len1 = ft_printf("|% 30d||% 30i|\n", 2147483647 ,2147483647 ); 
	// int len2 = printf("|% 30d||% 30i|\n", 2147483647 ,2147483647 );

	// int len1 = ft_printf("|% 30d||% 30i|\n", 214748364756,214748364756); 
	// int len2 = printf("|% 30d||% 30i|\n", 214748364756,214748364756);

	// int len1 = ft_printf("|% 30d||% 30i|\n",-214748364756,-214748364756); 
	// int len2 = printf("|% 30d||% 30i|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%.30d||%.30i|\n",0,0); 
	// int len2 = printf("|%.30d||%.30i|\n",0,0);
	
	// int len1 = ft_printf("|%.30d||%.30i|\n",-20,-20); 
	// int len2 = printf("|%.30d||%.30i|\n",-20,-20);

	// int len1 = ft_printf("|%.30d||%.30i|\n", 20,20);
	// int len2 = printf("|%.30d||%.30i|\n", 20,20);

	// int len1 = ft_printf("|%.30d||%.30i|\n",-2147483648,-2147483648); 
	// int len2 = printf("|%.30d||%.30i|\n",-2147483648,-2147483648);

	// int len1 = ft_printf("|%.30d||%.30i|\n", 2147483647 ,2147483647 ); 
	// int len2 = printf("|%.30d||%.30i|\n", 2147483647 ,2147483647 );

	// int len1 = ft_printf("|%.30d||%.30i|\n", 214748364756,214748364756); 
	// int len2 = printf("|%.30d||%.30i|\n", 214748364756,214748364756);

	// int len1 = ft_printf("|%.30d||%.30i|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%.30d||%.30i|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%+.30d||%+.30i|\n",0,0); 
	// int len2 = printf("|%+.30d||%+.30i|\n",0,0);

	// int len1 = ft_printf("|%+.30d||%+.30i|\n",-20,-20); 
	// int len2 = printf("|%+.30d||%+.30i|\n",-20,-20);

	// int len1 = ft_printf("|%+.30d||%+.30i|\n", 20,20);
	// int len2 = printf("|%+.30d||%+.30i|\n", 20,20);

	// int len1 = ft_printf("|%+.30d||%+.30i|\n",-2147483648,-2147483648); 
	// int len2 = printf("|%+.30d||%+.30i|\n",-2147483648,-2147483648);

	// int len1 = ft_printf("|%+.30d||%+.30i|\n", 2147483647 ,2147483647 ); 
	// int len2 = printf("|%+.30d||%+.30i|\n", 2147483647 ,2147483647 );

	// int len1 = ft_printf("|%+.30d||%+.30i|\n", 214748364756,214748364756); 
	// int len2 = printf("|%+.30d||%+.30i|\n", 214748364756,214748364756);

	// int len1 = ft_printf("|%+.30d||%+.30i|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%+.30d||%+.30i|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|% .30d||% .30i|\n",0,0); 
	// int len2 = printf("|% .30d||% .30i|\n",0,0);

	// int len1 = ft_printf("|% .30d||% .30i|\n",-20,-20); 
	// int len2 = printf("|% .30d||% .30i|\n",-20,-20);

	// int len1 = ft_printf("|% .30d||% .30i|\n", 20,20);
	// int len2 = printf("|% .30d||% .30i|\n", 20,20);

	// int len1 = ft_printf("|% .30d||% .30i|\n",-2147483648,-2147483648); 
	// int len2 = printf("|% .30d||% .30i|\n",-2147483648,-2147483648);

	// int len1 = ft_printf("|% .30d||% .30i|\n", 2147483647 ,2147483647 ); 
	// int len2 = printf("|% .30d||% .30i|\n", 2147483647 ,2147483647 );

	// int len1 = ft_printf("|% .30d||% .30i|\n", 214748364756,214748364756); 
	// int len2 = printf("|% .30d||% .30i|\n", 214748364756,214748364756);

	// int len1 = ft_printf("|%+- 0#.30d||%+- 0#.30i|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%+- 0#.30d||%+- 0#.30i|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%35.30d||%35.30i|\n",0,0); 
	// int len2 = printf("|%35.30d||%35.30i|\n",0,0);

	// int len1 = ft_printf("|%35.30d||%35.30i|\n",-20,-20); 
	// int len2 = printf("|%35.30d||%35.30i|\n",-20,-20);

	// int len1 = ft_printf("|%35.30d||%35.30i|\n", 20,20);
	// int len2 = printf("|%35.30d||%35.30i|\n", 20,20);

	// int len1 = ft_printf("|%35.30d||%35.30i|\n",-2147483648,-2147483648); 
	// int len2 = printf("|%35.30d||%35.30i|\n",-2147483648,-2147483648);

	// int len1 = ft_printf("|%35.30d||%35.30i|\n", 2147483647 ,2147483647 ); 
	// int len2 = printf("|%35.30d||%35.30i|\n", 2147483647 ,2147483647 );

	// int len1 = ft_printf("|%35.30d||%35.30i|\n", 214748364756,214748364756); 
	// int len2 = printf("|%35.30d||%35.30i|\n", 214748364756,214748364756);

	// int len1 = ft_printf("|%+- 0#35.30d||%+- 0#35.30i|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%+- 0#35.30d||%+- 0#35.30i|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%+-35.30d||%+-35.30i|\n",0,0); 
	// int len2 = printf("|%+-35.30d||%+-35.30i|\n",0,0);
	
	// int len1 = ft_printf("|%+-35.30d||%+-35.30i|\n",-20,-20); 
	// int len2 = printf("|%+-35.30d||%+-35.30i|\n",-20,-20);

	// int len1 = ft_printf("|%+-35.30d||%+-35.30i|\n", 20,20);
	// int len2 = printf("|%+-35.30d||%+-35.30i|\n", 20,20);

	// int len1 = ft_printf("|%+-35.30d||%+-35.30i|\n",-2147483648,-2147483648); 
	// int len2 = printf("|%+-35.30d||%+-35.30i|\n",-2147483648,-2147483648);

	// int len1 = ft_printf("|%+-35.30d||%+-35.30i|\n", 2147483647 ,2147483647 ); 
	// int len2 = printf("|%+-35.30d||%+-35.30i|\n", 2147483647 ,2147483647 );

	// int len1 = ft_printf("|%+-35.30d||%+-35.30i|\n", 214748364756,214748364756); 
	// int len2 = printf("|%+-35.30d||%+-35.30i|\n", 214748364756,214748364756);

	// int len1 = ft_printf("|%+- 0#35.30d||%+- 0#35.30i|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%+- 0#35.30d||%+- 0#35.30i|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%- 35.30d||%- 35.30i|\n",0,0); 
	// int len2 = printf("|%- 35.30d||%- 35.30i|\n",0,0);

	// int len1 = ft_printf("|%- 35.30d||%- 35.30i|\n",-20,-20); 
	// int len2 = printf("|%- 35.30d||%- 35.30i|\n",-20,-20);

	// int len1 = ft_printf("|%- 35.30d||%- 35.30i|\n", 20,20);
	// int len2 = printf("|%- 35.30d||%- 35.30i|\n", 20,20);

	// int len1 = ft_printf("|%- 35.30d||%- 35.30i|\n",-2147483648,-2147483648); 
	// int len2 = printf("|%- 35.30d||%- 35.30i|\n",-2147483648,-2147483648);

	// int len1 = ft_printf("|%- 35.30d||%- 35.30i|\n", 2147483647 ,2147483647 ); 
	// int len2 = printf("|%- 35.30d||%- 35.30i|\n", 2147483647 ,2147483647 );

	// int len1 = ft_printf("|%- 35.30d||%- 35.30i|\n", 214748364756,214748364756); 
	// int len2 = printf("|%- 35.30d||%- 35.30i|\n", 214748364756,214748364756);

	// int len1 = ft_printf("|%-  0#35.30d||%-  0#35.30i|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%-  0#35.30d||%-  0#35.30i|\n",-214748364756,-214748364756);

	// 	int len1 = ft_printf("|%035.30d||%035.30i|\n",0,0); 
	// int len2 = printf("|%035.30d||%035.30i|\n",0,0);

	// int len1 = ft_printf("|%035.30d||%035.30i|\n",-20,-20); 
	// int len2 = printf("|%035.30d||%035.30i|\n",-20,-20);

	// int len1 = ft_printf("|%035.30d||%035.30i|\n", 20,20);
	// int len2 = printf("|%035.30d||%035.30i|\n", 20,20);

	// int len1 = ft_printf("|%035.30d||%035.30i|\n",-2147483648,-2147483648); 
	// int len2 = printf("|%035.30d||%035.30i|\n",-2147483648,-2147483648);

	// int len1 = ft_printf("|%035.30d||%035.30i|\n", 2147483647 ,2147483647 ); 
	// int len2 = printf("|%035.30d||%035.30i|\n", 2147483647 ,2147483647 );

	// int len1 = ft_printf("|%035.30d||%035.30i|\n", 214748364756,214748364756); 
	// int len2 = printf("|%035.30d||%035.30i|\n", 214748364756,214748364756);

	// int len1 = ft_printf("|%0#35.30d||%0#35.30i|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%0#35.30d||%0#35.30i|\n",-214748364756,-214748364756);

	// 	int len1 = ft_printf("|%+35.30d||%+35.30i|\n",0,0); 
	// int len2 = printf("|%+35.30d||%+35.30i|\n",0,0);

	// int len1 = ft_printf("|%+35.30d||%+35.30i|\n",-20,-20); 
	// int len2 = printf("|%+35.30d||%+35.30i|\n",-20,-20);

	// int len1 = ft_printf("|%+35.30d||%+35.30i|\n", 20,20);
	// int len2 = printf("|%+35.30d||%+35.30i|\n", 20,20);

	// int len1 = ft_printf("|%+35.30d||%+35.30i|\n",-2147483648,-2147483648); 
	// int len2 = printf("|%+35.30d||%+35.30i|\n",-2147483648,-2147483648);

	// int len1 = ft_printf("|%+35.30d||%+35.30i|\n", 2147483647 ,2147483647 ); 
	// int len2 = printf("|%+35.30d||%+35.30i|\n", 2147483647 ,2147483647 );

	// int len1 = ft_printf("|%+35.30d||%+35.30i|\n", 214748364756,214748364756); 
	// int len2 = printf("|%+35.30d||%+35.30i|\n", 214748364756,214748364756);

	// int len1 = ft_printf("|%+35.30d||%+35.30i|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%+35.30d||%+35.30i|\n",-214748364756,-214748364756);

	// 	int len1 = ft_printf("|% 35.30d||% 35.30i|\n",0,0); 
	// int len2 = printf("|% 35.30d||% 35.30i|\n",0,0);

	// int len1 = ft_printf("|% 35.30d||% 35.30i|\n",-20,-20); 
	// int len2 = printf("|% 35.30d||% 35.30i|\n",-20,-20);

	// int len1 = ft_printf("|% 35.30d||% 35.30i|\n", 20,20);
	// int len2 = printf("|% 35.30d||% 35.30i|\n", 20,20);

	// int len1 = ft_printf("|% 35.30d||% 35.30i|\n",-2147483648,-2147483648); 
	// int len2 = printf("|% 35.30d||% 35.30i|\n",-2147483648,-2147483648);

	// int len1 = ft_printf("|% 35.30d||% 35.30i|\n", 2147483647 ,2147483647 ); 
	// int len2 = printf("|% 35.30d||% 35.30i|\n", 2147483647 ,2147483647 );

	// int len1 = ft_printf("|% 35.30d||% 35.30i|\n", 214748364756,214748364756); 
	// int len2 = printf("|% 35.30d||% 35.30i|\n", 214748364756,214748364756);

	// int len1 = ft_printf("|% 35.30d||% 35.30i|\n",-214748364756,-214748364756); 
	// int len2 = printf("|% 35.30d||% 35.30i|\n",-214748364756,-214748364756);

	// 	int len1 = ft_printf("|%-35.30d||%-35.30i|\n",0,0); 
	// int len2 = printf("|%-35.30d||%-35.30i|\n",0,0);

	// int len1 = ft_printf("|%-35.30d||%-35.30i|\n",-20,-20); 
	// int len2 = printf("|%-35.30d||%-35.30i|\n",-20,-20);

	// int len1 = ft_printf("|%-35.30d||%-35.30i|\n", 20,20);
	// int len2 = printf("|%-35.30d||%-35.30i|\n", 20,20);

	// int len1 = ft_printf("|%-35.30d||%-35.30i|\n",-2147483648,-2147483648); 
	// int len2 = printf("|%-35.30d||%-35.30i|\n",-2147483648,-2147483648);

	// int len1 = ft_printf("|%-35.30d||%-35.30i|\n", 2147483647 ,2147483647 ); 
	// int len2 = printf("|%-35.30d||%-35.30i|\n", 2147483647 ,2147483647 );

	// int len1 = ft_printf("|%-35.30d||%-35.30i|\n", 214748364756,214748364756); 
	// int len2 = printf("|%-35.30d||%-35.30i|\n", 214748364756,214748364756);

	// 		int len1 = ft_printf("|%-25.30d||%-25.30i|\n",0,0); 
	// int len2 = printf("|%-25.30d||%-25.30i|\n",0,0);

	// 	int len1 = ft_printf("|%-25.30d||%-25.30i|\n",-20,-20); 
	// int len2 = printf("|%-25.30d||%-25.30i|\n",-20,-20);

	// int len1 = ft_printf("|%-25.30d||%-25.30i|\n", 20,20);
	// int len2 = printf("|%-25.30d||%-25.30i|\n", 20,20);

	// int len1 = ft_printf("|%-25.30d||%-25.30i|\n",-2147483648,-2147483648); 
	// int len2 = printf("|%-25.30d||%-25.30i|\n",-2147483648,-2147483648);

	// int len1 = ft_printf("|%-25.30d||%-25.30i|\n", 2147483647 ,2147483647 ); 
	// int len2 = printf("|%-25.30d||%-25.30i|\n", 2147483647 ,2147483647 );

	// int len1 = ft_printf("|%-25.30d||%-25.30i|\n", 214748364756,214748364756); 
	// int len2 = printf("|%-25.30d||%-25.30i|\n", 214748364756,214748364756);

	// 		int len1 = ft_printf("|%+-0 #  ++--25.30d||%+-0 #  ++--25.30i|\n",0,0); 
	// int len2 = printf("|%+-0 #  ++--25.30d||%+-0 #  ++--25.30i|\n",0,0);

	// 	int len1 = ft_printf("|%+-0 #  ++--25.30d||%+-0 #  ++--25.30i|\n",-20,-20); 
	// int len2 = printf("|%+-0 #  ++--25.30d||%+-0 #  ++--25.30i|\n",-20,-20);

	// int len1 = ft_printf("|%+-0 #  ++--25.30d||%+-0 #  ++--25.30i|\n", 20,20);
	// int len2 = printf("|%+-0 #  ++--25.30d||%+-0 #  ++--25.30i|\n", 20,20);

	// int len1 = ft_printf("|%+-0 #  ++--25.30d||%+-0 #  ++--25.30i|\n",-2147483648,-2147483648); 
	// int len2 = printf("|%+-0 #  ++--25.30d||%+-0 #  ++--25.30i|\n",-2147483648,-2147483648);

	// int len1 = ft_printf("|%+-0 #  ++--25.30d||%+-0 #  ++--25.30i|\n", 2147483647 ,2147483647 ); 
	// int len2 = printf("|%+-0 #  ++--25.30d||%+-0 #  ++--25.30i|\n", 2147483647 ,2147483647 );

	// int len1 = ft_printf("|%+-0 #  ++--25.30d||%+-0 #  ++--25.30i|\n", 214748364756,214748364756); 
	// int len2 = printf("|%+-0 #  ++--25.30d||%+-0 #  ++--25.30i|\n", 214748364756,214748364756);

	// 		int len1 = ft_printf("|%+025.30d||%+025.30i|\n",0,0); 
	// int len2 = printf("|%+025.30d||%+025.30i|\n",0,0);

	// 	int len1 = ft_printf("|%+025.30d||%+025.30i|\n",-20,-20); 
	// int len2 = printf("|%+025.30d||%+025.30i|\n",-20,-20);

	// int len1 = ft_printf("|%+025.30d||%+025.30i|\n", 20,20);
	// int len2 = printf("|%+025.30d||%+025.30i|\n", 20,20);

	// int len1 = ft_printf("|%+025.30d||%+025.30i|\n",-2147483648,-2147483648); 
	// int len2 = printf("|%+025.30d||%+025.30i|\n",-2147483648,-2147483648);

	// int len1 = ft_printf("|%+025.30d||%+025.30i|\n", 2147483647 ,2147483647 ); 
	// int len2 = printf("|%+025.30d||%+025.30i|\n", 2147483647 ,2147483647 );

	// int len1 = ft_printf("|%+025.30d||%+025.30i|\n", 214748364756,214748364756); 
	// int len2 = printf("|%+025.30d||%+025.30i|\n", 214748364756,214748364756);
	
	// 		int len1 = ft_printf("|%0 25.30d||%0 25.30i|\n",0,0); 
	// int len2 = printf("|%0 25.30d||%0 25.30i|\n",0,0);

	// 	int len1 = ft_printf("|%0 25.30d||%0 25.30i|\n",-20,-20); 
	// int len2 = printf("|%0 25.30d||%0 25.30i|\n",-20,-20);

	// int len1 = ft_printf("|%0 25.30d||%0 25.30i|\n", 20,20);
	// int len2 = printf("|%0 25.30d||%0 25.30i|\n", 20,20);

	// int len1 = ft_printf("|%0 25.30d||%0 25.30i|\n",-2147483648,-2147483648); 
	// int len2 = printf("|%0 25.30d||%0 25.30i|\n",-2147483648,-2147483648);

	// int len1 = ft_printf("|%0 25.30d||%0 25.30i|\n", 2147483647 ,2147483647 ); 
	// int len2 = printf("|%0 25.30d||%0 25.30i|\n", 2147483647 ,2147483647 );

	// int len1 = ft_printf("|%0 25.30d||%0 25.30i|\n", 214748364756,214748364756); 
	// int len2 = printf("|%0 25.30d||%0 25.30i|\n", 214748364756,214748364756);

	// 	int len1 = ft_printf("|%+035.30d||%+035.30i|\n",0,0); 
	// int len2 = printf("|%+035.30d||%+035.30i|\n",0,0);

	// int len1 = ft_printf("|%+035.30d||%+035.30i|\n",-20,-20); 
	// int len2 = printf("|%+035.30d||%+035.30i|\n",-20,-20);

	// int len1 = ft_printf("|%+035.30d||%+035.30i|\n", 20,20);
	// int len2 = printf("|%+035.30d||%+035.30i|\n", 20,20);

	// int len1 = ft_printf("|%+035.30d||%+035.30i|\n",-2147483648,-2147483648); 
	// int len2 = printf("|%+035.30d||%+035.30i|\n",-2147483648,-2147483648);

	// int len1 = ft_printf("|%+035.30d||%+035.30i|\n", 2147483647 ,2147483647 ); 
	// int len2 = printf("|%+035.30d||%+035.30i|\n", 2147483647 ,2147483647 );

	// int len1 = ft_printf("|%+035.30d||%+035.30i|\n", 214748364756,214748364756); 
	// int len2 = printf("|%+035.30d||%+035.30i|\n", 214748364756,214748364756);
	
	// 		int len1 = ft_printf("|%0 35.30d||%0 35.30i|\n",0,0); 
	// int len2 = printf("|%0 35.30d||%0 35.30i|\n",0,0);

	// 	int len1 = ft_printf("|%0 35.30d||%0 35.30i|\n",-20,-20); 
	// int len2 = printf("|%0 35.30d||%0 35.30i|\n",-20,-20);

	// int len1 = ft_printf("|%0 35.30d||%0 35.30i|\n", 20,20);
	// int len2 = printf("|%0 35.30d||%0 35.30i|\n", 20,20);

	// int len1 = ft_printf("|%0 35.30d||%0 35.30i|\n",-2147483648,-2147483648); 
	// int len2 = printf("|%0 35.30d||%0 35.30i|\n",-2147483648,-2147483648);

	// int len1 = ft_printf("|%0 35.30d||%0 35.30i|\n", 2147483647 ,2147483647 ); 
	// int len2 = printf("|%0 35.30d||%0 35.30i|\n", 2147483647 ,2147483647 );

	// int len1 = ft_printf("|%0 35.30d||%0 35.30i|\n", 214748364756,214748364756); 
	// int len2 = printf("|%0 35.30d||%0 35.30i|\n", 214748364756,214748364756);

	// int len1 = ft_printf("|%0 35.30d||%0 35.30i||%##     25.30s||%##     25.30c|\n", 214748364756,214748364756, "maddddd", 'a'); //check the zero padding for c and s
	// int len2 = printf("|%0 35.30d||%0 35.30i||%##     25.30s||%##     25.30c|\n", 214748364756,214748364756, "maddddd", 'a');

	//unsigned numbers u:
	// int len1 = ft_printf("|%u|\n",0,0); 
	// int len2 = printf("|%u|\n",0,0);

	// int len1 = ft_printf("|%u|\n",-20,-20); 
	// int len2 = printf("|%u|\n",-20,-20);

	// int len1 = ft_printf("|%u|\n", 20,20);
	// int len2 = printf("|%u|\n", 20,20);

	// int len1 = ft_printf("|%u|\n",-2147483648); 
	// int len2 = printf("|%u|\n",-2147483648);

	// int len1 = ft_printf("|%u|\n", 2147483647); 
	// int len2 = printf("|%u|\n", 2147483647);

	// int len1 = ft_printf("|%u|\n", 214748364756); 
	// int len2 = printf("|%u|\n", 214748364756);

	// int len1 = ft_printf("|%u|\n",-214748364756); 
	// int len2 = printf("|%u|\n",-214748364756);

	// 	int len1 = ft_printf("|%30u||%30u|\n",0,0); 
	// int len2 = printf("|%30u||%30u|\n",0,0);

	// 	int len1 = ft_printf("|%30u||%30u|\n",-20,-20); 
	// int len2 = printf("|%30u||%30u|\n",-20,-20);

	// int len1 = ft_printf("|%30u||%30u|\n", 20,20);
	// int len2 = printf("|%30u||%30u|\n", 20,20);

	// int len1 = ft_printf("|%30u||%30u|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%30u||%30u|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%30u||%30u|\n", 2147483647,2147483647); 
	// int len2 = printf("|%30u||%30u|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%30u||%30u|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%30u||%30u|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%30u||%30u|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%30u||%30u|\n",-214748364756,-214748364756);

	// 	int len1 = ft_printf("|%-30u||%-30u|\n",0,0); 
	// int len2 = printf("|%-30u||%-30u|\n",0,0);

	// 	int len1 = ft_printf("|%-30u||%-30u|\n",-20,-20); 
	// int len2 = printf("|%-30u||%-30u|\n",-20,-20);

	// int len1 = ft_printf("|%-30u||%-30u|\n", 20,20);
	// int len2 = printf("|%-30u||%-30u|\n", 20,20);

	// int len1 = ft_printf("|%-30u||%-30u|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%-30u||%-30u|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%-30u||%-30u|\n", 2147483647,2147483647); 
	// int len2 = printf("|%-30u||%-30u|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%-30u||%-30u|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%-30u||%-30u|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%-30u||%-30u|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%-30u||%-30u|\n",-214748364756,-214748364756);

	// 	int len1 = ft_printf("|%030u||%030u|\n",0,0); 
	// int len2 = printf("|%030u||%030u|\n",0,0);

	// 	int len1 = ft_printf("|%030u||%030u|\n",-20,-20); 
	// int len2 = printf("|%030u||%030u|\n",-20,-20);

	// int len1 = ft_printf("|%030u||%030u|\n", 20,20);
	// int len2 = printf("|%030u||%030u|\n", 20,20);

	// int len1 = ft_printf("|%030u||%030u|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%030u||%030u|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%030u||%030u|\n", 2147483647,2147483647); 
	// int len2 = printf("|%030u||%030u|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%030u||%030u|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%030u||%030u|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%030u||%030u|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%030u||%030u|\n",-214748364756,-214748364756);

	// 	int len1 = ft_printf("|%+- #030u||%+- #030u|\n",0,0); 
	// int len2 = printf("|%+- #030u||%+- #030u|\n",0,0);

	// 	int len1 = ft_printf("|%+- #030u||%+- #030u|\n",-20,-20); 
	// int len2 = printf("|%+- #030u||%+- #030u|\n",-20,-20);

	// int len1 = ft_printf("|%+- #030u||%+- #030u|\n", 20,20);
	// int len2 = printf("|%+- #030u||%+- #030u|\n", 20,20);

	// int len1 = ft_printf("|%+- #030u||%+- #030u|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%+- #030u||%+- #030u|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%+- #030u||%+- #030u|\n", 2147483647,2147483647); 
	// int len2 = printf("|%+- #030u||%+- #030u|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%+- #030u||%+- #030u|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%+- #030u||%+- #030u|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%+- #030u||%+- #030u|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%+- #030u||%+- #030u|\n",-214748364756,-214748364756);

	// 	int len1 = ft_printf("|%+30u||%+30u|\n",0,0); 
	// int len2 = printf("|%+30u||%+30u|\n",0,0);

	// 	int len1 = ft_printf("|%+30u||%+30u|\n",-20,-20); 
	// int len2 = printf("|%+30u||%+30u|\n",-20,-20);

	// int len1 = ft_printf("|%+30u||%+30u|\n", 20,20);
	// int len2 = printf("|%+30u||%+30u|\n", 20,20);

	// int len1 = ft_printf("|%+30u||%+30u|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%+30u||%+30u|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%+30u||%+30u|\n", 2147483647,2147483647); 
	// int len2 = printf("|%+30u||%+30u|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%+30u||%+30u|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%+30u||%+30u|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%+30u||%+30u|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%+30u||%+30u|\n",-214748364756,-214748364756);

	// 	int len1 = ft_printf("|% 30u||% 30u|\n",0,0); 
	// int len2 = printf("|% 30u||% 30u|\n",0,0);

	// int len1 = ft_printf("|% 30u||% 30u|\n", 20,20);
	// int len2 = printf("|% 30u||% 30u|\n", 20,20);

	// int len1 = ft_printf("|% 30u||% 30u|\n",-2147483648, -2147483648); 
	// int len2 = printf("|% 30u||% 30u|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|% 30u||% 30u|\n", 2147483647,2147483647); 
	// int len2 = printf("|% 30u||% 30u|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|% 30u||% 30u|\n", 214748364756, 214748364756); 
	// int len2 = printf("|% 30u||% 30u|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|% 30u||% 30u|\n",-214748364756,-214748364756); 
	// int len2 = printf("|% 30u||% 30u|\n",-214748364756,-214748364756);

	// 	int len1 = ft_printf("|%.30u||%.30u|\n",0,0); 
	// int len2 = printf("|%.30u||%.30u|\n",0,0);

	// int len1 = ft_printf("|%.30u||%.30u|\n", 20,20);
	// int len2 = printf("|%.30u||%.30u|\n", 20,20);

	// int len1 = ft_printf("|%.30u||%.30u|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%.30u||%.30u|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%.30u||%.30u|\n", 2147483647,2147483647); 
	// int len2 = printf("|%.30u||%.30u|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%.30u||%.30u|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%.30u||%.30u|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%.30u||%.30u|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%.30u||%.30u|\n",-214748364756,-214748364756);

	// 	int len1 = ft_printf("|%+.30u||%+.30u|\n",0,0); 
	// int len2 = printf("|%+.30u||%+.30u|\n",0,0);

	// int len1 = ft_printf("|%+.30u||%+.30u|\n", 20,20);
	// int len2 = printf("|%+.30u||%+.30u|\n", 20,20);

	// int len1 = ft_printf("|%+.30u||%+.30u|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%+.30u||%+.30u|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%+.30u||%+.30u|\n", 2147483647,2147483647); 
	// int len2 = printf("|%+.30u||%+.30u|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%+.30u||%+.30u|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%+.30u||%+.30u|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%+.30u||%+.30u|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%+.30u||%+.30u|\n",-214748364756,-214748364756);

	// 	int len1 = ft_printf("|%-.30u||%-.30u|\n",0,0); 
	// int len2 = printf("|%-.30u||%-.30u|\n",0,0);

	// int len1 = ft_printf("|%-.30u||%-.30u|\n", 20,20);
	// int len2 = printf("|%-.30u||%-.30u|\n", 20,20);

	// int len1 = ft_printf("|%-.30u||%-.30u|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%-.30u||%-.30u|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%-.30u||%-.30u|\n", 2147483647,2147483647); 
	// int len2 = printf("|%-.30u||%-.30u|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%-.30u||%-.30u|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%-.30u||%-.30u|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%-.30u||%-.30u|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%-.30u||%-.30u|\n",-214748364756,-214748364756);

	// 	int len1 = ft_printf("|%0.30u||%0.30u|\n",0,0); 
	// int len2 = printf("|%0.30u||%0.30u|\n",0,0);

	// int len1 = ft_printf("|%0.30u||%0.30u|\n", 20,20);
	// int len2 = printf("|%0.30u||%0.30u|\n", 20,20);

	// int len1 = ft_printf("|%0.30u||%0.30u|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%0.30u||%0.30u|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%0.30u||%0.30u|\n", 2147483647,2147483647); 
	// int len2 = printf("|%0.30u||%0.30u|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%0.30u||%0.30u|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%0.30u||%0.30u|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%0.30u||%0.30u|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%0.30u||%0.30u|\n",-214748364756,-214748364756);

	// 	int len1 = ft_printf("|% .30u||% .30u|\n",0,0); 
	// int len2 = printf("|% .30u||% .30u|\n",0,0);

	// int len1 = ft_printf("|% .30u||% .30u|\n", 20,20);
	// int len2 = printf("|% .30u||% .30u|\n", 20,20);

	// int len1 = ft_printf("|% .30u||% .30u|\n",-2147483648, -2147483648); 
	// int len2 = printf("|% .30u||% .30u|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|% .30u||% .30u|\n", 2147483647,2147483647); 
	// int len2 = printf("|% .30u||% .30u|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|% .30u||% .30u|\n", 214748364756, 214748364756); 
	// int len2 = printf("|% .30u||% .30u|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|% .30u||% .30u|\n",-214748364756,-214748364756); 
	// int len2 = printf("|% .30u||% .30u|\n",-214748364756,-214748364756);

	// 	int len1 = ft_printf("|% .30u||% .30u|\n",0,0); 
	// int len2 = printf("|% .30u||% .30u|\n",0,0);

	// int len1 = ft_printf("|% .30u||% .30u|\n", 20,20);
	// int len2 = printf("|% .30u||% .30u|\n", 20,20);

	// int len1 = ft_printf("|% .30u||% .30u|\n",-2147483648, -2147483648); 
	// int len2 = printf("|% .30u||% .30u|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|% .30u||% .30u|\n", 2147483647,2147483647); 
	// int len2 = printf("|% .30u||% .30u|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|% .30u||% .30u|\n", 214748364756, 214748364756); 
	// int len2 = printf("|% .30u||% .30u|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|% .30u||% .30u|\n",-214748364756,-214748364756); 
	// int len2 = printf("|% .30u||% .30u|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%25.30u||%25.30u|\n",0,0); 
	// int len2 = printf("|%25.30u||%25.30u|\n",0,0);

	// int len1 = ft_printf("|%25.30u||%25.30u|\n", 20,20);
	// int len2 = printf("|%25.30u||%25.30u|\n", 20,20);

	// int len1 = ft_printf("|%25.30u||%25.30u|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%25.30u||%25.30u|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%25.30u||%25.30u|\n", 2147483647,2147483647); 
	// int len2 = printf("|%25.30u||%25.30u|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%25.30u||%25.30u|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%25.30u||%25.30u|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%25.30u||%25.30u|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%25.30u||%25.30u|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%+-0 #   25.30u||%+-0 #   25.30u|\n",0,0); 
	// int len2 = printf("|%+-0 #   25.30u||%+-0 #   25.30u|\n",0,0);

	// int len1 = ft_printf("|%+-0 #   25.30u||%+-0 #   25.30u|\n", 20,20);
	// int len2 = printf("|%+-0 #   25.30u||%+-0 #   25.30u|\n", 20,20);

	// int len1 = ft_printf("|%+-0 #   25.30u||%+-0 #   25.30u|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%+-0 #   25.30u||%+-0 #   25.30u|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%+-0 #   25.30u||%+-0 #   25.30u|\n", 2147483647,2147483647); 
	// int len2 = printf("|%+-0 #   25.30u||%+-0 #   25.30u|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%+-0 #   25.30u||%+-0 #   25.30u|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%+-0 #   25.30u||%+-0 #   25.30u|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%+-0 #   25.30u||%+-0 #   25.30u|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%+-0 #   25.30u||%+-0 #   25.30u|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%35.30u||%35.30u|\n",0,0); 
	// int len2 = printf("|%35.30u||%35.30u|\n",0,0);

	// int len1 = ft_printf("|%35.30u||%35.30u|\n", 20,20);
	// int len2 = printf("|%35.30u||%35.30u|\n", 20,20);

	// int len1 = ft_printf("|%35.30u||%35.30u|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%35.30u||%35.30u|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%35.30u||%35.30u|\n", 2147483647,2147483647); 
	// int len2 = printf("|%35.30u||%35.30u|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%35.30u||%35.30u|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%35.30u||%35.30u|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%35.30u||%35.30u|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%35.30u||%35.30u|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%-35.30u||%-35.30u|\n",0,0); 
	// int len2 = printf("|%-35.30u||%-35.30u|\n",0,0);

	// int len1 = ft_printf("|%-35.30u||%-35.30u|\n", 20,20);
	// int len2 = printf("|%-35.30u||%-35.30u|\n", 20,20);

	// int len1 = ft_printf("|%-35.30u||%-35.30u|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%-35.30u||%-35.30u|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%-35.30u||%-35.30u|\n", 2147483647,2147483647); 
	// int len2 = printf("|%-35.30u||%-35.30u|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%-35.30u||%-35.30u|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%-35.30u||%-35.30u|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%-35.30u||%-35.30u|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%-35.30u||%-35.30u|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%+35.30u||%+35.30u|\n",0,0); 
	// int len2 = printf("|%+35.30u||%+35.30u|\n",0,0);

	// int len1 = ft_printf("|%+35.30u||%+35.30u|\n", 20,20);
	// int len2 = printf("|%+35.30u||%+35.30u|\n", 20,20);

	// int len1 = ft_printf("|%+35.30u||%+35.30u|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%+35.30u||%+35.30u|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%+35.30u||%+35.30u|\n", 2147483647,2147483647); 
	// int len2 = printf("|%+35.30u||%+35.30u|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%+35.30u||%+35.30u|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%+35.30u||%+35.30u|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%+35.30u||%+35.30u|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%+35.30u||%+35.30u|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%035.30u||%035.30u|\n",0,0); 
	// int len2 = printf("|%035.30u||%035.30u|\n",0,0);

	// int len1 = ft_printf("|%035.30u||%035.30u|\n", 20,20);
	// int len2 = printf("|%035.30u||%035.30u|\n", 20,20);

	// int len1 = ft_printf("|%035.30u||%035.30u|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%035.30u||%035.30u|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%035.30u||%035.30u|\n", 2147483647,2147483647); 
	// int len2 = printf("|%035.30u||%035.30u|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%035.30u||%035.30u|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%035.30u||%035.30u|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%035.30u||%035.30u|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%035.30u||%035.30u|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%-35.30u||%-35.30u|\n",0,0); 
	// int len2 = printf("|%-35.30u||%-35.30u|\n",0,0);

	// int len1 = ft_printf("|%-35.30u||%-35.30u|\n", 20,20);
	// int len2 = printf("|%-35.30u||%-35.30u|\n", 20,20);

	// int len1 = ft_printf("|%-35.30u||%-35.30u|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%-35.30u||%-35.30u|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%-35.30u||%-35.30u|\n", 2147483647,2147483647); 
	// int len2 = printf("|%-35.30u||%-35.30u|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%-35.30u||%-35.30u|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%-35.30u||%-35.30u|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%-35.30u||%-35.30u|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%-35.30u||%-35.30u|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|% 35.30u||% 35.30u|\n",0,0); 
	// int len2 = printf("|% 35.30u||% 35.30u|\n",0,0);

	// int len1 = ft_printf("|% 35.30u||% 35.30u|\n", 20,20);
	// int len2 = printf("|% 35.30u||% 35.30u|\n", 20,20);

	// int len1 = ft_printf("|% 35.30u||% 35.30u|\n",-2147483648, -2147483648); 
	// int len2 = printf("|% 35.30u||% 35.30u|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|% 35.30u||% 35.30u|\n", 2147483647,2147483647); 
	// int len2 = printf("|% 35.30u||% 35.30u|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|% 35.30u||% 35.30u|\n", 214748364756, 214748364756); 
	// int len2 = printf("|% 35.30u||% 35.30u|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|% 35.30u||% 35.30u|\n",-214748364756,-214748364756); 
	// int len2 = printf("|% 35.30u||% 35.30u|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%+-0   ##35.30u||%+-0   ##35.30u|\n",0,0); 
	// int len2 = printf("|%+-0   ##35.30u||%+-0   ##35.30u|\n",0,0);

	// int len1 = ft_printf("|%+-0   ##35.30u||%+-0   ##35.30u|\n", 20,20);
	// int len2 = printf("|%+-0   ##35.30u||%+-0   ##35.30u|\n", 20,20);

	// int len1 = ft_printf("|%+-0   ##35.30u||%+-0   ##35.30u|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%+-0   ##35.30u||%+-0   ##35.30u|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%+-0   ##35.30u||%+-0   ##35.30u|\n", 2147483647,2147483647); 
	// int len2 = printf("|%+-0   ##35.30u||%+-0   ##35.30u|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%+-0   ##35.30u||%+-0   ##35.30u|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%+-0   ##35.30u||%+-0   ##35.30u|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%+-0   ##35.30u||%+-0   ##35.30u|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%+-0   ##35.30u||%+-0   ##35.30u|\n",-214748364756,-214748364756);

	// hexadecimal number lower case 'x':

	// int len1 = ft_printf("|%x||%x|\n",0,0); 
	// int len2 = printf("|%x||%x|\n",0,0);

	// int len1 = ft_printf("|%x||%x|\n", 20,20);
	// int len2 = printf("|%x||%x|\n", 20,20);

	// int len1 = ft_printf("|%x||%x|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%x||%x|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%x||%x|\n", 2147483647,2147483647); 
	// int len2 = printf("|%x||%x|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%x||%x|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%x||%x|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%x||%x|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%x||%x|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%#x||%#x|\n",0,0); 
	// int len2 = printf("|%#x||%#x|\n",0,0);

	// int len1 = ft_printf("|%#x||%#x|\n", 20,20);
	// int len2 = printf("|%#x||%#x|\n", 20,20);

	// int len1 = ft_printf("|%#x||%#x|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%#x||%#x|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%#x||%#x|\n", 2147483647,2147483647); 
	// int len2 = printf("|%#x||%#x|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%#x||%#x|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%#x||%#x|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%#x||%#x|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%#x||%#x|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%30x||%30x|\n",0,0); 
	// int len2 = printf("|%30x||%30x|\n",0,0);

	// int len1 = ft_printf("|%30x||%30x|\n", 20,20);
	// int len2 = printf("|%30x||%30x|\n", 20,20);

	// int len1 = ft_printf("|%30x||%30x|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%30x||%30x|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%30x||%30x|\n", 2147483647,2147483647); 
	// int len2 = printf("|%30x||%30x|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%30x||%30x|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%30x||%30x|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%30x||%30x|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%30x||%30x|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%-#30x||%-#30x|\n",0,0); 
	// int len2 = printf("|%-#30x||%-#30x|\n",0,0);

	// int len1 = ft_printf("|%-#30x||%-#30x|\n", 20,20);
	// int len2 = printf("|%-#30x||%-#30x|\n", 20,20);

	// int len1 = ft_printf("|%-#30x||%-#30x|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%-#30x||%-#30x|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%-#30x||%-#30x|\n", 2147483647,2147483647); 
	// int len2 = printf("|%-#30x||%-#30x|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%-#30x||%-#30x|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%-#30x||%-#30x|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%0#30x||%0#30x|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%0#30x||%0#30x|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%0#30x||%0#30x|\n",0,0); 
	// int len2 = printf("|%0#30x||%0#30x|\n",0,0);

	// int len1 = ft_printf("|%0#30x||%0#30x|\n", 20,20);
	// int len2 = printf("|%0#30x||%0#30x|\n", 20,20);

	// int len1 = ft_printf("|%0#30x||%0#30x|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%0#30x||%0#30x|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%0#30x||%0#30x|\n", 2147483647,2147483647); 
	// int len2 = printf("|%0#30x||%0#30x|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%0#30x||%0#30x|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%0#30x||%0#30x|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%0#30x||%0#30x|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%0#30x||%0#30x|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%#30x||%#30x|\n",0,0); 
	// int len2 = printf("|%#30x||%#30x|\n",0,0);

	// int len1 = ft_printf("|%#30x||%#30x|\n", 20,20);
	// int len2 = printf("|%#30x||%#30x|\n", 20,20);

	// int len1 = ft_printf("|%#30x||%#30x|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%#30x||%#30x|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%#30x||%#30x|\n", 2147483647,2147483647); 
	// int len2 = printf("|%#30x||%#30x|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%#30x||%#30x|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%#30x||%#30x|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%#30x||%#30x|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%#30x||%#30x|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%-30x||%-30x|\n",0,0); 
	// int len2 = printf("|%-30x||%-30x|\n",0,0);

	// int len1 = ft_printf("|%-30x||%-30x|\n", 20,20);
	// int len2 = printf("|%-30x||%-30x|\n", 20,20);

	// int len1 = ft_printf("|%-30x||%-30x|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%-30x||%-30x|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%-30x||%-30x|\n", 2147483647,2147483647); 
	// int len2 = printf("|%-30x||%-30x|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%-30x||%-30x|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%-30x||%-30x|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%-30x||%-30x|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%-30x||%-30x|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%-+#0  ###0  ++--30x||%-+#0  ###0  ++--30x|\n",0,0); 
	// int len2 = printf("|%-+#0  ###0  ++--30x||%-+#0  ###0  ++--30x|\n",0,0);

	// int len1 = ft_printf("|%-+#0  ###0  ++--30x||%-+#0  ###0  ++--30x|\n", 20,20);
	// int len2 = printf("|%-+#0  ###0  ++--30x||%-+#0  ###0  ++--30x|\n", 20,20);

	// int len1 = ft_printf("|%-+#0  ###0  ++--30x||%-+#0  ###0  ++--30x|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%-+#0  ###0  ++--30x||%-+#0  ###0  ++--30x|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%-+#0  ###0  ++--30x||%-+#0  ###0  ++--30x|\n", 2147483647,2147483647); 
	// int len2 = printf("|%-+#0  ###0  ++--30x||%-+#0  ###0  ++--30x|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%-+#0  ###0  ++--30x||%-+#0  ###0  ++--30x|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%-+#0  ###0  ++--30x||%-+#0  ###0  ++--30x|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%-+#0  ###0  ++--30x||%-+#0  ###0  ++--30x|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%-+#0  ###0  ++--30x||%-+#0  ###0  ++--30x|\n",-214748364756,-214748364756);
	
	// int len1 = ft_printf("|%.30x||%.30x|\n",0,0); 
	// int len2 = printf("|%.30x||%.30x|\n",0,0);

	// int len1 = ft_printf("|%.30x||%.30x|\n", 20,20);
	// int len2 = printf("|%.30x||%.30x|\n", 20,20);

	// int len1 = ft_printf("|%.30x||%.30x|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%.30x||%.30x|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%.30x||%.30x|\n", 2147483647,2147483647); 
	// int len2 = printf("|%.30x||%.30x|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%.30x||%.30x|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%.30x||%.30x|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%.30x||%.30x|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%.30x||%.30x|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%#.30x||%#.30x|\n",0,0); 
	// int len2 = printf("|%#.30x||%#.30x|\n",0,0);

	// int len1 = ft_printf("|%#.30x||%#.30x|\n", 20,20);
	// int len2 = printf("|%#.30x||%#.30x|\n", 20,20);

	// int len1 = ft_printf("|%#.30x||%#.30x|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%#.30x||%#.30x|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%#.30x||%#.30x|\n", 2147483647,2147483647); 
	// int len2 = printf("|%#.30x||%#.30x|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%#.30x||%#.30x|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%#.30x||%#.30x|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%#.30x||%#.30x|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%#.30x||%#.30x|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%+#-0   ###-  .30x||%+#-0   ###-  .30x|\n",0,0); 
	// int len2 = printf("|%+#-0   ###-  .30x||%+#-0   ###-  .30x|\n",0,0);

	// int len1 = ft_printf("|%+#-0   ###-  .30x||%+#-0   ###-  .30x|\n", 20,20);
	// int len2 = printf("|%+#-0   ###-  .30x||%+#-0   ###-  .30x|\n", 20,20);

	// int len1 = ft_printf("|%+#-0   ###-  .30x||%+#-0   ###-  .30x|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%+#-0   ###-  .30x||%+#-0   ###-  .30x|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%+#-0   ###-  .30x||%+#-0   ###-  .30x|\n", 2147483647,2147483647); 
	// int len2 = printf("|%+#-0   ###-  .30x||%+#-0   ###-  .30x|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%+#-0   ###-  .30x||%+#-0   ###-  .30x|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%+#-0   ###-  .30x||%+#-0   ###-  .30x|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%+#-0   ###-  .30x||%+#-0   ###-  .30x|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%+#-0   ###-  .30x||%+#-0   ###-  .30x|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%35.30x||%35.30x|\n",0,0); 
	// int len2 = printf("|%35.30x||%35.30x|\n",0,0);

	// int len1 = ft_printf("|%35.30x||%35.30x|\n", 20,20);
	// int len2 = printf("|%35.30x||%35.30x|\n", 20,20);

	// int len1 = ft_printf("|%35.30x||%35.30x|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%35.30x||%35.30x|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%35.30x||%35.30x|\n", 2147483647,2147483647); 
	// int len2 = printf("|%35.30x||%35.30x|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%35.30x||%35.30x|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%35.30x||%35.30x|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%35.30x||%35.30x|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%35.30x||%35.30x|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%-#35.30x||%-#35.30x|\n",0,0); 
	// int len2 = printf("|%-#35.30x||%-#35.30x|\n",0,0);

	// int len1 = ft_printf("|%-#35.30x||%-#35.30x|\n", 20,20);
	// int len2 = printf("|%-#35.30x||%-#35.30x|\n", 20,20);

	// int len1 = ft_printf("|%-#35.30x||%-#35.30x|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%-#35.30x||%-#35.30x|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%-#35.30x||%-#35.30x|\n", 2147483647,2147483647); 
	// int len2 = printf("|%-#35.30x||%-#35.30x|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%-#35.30x||%-#35.30x|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%-#35.30x||%-#35.30x|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%-#35.30x||%-#35.30x|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%-#35.30x||%-#35.30x|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%#35.30x||%#35.30x|\n",0,0); 
	// int len2 = printf("|%#35.30x||%#35.30x|\n",0,0);

	// int len1 = ft_printf("|%#35.30x||%#35.30x|\n", 20,20);
	// int len2 = printf("|%#35.30x||%#35.30x|\n", 20,20);

	// int len1 = ft_printf("|%#35.30x||%#35.30x|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%#35.30x||%#35.30x|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%#35.30x||%#35.30x|\n", 2147483647,2147483647); 
	// int len2 = printf("|%#35.30x||%#35.30x|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%#35.30x||%#35.30x|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%#35.30x||%#35.30x|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%#35.30x||%#35.30x|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%#35.30x||%#35.30x|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%-35.30x||%-35.30x|\n",0,0); 
	// int len2 = printf("|%-35.30x||%-35.30x|\n",0,0);

	// int len1 = ft_printf("|%-35.30x||%-35.30x|\n", 20,20);
	// int len2 = printf("|%-35.30x||%-35.30x|\n", 20,20);

	// int len1 = ft_printf("|%-35.30x||%-35.30x|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%-35.30x||%-35.30x|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%-35.30x||%-35.30x|\n", 2147483647,2147483647); 
	// int len2 = printf("|%-35.30x||%-35.30x|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%-35.30x||%-35.30x|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%-35.30x||%-35.30x|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%-35.30x||%-35.30x|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%-35.30x||%-35.30x|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%35.30x||%35.30x|\n",0,0); 
	// int len2 = printf("|%35.30x||%35.30x|\n",0,0);

	// int len1 = ft_printf("|%35.30x||%35.30x|\n", 20,20);
	// int len2 = printf("|%35.30x||%35.30x|\n", 20,20);

	// int len1 = ft_printf("|%35.30x||%35.30x|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%35.30x||%35.30x|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%35.30x||%35.30x|\n", 2147483647,2147483647); 
	// int len2 = printf("|%35.30x||%35.30x|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%35.30x||%35.30x|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%35.30x||%35.30x|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%35.30x||%35.30x|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%35.30x||%35.30x|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%-+ # 00000035.30x||%-+ # 00000035.30x|\n",0,0); 
	// int len2 = printf("|%-+ # 00000035.30x||%-+ # 00000035.30x|\n",0,0);

	// int len1 = ft_printf("|%-+ # 00000035.30x||%-+ # 00000035.30x|\n", 20,20);
	// int len2 = printf("|%-+ # 00000035.30x||%-+ # 00000035.30x|\n", 20,20);

	// int len1 = ft_printf("|%-+ # 00000035.30x||%-+ # 00000035.30x|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%-+ # 00000035.30x||%-+ # 00000035.30x|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%-+ # 00000035.30x||%-+ # 00000035.30x|\n", 2147483647,2147483647); 
	// int len2 = printf("|%-+ # 00000035.30x||%-+ # 00000035.30x|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%-+ # 00000035.30x||%-+ # 00000035.30x|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%-+ # 00000035.30x||%-+ # 00000035.30x|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%-+ # 00000035.30x||%-+ # 00000035.30x|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%-+ # 00000035.30x||%-+ # 00000035.30x|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%-+ # 00000035.30x||%-+ # 00000035.30x||%-+ # 00000035.30d||%-+ # 00000035.30i|\n",-214748364756,-214748364756,-214748364756,-214748364756); 
	// int len2 = printf("|%-+ # 00000035.30x||%-+ # 00000035.30x||%-+ # 00000035.30d||%-+ # 00000035.30i|\n",-214748364756,-214748364756,-214748364756,-214748364756);

	// hexadecimal number upper 'X':
	
	// int len1 = ft_printf("|%X||%X|\n",0,0); 
	// int len2 = printf("|%X||%X|\n",0,0);

	// int len1 = ft_printf("|%X||%X|\n", 20,20);
	// int len2 = printf("|%X||%X|\n", 20,20);

	// int len1 = ft_printf("|%X||%X|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%X||%X|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%X||%X|\n", 2147483647,2147483647); 
	// int len2 = printf("|%X||%X|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%X||%X|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%X||%X|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%X||%X|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%X||%X|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%#X||%#X|\n",0,0); 
	// int len2 = printf("|%#X||%#X|\n",0,0);

	// int len1 = ft_printf("|%#X||%#X|\n", 20,20);
	// int len2 = printf("|%#X||%#X|\n", 20,20);

	// int len1 = ft_printf("|%#X||%#X|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%#X||%#X|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%#X||%#X|\n", 2147483647,2147483647); 
	// int len2 = printf("|%#X||%#X|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%#X||%#X|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%#X||%#X|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%#X||%#X|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%#X||%#X|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%30X||%30X|\n",0,0); 
	// int len2 = printf("|%30X||%30X|\n",0,0);

	// int len1 = ft_printf("|%30X||%30X|\n", 20,20);
	// int len2 = printf("|%30X||%30X|\n", 20,20);

	// int len1 = ft_printf("|%30X||%30X|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%30X||%30X|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%30X||%30X|\n", 2147483647,2147483647); 
	// int len2 = printf("|%30X||%30X|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%30X||%30X|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%30X||%30X|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%30X||%30X|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%30X||%30X|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%-#30X||%-#30X|\n",0,0); 
	// int len2 = printf("|%-#30X||%-#30X|\n",0,0);

	// int len1 = ft_printf("|%-#30X||%-#30X|\n", 20,20);
	// int len2 = printf("|%-#30X||%-#30X|\n", 20,20);

	// int len1 = ft_printf("|%-#30X||%-#30X|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%-#30X||%-#30X|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%-#30X||%-#30X|\n", 2147483647,2147483647); 
	// int len2 = printf("|%-#30X||%-#30X|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%-#30X||%-#30X|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%-#30X||%-#30X|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%0#30X||%0#30X|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%0#30X||%0#30X|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%0#30X||%0#30X|\n",0,0); 
	// int len2 = printf("|%0#30X||%0#30X|\n",0,0);

	// int len1 = ft_printf("|%0#30X||%0#30X|\n", 20,20);
	// int len2 = printf("|%0#30X||%0#30X|\n", 20,20);

	// int len1 = ft_printf("|%0#30X||%0#30X|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%0#30X||%0#30X|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%0#30X||%0#30X|\n", 2147483647,2147483647); 
	// int len2 = printf("|%0#30X||%0#30X|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%0#30X||%0#30X|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%0#30X||%0#30X|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%0#30X||%0#30X|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%0#30X||%0#30X|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%#30X||%#30X|\n",0,0); 
	// int len2 = printf("|%#30X||%#30X|\n",0,0);

	// int len1 = ft_printf("|%#30X||%#30X|\n", 20,20);
	// int len2 = printf("|%#30X||%#30X|\n", 20,20);

	// int len1 = ft_printf("|%#30X||%#30X|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%#30X||%#30X|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%#30X||%#30X|\n", 2147483647,2147483647); 
	// int len2 = printf("|%#30X||%#30X|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%#30X||%#30X|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%#30X||%#30X|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%#30X||%#30X|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%#30X||%#30X|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%-30X||%-30X|\n",0,0); 
	// int len2 = printf("|%-30X||%-30X|\n",0,0);

	// int len1 = ft_printf("|%-30X||%-30X|\n", 20,20);
	// int len2 = printf("|%-30X||%-30X|\n", 20,20);

	// int len1 = ft_printf("|%-30X||%-30X|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%-30X||%-30X|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%-30X||%-30X|\n", 2147483647,2147483647); 
	// int len2 = printf("|%-30X||%-30X|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%-30X||%-30X|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%-30X||%-30X|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%-30X||%-30X|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%-30X||%-30X|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%-+#0  ###0  ++--30X||%-+#0  ###0  ++--30X|\n",0,0); 
	// int len2 = printf("|%-+#0  ###0  ++--30X||%-+#0  ###0  ++--30X|\n",0,0);

	// int len1 = ft_printf("|%-+#0  ###0  ++--30X||%-+#0  ###0  ++--30X|\n", 20,20);
	// int len2 = printf("|%-+#0  ###0  ++--30X||%-+#0  ###0  ++--30X|\n", 20,20);

	// int len1 = ft_printf("|%-+#0  ###0  ++--30X||%-+#0  ###0  ++--30X|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%-+#0  ###0  ++--30X||%-+#0  ###0  ++--30X|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%-+#0  ###0  ++--30X||%-+#0  ###0  ++--30X|\n", 2147483647,2147483647); 
	// int len2 = printf("|%-+#0  ###0  ++--30X||%-+#0  ###0  ++--30X|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%-+#0  ###0  ++--30X||%-+#0  ###0  ++--30X|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%-+#0  ###0  ++--30X||%-+#0  ###0  ++--30X|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%-+#0  ###0  ++--30X||%-+#0  ###0  ++--30X|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%-+#0  ###0  ++--30X||%-+#0  ###0  ++--30X|\n",-214748364756,-214748364756);
	
	// int len1 = ft_printf("|%.30X||%.30X|\n",0,0); 
	// int len2 = printf("|%.30X||%.30X|\n",0,0);

	// int len1 = ft_printf("|%.30X||%.30X|\n", 20,20);
	// int len2 = printf("|%.30X||%.30X|\n", 20,20);

	// int len1 = ft_printf("|%.30X||%.30X|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%.30X||%.30X|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%.30X||%.30X|\n", 2147483647,2147483647); 
	// int len2 = printf("|%.30X||%.30X|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%.30X||%.30X|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%.30X||%.30X|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%.30X||%.30X|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%.30X||%.30X|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%#.30X||%#.30X|\n",0,0); 
	// int len2 = printf("|%#.30X||%#.30X|\n",0,0);

	// int len1 = ft_printf("|%#.30X||%#.30X|\n", 20,20);
	// int len2 = printf("|%#.30X||%#.30X|\n", 20,20);

	// int len1 = ft_printf("|%#.30X||%#.30X|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%#.30X||%#.30X|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%#.30X||%#.30X|\n", 2147483647,2147483647); 
	// int len2 = printf("|%#.30X||%#.30X|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%#.30X||%#.30X|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%#.30X||%#.30X|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%#.30X||%#.30X|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%#.30X||%#.30X|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%+#-0   ###-  .30X||%+#-0   ###-  .30X|\n",0,0); 
	// int len2 = printf("|%+#-0   ###-  .30X||%+#-0   ###-  .30X|\n",0,0);

	// int len1 = ft_printf("|%+#-0   ###-  .30X||%+#-0   ###-  .30X|\n", 20,20);
	// int len2 = printf("|%+#-0   ###-  .30X||%+#-0   ###-  .30X|\n", 20,20);

	// int len1 = ft_printf("|%+#-0   ###-  .30X||%+#-0   ###-  .30X|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%+#-0   ###-  .30X||%+#-0   ###-  .30X|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%+#-0   ###-  .30X||%+#-0   ###-  .30X|\n", 2147483647,2147483647); 
	// int len2 = printf("|%+#-0   ###-  .30X||%+#-0   ###-  .30X|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%+#-0   ###-  .30X||%+#-0   ###-  .30X|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%+#-0   ###-  .30X||%+#-0   ###-  .30X|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%+#-0   ###-  .30X||%+#-0   ###-  .30X|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%+#-0   ###-  .30X||%+#-0   ###-  .30X|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%35.30X||%35.30X|\n",0,0); 
	// int len2 = printf("|%35.30X||%35.30X|\n",0,0);

	// int len1 = ft_printf("|%35.30X||%35.30X|\n", 20,20);
	// int len2 = printf("|%35.30X||%35.30X|\n", 20,20);

	// int len1 = ft_printf("|%35.30X||%35.30X|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%35.30X||%35.30X|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%35.30X||%35.30X|\n", 2147483647,2147483647); 
	// int len2 = printf("|%35.30X||%35.30X|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%35.30X||%35.30X|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%35.30X||%35.30X|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%35.30X||%35.30X|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%35.30X||%35.30X|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%-#35.30X||%-#35.30X|\n",0,0); 
	// int len2 = printf("|%-#35.30X||%-#35.30X|\n",0,0);

	// int len1 = ft_printf("|%-#35.30X||%-#35.30X|\n", 20,20);
	// int len2 = printf("|%-#35.30X||%-#35.30X|\n", 20,20);

	// int len1 = ft_printf("|%-#35.30X||%-#35.30X|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%-#35.30X||%-#35.30X|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%-#35.30X||%-#35.30X|\n", 2147483647,2147483647); 
	// int len2 = printf("|%-#35.30X||%-#35.30X|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%-#35.30X||%-#35.30X|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%-#35.30X||%-#35.30X|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%-#35.30X||%-#35.30X|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%-#35.30X||%-#35.30X|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%#35.30X||%#35.30X|\n",0,0); 
	// int len2 = printf("|%#35.30X||%#35.30X|\n",0,0);

	// int len1 = ft_printf("|%#35.30X||%#35.30X|\n", 20,20);
	// int len2 = printf("|%#35.30X||%#35.30X|\n", 20,20);

	// int len1 = ft_printf("|%#35.30X||%#35.30X|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%#35.30X||%#35.30X|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%#35.30X||%#35.30X|\n", 2147483647,2147483647); 
	// int len2 = printf("|%#35.30X||%#35.30X|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%#35.30X||%#35.30X|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%#35.30X||%#35.30X|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%#35.30X||%#35.30X|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%#35.30X||%#35.30X|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%-35.30X||%-35.30X|\n",0,0); 
	// int len2 = printf("|%-35.30X||%-35.30X|\n",0,0);

	// int len1 = ft_printf("|%-35.30X||%-35.30X|\n", 20,20);
	// int len2 = printf("|%-35.30X||%-35.30X|\n", 20,20);

	// int len1 = ft_printf("|%-35.30X||%-35.30X|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%-35.30X||%-35.30X|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%-35.30X||%-35.30X|\n", 2147483647,2147483647); 
	// int len2 = printf("|%-35.30X||%-35.30X|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%-35.30X||%-35.30X|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%-35.30X||%-35.30X|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%-35.30X||%-35.30X|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%-35.30X||%-35.30X|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%35.30X||%35.30X|\n",0,0); 
	// int len2 = printf("|%35.30X||%35.30X|\n",0,0);

	// int len1 = ft_printf("|%35.30X||%35.30X|\n", 20,20);
	// int len2 = printf("|%35.30X||%35.30X|\n", 20,20);

	// int len1 = ft_printf("|%35.30X||%35.30X|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%35.30X||%35.30X|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%35.30X||%35.30X|\n", 2147483647,2147483647); 
	// int len2 = printf("|%35.30X||%35.30X|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%35.30X||%35.30X|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%35.30X||%35.30X|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%35.30X||%35.30X|\n",-214748364756,-214748364756); 
	// int len2 = printf("|%35.30X||%35.30X|\n",-214748364756,-214748364756);

	// int len1 = ft_printf("|%-+ # 00000035.30X||%-+ # 00000035.30X|\n",0,0); 
	// int len2 = printf("|%-+ # 00000035.30X||%-+ # 00000035.30X|\n",0,0);

	// int len1 = ft_printf("|%-+ # 00000035.30X||%-+ # 00000035.30X|\n", 20,20);
	// int len2 = printf("|%-+ # 00000035.30X||%-+ # 00000035.30X|\n", 20,20);

	// int len1 = ft_printf("|%-+ # 00000035.30X||%-+ # 00000035.30X|\n",-2147483648, -2147483648); 
	// int len2 = printf("|%-+ # 00000035.30X||%-+ # 00000035.30X|\n",-2147483648, -2147483648);

	// int len1 = ft_printf("|%-+ # 00000035.30X||%-+ # 00000035.30X|\n", 2147483647,2147483647); 
	// int len2 = printf("|%-+ # 00000035.30X||%-+ # 00000035.30X|\n", 2147483647,2147483647);

	// int len1 = ft_printf("|%-+ # 00000035.30X||%-+ # 00000035.30X|\n", 214748364756, 214748364756); 
	// int len2 = printf("|%-+ # 00000035.30X||%-+ # 00000035.30X|\n", 214748364756, 214748364756);

	// int len1 = ft_printf("|%-+ # 00000035.30X||%-+ # 00000035.30X||%-+ # 00000035.30x||%-+ # 00000035.30x||%-+ # 00000035.30d||%-+ # 00000035.30i||%-+ # 00000035.30u|\n",-214748364756,-214748364756,-214748364756,-214748364756,-214748364756,-214748364756,-214748364756); 
	// int len2 = printf("|%-+ # 00000035.30X||%-+ # 00000035.30X||%-+ # 00000035.30x||%-+ # 00000035.30x||%-+ # 00000035.30d||%-+ # 00000035.30i||%-+ # 00000035.30u|\n",-214748364756,-214748364756,-214748364756,-214748364756,-214748364756,-214748364756,-214748364756);

	//percent cases '%':
	
	//  int len1 = ft_printf("helloooo%5%%5%%%\n"); 
	//  int len2 = printf("helloooo%5%%5%%%\n");
	

	// printf("len1: %d\n", len1);
	// printf("len2: %d\n", len2);
}