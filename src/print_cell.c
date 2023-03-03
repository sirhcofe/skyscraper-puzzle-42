#include "puzzle.h"
#include <stdio.h>

#define C_BLU	"\x1B[34m"
#define C_WHT	"\x1B[37m"
#define C_RST	"\x1B[0m"

void	print_cell(t_puzzle *puzl, int index)
{
	int	i;

	i = -1;
	while (++i < puzl->size)
		printf(C_WHT "%d ", puzl->cell[index][i].val);
}

void	print_vsby(t_puzzle *puzl, int direction, int index)
{
	int	i;

	if (direction == TOP || direction == BOT)
	{
		printf("  ");
		i = -1;
		while (++i < puzl->size)
			printf(C_BLU "%d ", puzl->vsby[direction][i]);
		printf(C_RST "\n");
	}
	else if (direction == LFT || direction == RHT)
	{
		printf(C_BLU "%d ", puzl->vsby[direction][index]);
		if (direction == RHT)
			printf("\n");
	}
}

void	print_cells(t_puzzle *puzl)
{
	int	i;

	i = 0;
	while (i < puzl->size + 2)
	{
		if (i == 0)
			print_vsby(puzl, TOP, 0);
		else if (i == puzl->size + 1)
			print_vsby(puzl, BOT, 0);
		else
		{
			print_vsby(puzl, LFT, i - 1);
			print_cell(puzl, i - 1);
			print_vsby(puzl, RHT, i - 1);
		}
		i++;
	}
}

void	print_posbl_candidate(t_puzzle *puzl)
{
	int	i;
	int	j;

	printf("\n");
	i = -1;
	while (++i < puzl->size)
	{
		j = -1;
		while (++j < puzl->size)
			printf("%d ", puzl->cell[i][j].count);
		printf("\n");
	}
}
