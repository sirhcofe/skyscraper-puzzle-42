#include "puzzle.h"

/**
 * This function checks if the number parsed is a perfect square. Returns
 * its root if true, otherwise return -1
 * 
 * @param num the number parsed for checking
*/
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

/**
 * This function ensures that the input parsed from the command line argument
 * is sufficient to make a valid puzzle map, where (N^2 + 1) numbers of
 * arguments is required to make a puzzle map of N size.
 * 
 * @param argc the number of arguments parsed from command line
 * @param argv the arguments parsed
*/
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
