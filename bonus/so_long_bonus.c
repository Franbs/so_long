/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:31:42 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/04/07 18:31:42 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_readmap(char *file, t_content *content)
{
	ft_getrowscols(file, content);
	ft_savemap(file, content);
	ft_countcontent(content);
}

void	ft_startmlx(t_content *content, char *file)
{
	t_game	*game;

	game = ft_initgame(content);
	ft_checkroutes(game, file);
	ft_print_map(game->content);
	ft_render(game);
	mlx_key_hook(game->mlx, &ft_move, game);
	mlx_loop_hook(game->mlx, &ft_openexit, game);
	mlx_loop(game->mlx);
	ft_freegame(game);
}

int	main(int ac, char **av)
{
	t_content	*content;

	if (ac != 2)
		ft_error("Error. Send only a file", NULL, -1);
	if (!ft_checkext(av[1], ".ber"))
		ft_error("Error. File ext must be .ber", NULL, -1);
	content = ft_initcontent();
	ft_readmap(av[1], content);
	ft_startmlx(content, av[1]);
	return (0);
}
