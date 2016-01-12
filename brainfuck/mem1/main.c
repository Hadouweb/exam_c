#include <unistd.h>

void	ft_interpret(char *str, char *buff, int loop)
{
	while (*str)
	{
		if (*str == '>')
			buff++;
		if (*str == '<')
			buff--;
		if (*str == '+')
			(*buff)++;
		if (*str == '-')
			(*buff)--;
		if (*str == '.')
			write (1, buff, 1);
		if (*str == '[' && *buff == 0)
		{
			loop = 1;
			while (loop && str++)
			{
				if (*str == ']')
					loop--;
				if (*str == '[')
					loop++;
			}
		}
		if (*str == ']' && *buff != 0)
		{
			loop = 1;
			while (loop && str--)
			{
				if (*str == ']')
					loop++;
				if (*str == '[')
					loop--;
			}
		}
		str++;
	}

}

int		main(int ac, char **av)
{
	int		i;
	int		loop;
	char	buff[2048];

	if (ac != 2)
		write (1, "\n", 1);
	else
	{
		i = 0;
		loop = 0;
		while (buff[i])
		{
			buff[i] = 0;
			i++;
		}
		ft_interpret(av[1], buff, loop);
	}
	return (0);
}