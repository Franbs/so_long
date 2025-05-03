/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:55:59 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/05/03 18:34:22 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
}

t_game	*ft_initgame(t_content *content)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
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

char	ft_gettile(t_game *game, int x, int y)
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
				return (tile);
			j++;
		}
		i++;
	}
	return ('\0');
}
