#include "puzzle.h"

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		write(1, &str[i], 1);
}

int	error(int condition)
{
	if (condition == 1)
	{
		ft_putstr("Invalid arguments\n");
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_puzzle	*puzl;
	int			size;

	size = check_args(argc, argv);
	if (size == -1)
		return (error(1));
	puzl = init(size, argv);
}
