#include "ft_printf_bonus.h"

char	b_upper_or_lower_case_check(int rem, char c)
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

char	*b_return_hexvalue_lower(unsigned int n)
{
	int		rem;
	char	*str;
	int		i;

	str = malloc(100);
	if(!str)
		return NULL;
	i = 0;
	while (n != 0)
	{
		rem = n % 16;
		n /= 16;
		str[i] = b_upper_or_lower_case_check(rem, 'a');
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*b_return_hexvalue_upper(unsigned int n)
{
	int		rem;
	char	*str;
	int		i;

	str = malloc(100);
	i = 0;
	while (n != 0)
	{
		rem = n % 16;
		n /= 16;
		str[i] = b_upper_or_lower_case_check(rem, 'A');
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*b_return_address_and_convert_to_hex(void *address)
{
	int rem;
	int i;
	char *str;
	uintptr_t n_address;
	str = malloc(100);
	n_address = (uintptr_t)address;
	i = 0;
	while (n_address != 0)
	{
		rem = n_address % 16;
		n_address /= 16;
		str[i] = b_upper_or_lower_case_check(rem, 'a');
		i++;
	}
	str[i] = '\0';
	return (str);
}