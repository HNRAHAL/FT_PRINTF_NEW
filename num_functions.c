#include "ft_printf_bonus.h"

int	b_ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == INT_MIN)
		return (b_ft_putstr("2147483648"));
	if (n < 0)
		n = -n;
	
	if (n >= 10)
	{
		count += b_ft_putnbr(n / 10);
		if (count == -1)
			return (-1);
	}
	count += b_ft_putchar((n % 10) + '0');
	if (count == -1)
		return (-1);
	return (count);
}

int	b_ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += b_ft_putnbr_unsigned(n / 10);
		if (count == -1)
			return (-1);
	}
	count += b_ft_putchar((n % 10) + '0');
	if (count == -1)
		return (-1);
	return (count);
}

int	b_num_len(int n)
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

int	b_unsigned_num_len(unsigned int n)
{
	int count;

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