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

typedef	struct s_player
{
	int			posx;
	int			posy;
	mlx_image_t	*imgup;
	mlx_image_t	*imgdown;
	mlx_image_t	*imgleft;
	mlx_image_t	*imgright;
}	t_player;


typedef struct s_game
{
	t_content	*content;
	t_player	*player;
	mlx_t		*mlx;
	mlx_image_t	*wallimg;
	mlx_image_t	*floorimg;
	mlx_image_t	*cimg;
	mlx_image_t	*eimg;
	int			moves;
}	t_game;


// utils.c
void		ft_error(char *str, t_content *content, int fd);
void		ft_errorgame(char *str, t_game *game, int fd);
void		ft_cleangnl(int fd);
void		ft_win(char *str, t_game *game);
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
char		ft_gettile(t_game *game, int x, int y);
// render.c
void		ft_render(t_game *game);
void		ft_move(mlx_key_data_t keydata, void *param);
void		ft_swaptile(t_game *game, int x, int y, char newchar);
// player.c
t_player	*ft_initplayer(t_game *game);
int			ft_getx(t_game *game);
int			ft_gety(t_game *game);
// move.c
int		ft_moveup(t_game *game);
int		ft_movedown(t_game *game);
int		ft_moveleft(t_game *game);
int		ft_moveright(t_game *game);

#endif