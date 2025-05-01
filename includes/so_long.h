/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:31:52 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/04/07 18:31:52 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <limits.h>
# define IMG_W 32
# define IMG_H 32

typedef struct s_content
{
	char	**map;
	int		rows;
	int		cols;
	int		p;
	int		e;
	int		c;
}	t_content;

typedef struct s_game
{
	t_content	*content;
	mlx_t		*mlx;
	mlx_image_t	*wallimg;
	mlx_image_t	*floorimg;
	mlx_image_t	*cimg;
	mlx_image_t	*pimg;
	mlx_image_t	*eimg;
}	t_game;


// utils.c
void		ft_error(char *str, t_content *content, int fd);
void		ft_errorgame(char *str, t_game *game, int fd);
void		ft_cleangnl(int fd);
// utils_content.c
void		ft_getrowscols(char *file, t_content *content);
void		ft_countcontent(t_content *content);
// parser.c
char		*ft_checkext(char *av, char *ext);
// map.c
void		ft_print_map(t_content *content);
void		ft_savemap(char *file, t_content *content);
// content.c
t_content	*ft_initcontent(void);
void		ft_freecontent(t_content *content);
// mlx_utils.c
void		ft_close(mlx_key_data_t keydata, void* param);
void		ft_freeimg(t_game *game);
void		ft_freetexture(mlx_texture_t	*texture);
// game.c
t_game		*ft_initgame(t_content *content);
void		ft_freegame(t_game *game);
// render.c
void		ft_render(t_game *game);

#endif