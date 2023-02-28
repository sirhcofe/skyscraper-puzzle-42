#include "puzzle.h"

/**
 * This function updates the list of possible candidates of the adjacent 
 * cells along the row/column
 * 
 * @param puzl struct containing cell array with its size, and visibility array
 * @param i the row index of the cell array
 * @param j the col index of the cell array
 * @param value the candidate which will be assigned into the cell
*/
void	update_possbl(t_puzzle *puzl, int i, int j, int value)
{
	int	a;
	int	b;

	a = -1;
	while (++a < puzl->size)
	{
		if (a == i)
		{
			b = -1;
			while (++b < puzl->size)
				puzl->cell[a][b].posbl[value] = 1;
		}
		else
			puzl->cell[a][j].posbl[value] = 1;
	}
}

/**
 * This function checks if the assignment of the candidate does not conflict 
 * with any rules, like duplicate numbers on the same row/column, etc
 * 
 * @param puzl struct containing cell array with its size, and visibility array
 * @param i the row index of the cell array
 * @param j the col index of the cell array
 * @param value the candidate which will be assigned into the cell
*/
int	assign_ok(t_puzzle *puzl, int i, int j, int value)
{
	if (puzl->cell[i][j].posbl[value] == 1 && puzl->cell[i][j].val != value)
		return (1);
	else
		return (0);
}

/**
 * This function will assign the candidate into a particular cell, which will 
 * then confirm the assignment does not conflict any rules, like duplicate 
 * numbers on the same row/column, etc
 * 
 * @param puzl struct containing cell array with its size, and visibility array
 * @param row the row index of the cell array
 * @param col the col index of the cell array
 * @param value the candidate which will be assigned into the cell
*/
int assign_candidate(t_puzzle *puzl, int row, int col, int value)
{
	puzl->cell[row][col].val = value;
	if (assign_ok(puzl, row, col, value))
		return (1);
	update_possbl(puzl, row, col, value);
	return (0);
}
