/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:25:51 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/05/03 20:19:32 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		game->moves += ft_movedown(game);
		ft_printf("moves: %d\n", game->moves);
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		game->moves += ft_moveup(game);
		ft_printf("moves: %d\n", game->moves);
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		game->moves += ft_moveleft(game);
		ft_printf("moves: %d\n", game->moves);
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		game->moves += ft_moveright(game);
		ft_printf("moves: %d\n", game->moves);
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

void	ft_swaptile(t_game *game, int x, int y, char newchar)
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
			if (i == y && j == x)
				game->content->map[i][j] = newchar;
			j++;
		}
		i++;
	}
}
