#include "puzzle.h"

/**
 * This function checks if the number parsed is a divisible by 4. Returns
 * its root if true, otherwise return -1
 * 
 * @param num the number parsed for checking
*/
int	four_divisible(int num)
{
	int	i;

	i = 1;
	while (1)
	{
		if (i * 4 == num)
			return (i);
		else if (i * 4 > num)
			return (-1);
		i++;
	}
}

/**
 * This function ensures that the input parsed from the command line argument
 * is sufficient to make a valid puzzle map, where (4*N + 1) numbers of
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

	printf("argc = %d\n", argc);
	root = four_divisible(argc - 1);
	printf("root = %d\n", root);
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
