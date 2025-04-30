/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:27:54 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/04/29 18:56:37 by fbanzo-s         ###   ########.fr       */
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

mlx_image_t    *ft_load_textures(t_content *content, mlx_t *mlx)
{
    mlx_texture_t	*texture;
	mlx_image_t	*wall_img;

    texture = mlx_load_png("./sprites/wall.png");
    if (!texture)
        ft_error("Error loading texture", content, -1);
    wall_img = mlx_texture_to_image(mlx, texture);
    mlx_delete_texture(texture);
	return (wall_img);
}

void    ft_render_map(t_content *content, mlx_t *mlx, mlx_image_t *wall_img)
{
    int i;
    int j;

    i = 0;
    while (i < content->rows)
    {
        j = 0;
        while (j < content->cols)
        {
            if (content->map[i][j] == '1')
            {
                mlx_image_to_window(mlx, wall_img, j * IMG_W, i * IMG_H);
            }
            j++;
        }
        i++;
    }
}
