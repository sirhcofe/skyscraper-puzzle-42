#ifndef PUZZLE_H
#define PUZZLE_H

#include <stdlib.h>
#include <unistd.h>

#define TOP 0
#define BOT 1
#define LFT 2
#define RHT 3

typedef struct s_map
{
	int		count;
	int		*posbl;
	int		val;
	int		fixed;
}			t_map;

typedef struct s_puzzle
{
	int			**vsby;
	t_map		**cell;
}				t_puzzle;

int			check_args(int argc, char **argv);
t_puzzle	*init(root, argv);

#endif
