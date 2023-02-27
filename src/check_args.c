#include "puzzle.h"

int	is_perfect_square(int num)
{
	int	i;

	i = 1;
	while (1)
	{
		if (i * i == num)
			return (i);
		else if (i * i > num)
			return (-1);
		i++;
	}
}

int	check_args(int argc, char **argv)
{
	int	root;
	int	i;
	int	j;

	root = is_perfect_square(argc - 1);
	if (root == -1)
		return (-1);
	i = 0;
	while (argv[++i] != NULL)
	{
		j = -1;
		while (argv[i][++j] != '\0')
		{
			if (!(ft_isdigit(argv[i][j])))
				return (-1);
		}
	}
	return (root);
}
