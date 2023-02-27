#include "puzzle.h"

int	assign_ok(t_puzzle *puzl, int i, int j, int value)
{
	if (puzl->cell[i][j].posbl[value] == 1 && puzl->cell[i][j].val != value)
		return (1);
	else
		return (0);
}
