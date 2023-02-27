#include "puzzle.h"
#include <stdio.h>

int assign(t_puzzle *puzl, int row, int col, int value)
{
	puzl->cell[row][col].val = value;
	if (assign_ok(puzl, row, col, value))
		return (1);
	update_possbl(puzl, row, col, value);
	return (0);
}

int	fill_one(t_puzzle *puzl, int index, int dir)
{
	int	x;

	if (dir == TOP || dir == BOT)
	{
		x = ((dir == TOP) * 0) + ((dir == BOT) * (puzl->size - 1));
		puzl->cell[x][index].val = puzl->size;
		if (assign(puzl, x, index, puzl->size))
			return (1);
	}
	else if (dir == LFT || dir == RHT)
	{
		x = ((dir == LFT) * 0) + ((dir == RHT) * (puzl->size - 1));
		puzl->cell[index][x].val = puzl->size;
		if (assign(puzl, x, index, puzl->size))
			return (1);
	}
}

int	fill_maxval(t_puzzle *puzl, int index, int dir)
{
	int	i;
	int	value;

	i = -1;
	while (++i < puzl->size)
	{
		if (dir == TOP || dir == BOT)
		{
			// puzl->cell[i][index].val = ((dir == TOP) * (i + 1))
			// 							+ ((dir == BOT) * (puzl->size - i));
			// if (assign_ok(puzl, i, index, puzl->cell[i][index].val))
			// 	return (1);
			// update_possbl(puzl, i, index, puzl->cell[i][index].val);
			value = ((dir == TOP) * (i + 1))
						+ ((dir == BOT) * (puzl->size - i));
			if (assign(puzl, i, index, value))
				return (1);
			puzl->cell[i][index].fixed = 1;
		}
		else if (dir == LFT || dir == RHT)
		{
			// puzl->cell[index][i].val = ((dir == LFT) * (i + 1))
			// 							+ ((dir == RHT) * (puzl->size - i));
			// if (assign_ok(puzl, i, index, puzl->cell[index][i].val))
			// 	return (1);
			// update_possbl(puzl, i, index, puzl->cell[index][i].val);
			value = ((dir == LFT) * (i + 1))
						+ ((dir == RHT) * (puzl->size - i));
			if (assign(puzl, index, i, value))
				return (1);
			puzl->cell[i][index].fixed = 1;
		}
	}
	return (0);
}

int	find_maxval_clue(t_puzzle *puzl)
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
			// else if (puzl->vsby[i][j] == 1 && fill_one(puzl, j, i))
			// 	return (1);
			print_cells(puzl);
		}
	}
	return (0);
}

int	constraint_propag(t_puzzle *puzl)
{
	if (find_maxval_clue(puzl))
		return (1);
	else
	{
		print_cells(puzl);
		return (0);
	}
}
