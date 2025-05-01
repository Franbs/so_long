/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:27:54 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/05/01 17:59:11 by fbanzo-s         ###   ########.fr       */
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
	if (game->pimg)
		mlx_delete_image(game->mlx, game->pimg);
}

void	ft_freetexture(mlx_texture_t	*texture)
{
	if (texture)
		mlx_delete_texture(texture);
}
