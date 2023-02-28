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
	int			size;
	int			**vsby;
	t_map		**cell;
}				t_puzzle;

// initial checking and parsing
int			check_args(int argc, char **argv);
t_puzzle	*init(int size, char **argv);

// initial candidate assignment based on edge clues
int			solve_edge_clues(t_puzzle *puzl);

// checking if value assigning in cell doesn't have any conflicts
int 		assign_candidate(t_puzzle *puzl, int row, int col, int value);

// update clues row/column-wise after assigning values in cell of the same row/column
void		update_possbl(t_puzzle *puzl, int i, int j, int value);

// utils
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
void		print_cells(t_puzzle *puzl);

#endif
