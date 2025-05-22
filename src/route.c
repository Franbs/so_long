/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:27:49 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/05/13 19:17:31 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_recursivesearch(t_mapdup *mapdup, int row, int col)
{
	if (row < 0 || col < 0 || row >= mapdup->rows || col >= mapdup->cols)
		return ;
	if (mapdup->map[row][col] == '1' || mapdup->map[row][col] == 'X')
		return ;
	else if (mapdup->map[row][col] == 'C')
		mapdup->c++;
	else if (mapdup->map[row][col] == 'E')
		mapdup->e++;
	mapdup->map[row][col] = 'X';
	ft_recursivesearch(mapdup, (row + 1), col);
	ft_recursivesearch(mapdup, (row - 1), col);
	ft_recursivesearch(mapdup, row, (col + 1));
	ft_recursivesearch(mapdup, row, (col - 1));
}

void	ft_checkroutes(t_game *game, char *file)
{
	int			col;
	int			row;
	int			route;
	t_mapdup	*mapdup;	

	route = 0;
	col = game->player->posx;
	row = game->player->posy;
	mapdup = ft_initmapdup(game);
	ft_savemapdup(game, mapdup, file);
	ft_recursivesearch(mapdup, row, col);
	if (mapdup->c != game->content->c || mapdup->e != 1)
	{
		ft_freemapdup(mapdup);
		ft_errorgame("Error. You can't get everything", game, -1);
	}
	ft_freemapdup(mapdup);
}
