#include <stdlib.h>

int 	ft_intlen(int value, int base)
{
	int 	i;

	i = 0;
	if (value < 0 && base == 10)
		i++;
	if (value == 0)
		i++;
	while (value)
	{
		value /= base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	int		size;
	int		sign;

	size = ft_intlen(value, base);
	str = (char *)malloc(size * sizeof(char) + 1);
	sign = (value < 0) ? -1 : 1;
	str[size--] = '\0';
	if (value < 0 && base == 10)
		str[0] = '-';
	if (value == 0)
		str[0] = '0';
	while (value)
	{
		str[size] = value % base * sign;
		if (str[size] >= 10)
			str[size] += 7;
		str[size] += '0';
		value /= base;
		size--;
	}
	return (str);
}
