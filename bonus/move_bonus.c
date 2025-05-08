/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:25:53 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/05/08 17:50:14 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_updateplayerpos(t_game *game, int newx, int newy, mlx_image_t *img)
{
	char		oldtile;
	char		newtile;

	newtile = game->content->map[newy][newx];
	oldtile = game->content->map[game->player->posy][game->player->posx];
	ft_checkexit(game, oldtile, newtile);
	if (newtile != 'E')
	{
		game->content->map[newy][newx] = 'P';
		if (oldtile != 'E')
			game->content->map[game->player->posy][game->player->posx] = '0';
	}
	else if (newtile == 'E')
		game->content->map[game->player->posy][game->player->posx] = '0';
	mlx_image_to_window(game->mlx, img, newx * IMG_W, newy * IMG_H);
	game->player->posy = newy;
	game->player->posx = newx;
}

int	ft_moveup(t_game *game)
{
	int			newx;
	int			newy;

	newx = game->player->posx;
	newy = game->player->posy - 1;
	if (newy > 0 && newy < game->content->rows
		&& game->content->map[newy][newx] != '1')
	{
		ft_updateplayerpos(game, newx, newy, game->player->imgup);
		return (1);
	}
	return (0);
}

int	ft_movedown(t_game *game)
{
	int			newy;
	int			newx;

	newx = game->player->posx;
	newy = game->player->posy + 1;
	if (newy > 0 && newy < game->content->rows
		&& game->content->map[newy][newx] != '1')
	{
		ft_updateplayerpos(game, newx, newy, game->player->imgdown);
		return (1);
	}
	return (0);
}

int	ft_moveleft(t_game *game)
{
	int			newx;
	int			newy;

	newx = game->player->posx - 1;
	newy = game->player->posy;
	if (newx > 0 && newx < game->content->cols
		&& game->content->map[newy][newx] != '1')
	{
		ft_updateplayerpos(game, newx, newy, game->player->imgleft);
		return (1);
	}
	return (0);
}

int	ft_moveright(t_game *game)
{
	int			newx;
	int			newy;

	newx = game->player->posx + 1;
	newy = game->player->posy;
	if (newx > 0 && newx < game->content->cols
		&& game->content->map[newy][newx] != '1')
	{
		ft_updateplayerpos(game, newx, newy, game->player->imgright);
		return (1);
	}
	return (0);
}
