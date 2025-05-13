/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:16:45 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/05/13 19:24:08 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_mapdup	*ft_initmapdup(t_game *game)
{
	t_mapdup	*mapdup;

	mapdup = malloc(sizeof(t_mapdup));
	if (!mapdup)
		ft_errorgame("Error.", game, -1);
	mapdup->map = NULL;
	mapdup->rows = game->content->rows;
	mapdup->cols = game->content->cols;
	mapdup->c = 0;
	mapdup->e = 0;
	return (mapdup);
}

void	ft_freemapdup(t_mapdup *mapdup)
{
	int	i;

	if (!mapdup)
		return ;
	if (mapdup->map)
	{
		i = 0;
		while (i < mapdup->rows && mapdup->map[i])
		{
			free(mapdup->map[i]);
			i++;
		}
		free(mapdup->map);
	}
	free(mapdup);
}

void	ft_freeall(t_game *game, t_mapdup *mapdup, int fd)
{
	ft_freemapdup(mapdup);
	ft_errorgame("Error", game, fd);
}

void	ft_mallocmapdup(t_game *game, t_mapdup *mapdup, int fd)
{
	int		i;
	char	*line;

	mapdup->map = malloc(sizeof(char *) * (mapdup->rows + 1));
	if (!mapdup->map)
		ft_freeall(game, mapdup, fd);
	i = 0;
	while (i < mapdup->rows)
	{
		line = get_next_line(fd);
		if (!line)
			ft_freeall(game, mapdup, fd);
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		mapdup->map[i] = malloc(sizeof(char) * (mapdup->cols + 1));
		if (!mapdup->map[i])
		{
			free(line);
			ft_freeall(game, mapdup, fd);
		}
		ft_strlcpy(mapdup->map[i], line, mapdup->cols + 1);
		free(line);
		i++;
	}
	mapdup->map[i] = NULL;
}

void	ft_savemapdup(t_game *game, t_mapdup *mapdup, char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_freemapdup(mapdup);
		ft_errorgame("Error opening file", game, fd);
	}
	ft_mallocmapdup(game, mapdup, fd);
	ft_cleangnl(fd);
	close(fd);
}
