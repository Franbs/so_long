/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:55:59 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/05/31 16:14:40 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

mlx_texture_t	*ft_applytexture(char *path, t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		ft_errorgame("Error loading textures.", game, -1);
	return (texture);
}

void	ft_settextures(t_game *game)
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
	texture = ft_applytexture("./sprites/enemy.png", game);
	game->enemyimg = mlx_texture_to_image(game->mlx, texture);
	ft_freetexture(texture);
}

t_game	*ft_initgame(t_content *content)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_error("Error.", content, -1);
	game->content = content;
	game->mlx = mlx_init((content->cols * IMG_W), (content->rows * IMG_H),
			"so_long", true);
	if (!game->mlx)
		ft_errorgame("Error al inicializar mlx.", game, -1);
	game->player = ft_initplayer(game);
	ft_settextures(game);
	game->moves = 0;
	game->enemies = ft_initenemies(game);
	game->movestxtimg = NULL;
	return (game);
}

void	ft_freegame(t_game *game)
{
	if (!game)
		return ;
	ft_freeimg(game);
	if (game->player)
		free(game->player);
	ft_freeenemies(game);
	if (game->content)
		ft_freecontent(game->content);
	if (game->mlx)
		mlx_terminate(game->mlx);
	free(game);
}

void	ft_checkexit(t_game *game, char oldtile, char newtile)
{
	if (newtile == 'C')
		game->content->c--;
	if (newtile == 'E' && game->content->c <= 0)
		ft_win("YOU WON!", game);
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
