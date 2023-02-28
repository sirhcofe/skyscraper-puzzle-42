#include "puzzle.h"

/**
 * Function checks for the legibility of the visibility constraints, ensuring
 * the clues will not have obvious errors, like impossible constaint of values
 * more than the size of the puzzle, or combination of clues of the opposing
 * sides along the row/column that is invalid (for example a combination of 3-3
 * in a puzzle of size 4 will be unsolvable)
 * Note: this function does not check for all visibility constraints error,
 * especially unsolvable puzzle as a whole
 * 
 * @param vsby the array storing the visibility constraint clues
 * @param size the size of the puzzle
*/
int	check_visibility(int **vsby, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		if (vsby[TOP][i] + vsby[BOT][i] > size + 1
				|| vsby[LFT][i] + vsby[RHT][i] > size + 1)
		{
			j = -1;
			while (++j < size)
				free(vsby[j]);
			free(vsby);
			return (1);
		}
	}
	return (0);
}

/**
 * The initialization of visibility constraint clues
 * 
 * @param puzl struct
 * @param size size of the puzzle
 * @param argv arguments from the command line
*/
int	visibility_init(t_puzzle *puzl, int size, char **argv)
{
	int	i;
	int	j;
	int	count;

	puzl->vsby = malloc(sizeof(int *) * size);
	i = -1;
	while (++i < size)
		puzl->vsby[i] = malloc(sizeof(int) * size);
	count = 1;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			puzl->vsby[i][j] = ft_atoi(argv[count++]);
	}
	if (check_visibility(puzl->vsby, size))
		return (1);
	return (0);
}

/**
 * The initialization of the cell struct
 * 
 * @param puzl struct
*/
void	cell_init(t_puzzle *puzl)
{
	int	i;
	int	j;
	int	k;

	puzl->cell = malloc(sizeof(t_map *) * puzl->size);
	i = -1;
	while (++i < puzl->size)
	{
		puzl->cell[i] = malloc(sizeof(t_map) * puzl->size);
		j = -1;
		while (++j < puzl->size)
		{
			puzl->cell[i][j].count = puzl->size;
			puzl->cell[i][j].val = 0;
			puzl->cell[i][j].fixed = 0;
			puzl->cell[i][j].posbl = malloc(sizeof(int) * puzl->size + 1);
			k = -1;
			while (++k < puzl->size + 1)
				puzl->cell[i][j].posbl[k] = 0;
		}
	}
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

	puzl = malloc(sizeof(t_puzzle));
	puzl->size = size;
	puzl->vsby = NULL;
	if (visibility_init(puzl, size, argv))
	{
		free(puzl);
		return (NULL);
	}
	cell_init(puzl);
	return (puzl);
}
