/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:27:54 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/05/03 18:01:10 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_close(mlx_key_data_t keydata, void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mlx);
}

void	ft_freeimg(t_game *game)
{
	if (game->floorimg)
		mlx_delete_image(game->mlx, game->floorimg);
	if (game->wallimg)
		mlx_delete_image(game->mlx, game->wallimg);
	if (game->cimg)
		mlx_delete_image(game->mlx, game->cimg);
	if (game->eimg)
		mlx_delete_image(game->mlx, game->eimg);
	if (game->player->imgdown)
		mlx_delete_image(game->mlx, game->player->imgdown);
	if (game->player->imgup)
		mlx_delete_image(game->mlx, game->player->imgup);
	if (game->player->imgleft)
		mlx_delete_image(game->mlx, game->player->imgleft);
	if (game->player->imgright)
		mlx_delete_image(game->mlx, game->player->imgright);
}

void	ft_freetexture(mlx_texture_t	*texture)
{
	if (texture)
		mlx_delete_texture(texture);
}
