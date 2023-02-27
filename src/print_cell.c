#include "puzzle.h"
#include <stdio.h>

void	print_cells(t_puzzle *puzl)
{
	int	i;
	int	j;

	i = -1;
	while (++i < puzl->size)
	{
		j = -1;
		while (++j < puzl->size)
			printf("%d ", puzl->cell[i][j].val);
		printf("\n");
	}
}
