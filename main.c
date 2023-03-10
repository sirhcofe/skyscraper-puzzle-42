#include "puzzle.h"

void	ft_free(t_puzzle *puzl)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
		free(puzl->vsby[i]);
	i = -1;
	while (++i < puzl->size)
	{
		j = -1;
		while (++j < puzl->size)
			free(puzl->cell[i][j].posbl);
		free(puzl->cell[i]);
	}
	free(puzl->vsby);
	free(puzl->cell);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		write(1, &str[i], 1);
}

int	error(int condition)
{
	if (condition == 1)
		ft_putstr("Invalid arguments!\n");
	else if (condition == 2)
		ft_putstr("Invalid visibility constraint!\n");
	else if (condition == 3)
		ft_putstr("Unsolvable!\n");
	return (1);
}

int	main(int argc, char **argv)
{
	t_puzzle	*puzl;
	int			size;
	int			ret;

	ret = 0;
	size = check_args(argc, argv);
	if (size == -1)
		return (error(1));
	puzl = init(size, argv);
	if (puzl == NULL)
		return (error(2));
	if (solve_edge_clues(puzl) || solve_rest(puzl))
		ret = error(3);
	ft_free(puzl);
	free(puzl);
	return (ret);
}
