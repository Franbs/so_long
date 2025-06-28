/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:55:59 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/06/28 18:26:40 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

mlx_image_t	*ft_applytexture(char *path, t_game *game)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
		ft_errorgame("Error loading textures.", game, -1);
	image = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
		ft_errorgame("Error loading images.", game, -1);
	return (image);
}

void	ft_settextures(t_game *game)
{
	game->floorimg = ft_applytexture("./sprites/floor.png", game);
	game->wallimg = ft_applytexture("./sprites/wall3.png", game);
	game->cimg = ft_applytexture("./sprites/coinsmall.png", game);
	game->eimg = ft_applytexture("./sprites/exit.png", game);
	game->eimgopen = ft_applytexture("./sprites/exit2.png", game);
}

t_game	*ft_initgame(t_content *content)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_error("Error.", content, -1);
	game->mlx = NULL;
	game->player = NULL;
	game->floorimg = NULL;
	game->wallimg = NULL;
	game->cimg = NULL;
	game->eimg = NULL;
	game->eimgopen = NULL;
	game->moves = 0;
	game->content = content;
	game->mlx = mlx_init((content->cols * IMG_W), (content->rows * IMG_H),
			"so_long", true);
	if (!game->mlx)
		ft_errorgame("Error al inicializar mlx.", game, -1);
	game->player = ft_initplayer(game);
	ft_settextures(game);
	game->moves = 0;
	return (game);
}

void	ft_freegame(t_game *game)
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
