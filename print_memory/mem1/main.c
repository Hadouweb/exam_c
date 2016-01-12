#include <unistd.h>

void	print_str(unsigned char *ptr, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (ptr[i] >= 32 && ptr[i] < 127)
			write(1, &ptr[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	print_byte(unsigned char byte)
{
	char	hexa[16] = "0123456789abcdef";

	write(1, &hexa[byte >> 4], 1);
	write(1, &hexa[byte & 15], 1);
}

void	print_line(unsigned char *ptr, int len)
{
	int		i;
	int		col;

	i = 0;
	col = 40;
	while (i < len)
	{
		print_byte(ptr[i]);
		col -= 2;
		if (i + 1 < len)
		{
			print_byte(ptr[i + 1]);
			write(1, " ", 1);
			col -= 3;
		}
		i += 2;
	}
	while (col--)
		write(1, " ", 1);
	print_str(ptr, len);
}

void	print_memory(const void *addr, size_t size)
{
	unsigned char	*ptr;
	int				nb_line;
	int				nb_byte;
	int				i;

	ptr = (unsigned char*)addr;
	nb_line = size / 16;
	nb_byte = size % 16;
	i = 0;
	while (i < nb_line)
	{
		print_line(ptr, 16);
		ptr += 16;
		i++;
	}
	if (nb_byte)
		print_line(ptr, nb_byte);
}

int		main(void)
{
	int	tab[10] = {0, 23, 150, 255,
	              12, 16,  21, 42};
 
	print_memory(tab, sizeof(tab));
	return (0);
}