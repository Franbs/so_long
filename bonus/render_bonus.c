/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:25:51 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/05/08 19:00:01 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_move(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		moved;

	game = param;
	moved = 0;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_S)
			moved = ft_movedown(game);
		if (keydata.key == MLX_KEY_W)
			moved = ft_moveup(game);
		if (keydata.key == MLX_KEY_A)
			moved = ft_moveleft(game);
		if (keydata.key == MLX_KEY_D)
			moved = ft_moveright(game);
		if (moved)
		{
			game->moves += moved;
			ft_printf("moves: %d\n", game->moves);
		}
	}
	ft_close(keydata, game->mlx);
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
		mlx_image_to_window(game->mlx, game->player->imgdown,
			j * IMG_W, i * IMG_H);
	if (tile == 'T')
		mlx_image_to_window(game->mlx, game->enemyimg,
			j * IMG_W, i * IMG_H);
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

int	ft_findchar(t_game *game, char tofind, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->content->rows)
	{
		j = 0;
		while (j < game->content->cols)
		{
			if (game->content->map[i][j] == tofind)
			{
				*x = j;
				*y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
