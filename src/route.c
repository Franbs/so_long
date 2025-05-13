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

void	ft_recursivesearch(t_mapdup *mapdup, int x, int y)
{
	if (x < 0 || y < 0 || x >= mapdup->rows || y >= mapdup->cols)
		return ;
	if (mapdup->map[x][y] == '1' || mapdup->map[x][y] == 'X')
		return ;
	else if (mapdup->map[x][y] == 'C')
		mapdup->c++;
	else if (mapdup->map[x][y] == 'E')
		mapdup->e++;
	mapdup->map[x][y] = 'X';
	ft_recursivesearch(mapdup, (x + 1), y);
	ft_recursivesearch(mapdup, (x - 1), y);
	ft_recursivesearch(mapdup, x, (y + 1));
	ft_recursivesearch(mapdup, x, (y - 1));
}

void	ft_checkroutes(t_game *game, char *file)
{
	int			x;
	int			y;
	int			route;
	t_mapdup	*mapdup;	

	route = 0;
	x = game->player->posx;
	y = game->player->posy;
	mapdup = ft_initmapdup(game);
	ft_savemapdup(game, mapdup, file);
	ft_recursivesearch(mapdup, x, y);
	if (mapdup->c != game->content->c || mapdup->e != 1)
	{
		ft_freemapdup(mapdup);
		ft_errorgame("Error. You can't get everything", game, -1);
	}
	ft_freemapdup(mapdup);
}
