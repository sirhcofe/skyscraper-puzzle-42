/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:22:12 by chenlee           #+#    #+#             */
/*   Updated: 2023/03/03 18:47:55 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puzzle.h"

t_node	**create_child_nodes(t_puzzle *puzl, int row, int col, t_node *parent)
{
	int		i;
	t_node	**child_list;

	i = -1;
	child_list = malloc(sizeof(t_node *) * puzl->cell[row][col].count);
	while (++i < puzl->cell[row][col].count)
	{
		child_list[i] = malloc(sizeof(t_node));
		child_list[i]->puzl = *puzl;
		child_list[i]->parent = parent;
		child_list[i]->child = NULL;
	}
	return (child_list);
}
