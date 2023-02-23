#include "puzzle.h"

int	**visibility_init(int root, char **argv)
{
	int	**ret;
	int	i;
	int	j;
	int	count;

	ret = malloc(sizeof(int *) * root);
	i = -1;
	while (++i < root)
		ret[i] = malloc(sizeof(int) * root);
	count = 1;
	i = -1;
	while (++i < root)
	{
		j = -1;
		while (++j < root)
			ret[i][j] = ft_atoi(argv[count++]);
	}
	return (ret);
}

t_puzzle	*init(int root, char **argv)
{
	t_puzzle	*puzl;
	int			i;

	puzl = malloc(sizeof(t_puzzle));
	puzl->vsby = visibility_init(root, argv);
	puzl->cell = malloc(sizeof(t_map *) * root);
	i = -1;
	while (++i < root)
		puzl->cell[i] = malloc(sizeof(t_map) * root);
	
}
