/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_rest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:01:15 by chenlee           #+#    #+#             */
/*   Updated: 2023/03/03 18:47:48 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puzzle.h"

void	find_min_candidate(t_puzzle *puzl, int *min_i, int *min_j)
{
	int	i;
	int	j;
	int	min;

	i = -1;
	min = puzl->size;
	while (++i < puzl->size)
	{
		j = -1;
		while (++j < puzl->size)
		{
			if (puzl->cell[i][j].fixed != 1 && puzl->cell[i][j].count < min)
			{
				*(min_i) = i;
				*(min_j) = j;
				min = puzl->cell[i][j].count;
			}
		}
	}
}

t_node	*node_init(t_puzzle *puzl, int row, int col)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->puzl = *puzl;
	node->parent = NULL;
	node->child = NULL;
	return (node);
}

int	solve_rest(t_puzzle *puzl)
{
	t_node	*main_node;
	int		min_i;
	int		min_j;

	find_min_candidate(puzl, &min_i, &min_j);
	main_node = node_init(puzl);
	main_node->child = create_child_nodes(puzl, min_i, min_j, main_node);
	return (0);
}
