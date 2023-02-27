#include "puzzle.h"

void	mark_used(t_map cell, int ignore)
{
	cell.posbl[ignore] = 1;
}

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
