#include "ft_printf_bonus.h"

int	b_ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int 	b_ft_putstr(char *s)
{
	int	count, res;
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