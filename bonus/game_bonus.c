/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:55:59 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/05/04 15:47:44 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

mlx_texture_t	*ft_applytexture(char *path, t_game_bonus *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		ft_errorgame("Error loading textures.", game, -1);
	return (texture);
}

void	ft_settextures(t_game_bonus *game)
{
	mlx_texture_t	*texture;

	texture = ft_applytexture("./sprites/floor.png", game);
	game->floorimg = mlx_texture_to_image(game->mlx, texture);
	ft_freetexture(texture);
	texture = ft_applytexture("./sprites/wall3.png", game);
	game->wallimg = mlx_texture_to_image(game->mlx, texture);
	ft_freetexture(texture);
	texture = ft_applytexture("./sprites/coinsmall.png", game);
	game->cimg = mlx_texture_to_image(game->mlx, texture);
	ft_freetexture(texture);
	texture = ft_applytexture("./sprites/exit.png", game);
	game->eimg = mlx_texture_to_image(game->mlx, texture);
	ft_freetexture(texture);
	texture = ft_applytexture("./sprites/exit2.png", game);
	game->eimgopen = mlx_texture_to_image(game->mlx, texture);
	ft_freetexture(texture);
}

t_game	*ft_initgame(t_content_bonus *content)
{
	t_game_bonus	*game;

	game = malloc(sizeof(t_game_bonus));
	if (!game)
		ft_error("Error.", content, -1);
	game->content = content;
	game->mlx = mlx_init((content->cols * IMG_W), (content->rows * IMG_H),
			"so_long", false);
	if (!game->mlx)
		ft_errorgame("Error al inicializar mlx.", game, -1);
	game->player = ft_initplayer(game);
	ft_settextures(game);
	game->moves = 0;
	return (game);
}

void	ft_freegame(t_game_bonus *game)
{
	if (!game)
		return ;
	ft_freeimg(game);
	if (game->player)
		free(game->player);
	if (game->content)
		ft_freecontent(game->content);
	if (game->mlx)
		mlx_terminate(game->mlx);
	free(game);
}

void	ft_checkexit(t_game_bonus *game, char oldtile, char newtile)
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
