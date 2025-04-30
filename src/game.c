/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:55:59 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/04/30 17:41:47 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_game	*ft_initgame(t_content *content)
{
	t_game	*game;
	mlx_texture_t	*floorTex;
	mlx_texture_t	*wallTex;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->content = content;
	game->mlx = mlx_init((content->cols * IMG_W), (content->rows * IMG_H),
			"so_long", false);
	if (!game->mlx)
		ft_error("Error al inicializar mlx.", content, -1);
	floorTex = mlx_load_png("./sprites/floor.png");
	if (!floorTex)
		ft_error("Error al cargar texturas.", content, -1);
	game->floor = mlx_texture_to_image(game->mlx, floorTex);
	wallTex = mlx_load_png("./sprites/wall.png");
	game->wall = mlx_texture_to_image(game->mlx, wallTex);
	return (game);
}

void	ft_freegame(t_game *game)
{
    if (!game)
		return;
	if (game->content)
		ft_freecontent(game->content);
    if (game->mlx)
		mlx_terminate(game->mlx);
    free(game);
}

void	ft_render(t_game *game)
{
	int	i;
	int	j;

	i = 0;
    while (i < game->content->rows) {
        j = 0;
        while (j < game->content->cols) {
            char tile = game->content->map[i][j];
            mlx_image_to_window(game->mlx, game->floor, j * IMG_W, i * IMG_H);
            if (tile == '1')
                mlx_image_to_window(game->mlx, game->wall, j * IMG_W, i * IMG_H);
			j++;
        }
		i++;
    }
}
