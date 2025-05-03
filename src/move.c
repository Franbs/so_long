/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:25:53 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/05/03 20:17:24 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_checkexit(t_game *game, char oldtile, char newtile)
{
	if (newtile == 'C')
		game->content->c--;
	if (newtile == 'E' && game->content->c <= 0)
	{
		ft_printf("moves: %d\n", (game->moves + 1));
		ft_win("YOU WON!", game);
	}
	if (oldtile == 'E')
	{
		mlx_image_to_window(game->mlx, game->eimg,
			game->player->posx * IMG_W, game->player->posy * IMG_H);
	}
	else
	{
		mlx_image_to_window(game->mlx, game->floorimg,
			game->player->posx * IMG_W, game->player->posy * IMG_H);
	}
}

int	ft_moveup(t_game *game)
{
	int			newy;
	char		newtile;
	char		oldtile;

	newy = game->player->posy - 1;
	newtile = ft_gettile(game, game->player->posx, newy);
	oldtile = ft_gettile(game, game->player->posx, game->player->posy);
	if (newy > 0 && newy < game->content->rows && newtile != '1')
	{
		ft_checkexit(game, oldtile, newtile);
		if (newtile != 'E')
		{
			ft_swaptile(game, game->player->posx, newy, 'P');
			if (oldtile != 'E')
				ft_swaptile(game, game->player->posx, game->player->posy, '0');
		}
		else if (newtile == 'E')
			ft_swaptile(game, game->player->posx, game->player->posy, '0');
		mlx_image_to_window(game->mlx, game->player->imgup,
			game->player->posx * IMG_W, newy * IMG_H);
		game->player->posy -= 1;
	}
	return (1);
}

int	ft_movedown(t_game *game)
{
	int			newy;
	char		newtile;
	char		oldtile;

	newy = game->player->posy + 1;
	newtile = ft_gettile(game, game->player->posx, newy);
	oldtile = ft_gettile(game, game->player->posx, game->player->posy);
	if (newy > 0 && newy < game->content->rows && newtile != '1')
	{
		ft_checkexit(game, oldtile, newtile);
		if (newtile != 'E')
		{
			ft_swaptile(game, game->player->posx, newy, 'P');
			ft_swaptile(game, game->player->posx, game->player->posy, '0');
		}
		else if (newtile == 'E')
			ft_swaptile(game, game->player->posx, game->player->posy, '0');
		mlx_image_to_window(game->mlx, game->player->imgdown,
			game->player->posx * IMG_W, newy * IMG_H);
		game->player->posy += 1;
	}
	return (1);
}

int	ft_moveleft(t_game *game)
{
	int			newx;
	char		newtile;
	char		oldtile;

	newx = game->player->posx - 1;
	newtile = ft_gettile(game, newx, game->player->posy);
	oldtile = ft_gettile(game, game->player->posx, game->player->posy);
	if (newx > 0 && newx < game->content->cols && newtile != '1')
	{
		ft_checkexit(game, oldtile, newtile);
		if (newtile != 'E')
		{
			ft_swaptile(game, newx, game->player->posy, 'P');
			ft_swaptile(game, game->player->posx, game->player->posy, '0');
		}
		else if (newtile == 'E')
			ft_swaptile(game, game->player->posx, game->player->posy, '0');
		mlx_image_to_window(game->mlx, game->player->imgleft,
			newx * IMG_W, game->player->posy * IMG_H);
		game->player->posx -= 1;
	}
	return (1);
}

int	ft_moveright(t_game *game)
{
	int			newx;
	char		newtile;
	char		oldtile;

	newx = game->player->posx + 1;
	newtile = ft_gettile(game, newx, game->player->posy);
	oldtile = ft_gettile(game, game->player->posx, game->player->posy);
	if (newx > 0 && newx < game->content->cols && newtile != '1')
	{
		ft_checkexit(game, oldtile, newtile);
		if (newtile != 'E')
		{
			ft_swaptile(game, newx, game->player->posy, 'P');
			ft_swaptile(game, game->player->posx, game->player->posy, '0');
		}
		else if (newtile == 'E')
			ft_swaptile(game, game->player->posx, game->player->posy, '0');
		mlx_image_to_window(game->mlx, game->player->imgright,
			newx * IMG_W, game->player->posy * IMG_H);
		game->player->posx += 1;
	}
	return (1);
}
