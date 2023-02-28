#include "puzzle.h"

int	**visibility_init(int size, char **argv)
{
	int	**ret;
	int	i;
	int	j;
	int	count;

	ret = malloc(sizeof(int *) * size);
	i = -1;
	while (++i < size)
		ret[i] = malloc(sizeof(int) * size);
	count = 1;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			ret[i][j] = ft_atoi(argv[count++]);
	}
	return (ret);
}

/**
 * The initialization of the sturct, whereby the stuct holds 3 information:
 * 1. The size of the puzzle
 * 2. A double int array containing the visibility constraint clues
 * 3. A double array of struct, where each struct denotes a cell in which holds:
 *    3.1 The value assigned to the cell,
 *    3.2 The list of possible candidates of a cell, which is defined by a array
 *        of integers and the index (except 0) denotes the candidate values. A
 *        number of 0 or 1 will be assigned to each index, which can be useful
 *        to determine if the number has been used along the same row/column
 * 
 * @param size The size of the puzzle
 * @param argv Arguments parsed from the command line
*/
t_puzzle	*init(int size, char **argv)
{
	t_puzzle	*puzl;
	int			i;
	int			j;
	int			k;

	puzl = malloc(sizeof(t_puzzle));
	puzl->size = size;
	puzl->vsby = visibility_init(size, argv);
	puzl->cell = malloc(sizeof(t_map *) * size);
	i = -1;
	while (++i < size)
	{
		puzl->cell[i] = malloc(sizeof(t_map) * size);
		j = -1;
		while (++j < size)
		{
			puzl->cell[i][j].count = size;
			puzl->cell[i][j].val = 0;
			puzl->cell[i][j].fixed = 0;
			puzl->cell[i][j].posbl = malloc(sizeof(int) * size + 1);
			k = -1;
			while (++k < size + 1)
				puzl->cell[i][j].posbl[k] = 0;
		}
	}
	return (puzl);
}
