#include "puzzle.h"
#include <stdio.h>

int	fill_mid(t_puzzle *puzl, int index, int dir)
{
	if (dir == 0
		&& assign_candidate(puzl, puzl->vsby[dir][index], index, puzl->size))
			return (1);
	else if (dir == 2
		&& assign_candidate(puzl, index, puzl->vsby[dir][index], puzl->size))
			return (1);
	return (0);
}

int	fill_one(t_puzzle *puzl, int index, int dir)
{
	int	x;

	printf("fill_one called\n");
	if (dir == TOP || dir == BOT)
	{
		x = ((dir == TOP) * 0) + ((dir == BOT) * (puzl->size - 1));
		puzl->cell[x][index].val = puzl->size;
		if (assign_candidate(puzl, x, index, puzl->size))
			return (1);
	}
	else if (dir == LFT || dir == RHT)
	{
		x = ((dir == LFT) * 0) + ((dir == RHT) * (puzl->size - 1));
		puzl->cell[index][x].val = puzl->size;
		if (assign_candidate(puzl, x, index, puzl->size))
			return (1);
	}
	print_cells(puzl);
	return (0);
}

/**
 * This function will be called when a visibility constraint of value MAX 
 * is found on opposing sides of the same row/column, this will generate a 
 * group of ascending numbers along the row/column ranging from 1 to MAX
 * 
 * @param puzl struct containing cell array with its size, and visibility array
 * @param index the index from a particular direction
 * @param dir direction indicated either TOP, BOT, LFT, or RHT
*/
int	fill_maxval(t_puzzle *puzl, int index, int dir)
{
	int	i;
	int	value;

	printf("maxval called\n");
	i = -1;
	while (++i < puzl->size)
	{
		if (dir == TOP || dir == BOT)
		{
			value = ((dir == TOP) * (i + 1))
						+ ((dir == BOT) * (puzl->size - i));
			if (assign_candidate(puzl, i, index, value))
				return (1);
			puzl->cell[i][index].fixed = 1;
		}
		else if (dir == LFT || dir == RHT)
		{
			value = ((dir == LFT) * (i + 1))
						+ ((dir == RHT) * (puzl->size - i));
			if (assign_candidate(puzl, index, i, value))
				return (1);
			puzl->cell[i][index].fixed = 1;
		}
	}
	return (0);
}

/**
 * Goes through the visbility constraint clues to find obvious combinations 
 * to assign the resulting candidate(s) into each cells
 * 
 * @param puzl struct containing cell array with its size, and visibility array
*/
int	find_clues(t_puzzle *puzl)
{
	int	i;
	int	j;

	i = -1;
	while (++i < puzl->size)
	{
		j = -1;
		while (++j < puzl->size)
		{
			if (puzl->vsby[i][j] == puzl->size && fill_maxval(puzl, j, i))
				return (1);
			else if (puzl->vsby[i][j] == 1 && fill_one(puzl, j, i))
				return (1);
			// else if ((i == 0 || i == 2)
			// 			&& puzl->vsby[i][j] + puzl->vsby[i + 1][j] == puzl->size + 1
			// 			&& fill_mid(puzl, j, i))
				// return (1);
		}
	}
	return (0);
}

int	solve_edge_clues(t_puzzle *puzl)
{
	if (find_clues(puzl))
		return (1);
	else
	{
		print_cells(puzl);
		return (0);
	}
}
