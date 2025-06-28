/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:49:25 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/06/28 18:33:57 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_gety(t_game *game)
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
			if (tile == 'P')
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int	ft_getx(t_game *game)
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
			if (tile == 'P')
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}

t_player	*ft_initplayer(t_game *game)
{
	t_player		*player;

	player = malloc(sizeof(t_player));
	if (!player)
		ft_errorgame("Error.", game, -1);
	player->posx = ft_getx(game);
	player->posy = ft_gety(game);
	player->imgdown = ft_applytexture("./sprites/player.png", game);
	player->imgup = ft_applytexture("./sprites/playerup.png", game);
	player->imgleft = ft_applytexture("./sprites/playerleft.png", game);
	player->imgright = ft_applytexture("./sprites/playerright.png", game);
	return (player);
}
