/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:12:20 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/05/31 16:11:50 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

t_enemy	ft_initenemy(int x, int y)
{
	t_enemy	enemy;

	enemy.posx = x;
	enemy.posy = y;
	return (enemy);
}

t_enemy	*ft_initenemies(t_game *game)
{
	int		i;
	int		j;
	int		k;
	t_enemy	*enemies;

	enemies = malloc(sizeof(t_enemy) * game->content->enemy);
	if (!enemies)
		ft_errorgame("Error.", game, -1);
	k = 0;
	i = 0;
	while (i < game->content->rows)
	{
		j = 0;
		while (j < game->content->cols)
		{
			if (game->content->map[i][j] == 'T')
				enemies[k] = ft_initenemy(i, j);
			j++;
		}
		i++;
	}
	return (enemies);
}

void	ft_freeenemies(t_game *game)
{
	if (game && game->enemies)
	{
		free(game->enemies);
		game->enemies = NULL;
	}
}
