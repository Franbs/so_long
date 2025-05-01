/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:25:51 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/05/01 19:04:02 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_renderplayer(t_game *game, int i, int j)
{
	mlx_image_to_window(game->mlx, game->player->imgdown, j * IMG_W, i * IMG_H);
}

void	ft_setimgstowindow(t_game *game, char tile, int i, int j)
{
	mlx_image_to_window(game->mlx, game->floorimg, j * IMG_W, i * IMG_H);
	if (tile == '1')
		mlx_image_to_window(game->mlx, game->wallimg, j * IMG_W, i * IMG_H);
	if (tile == 'E')
		mlx_image_to_window(game->mlx, game->eimg, j * IMG_W, i * IMG_H);
	if (tile == 'C')
		mlx_image_to_window(game->mlx, game->cimg, j * IMG_W, i * IMG_H);
	if (tile == 'P')
		ft_renderplayer(game, i, j);
}

void	ft_render(t_game *game)
{
	int		i;
	int		j;
	char	tile;

	i = 0;
	while (i < game->content->rows)
	{
		j = 0;
		while (j < game->content->cols)
		{
			tile = game->content->map[i][j];
			ft_setimgstowindow(game, tile, i, j);
			j++;
		}
		i++;
	}
}
