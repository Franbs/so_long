/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:29:40 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/04/12 14:56:22 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**ft_mallocmap(t_content *content, int fd)
{
	char	**map;
	int		i;
	char	*line;

	map = malloc(sizeof(char *) * (content->rows + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < content->rows)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map[i] = malloc(sizeof(char) * (content->cols + 1));
		if (!map[i])
			ft_error(1);
		ft_strlcpy(map[i], line, content->cols + 1);
		free(line);
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**ft_savemap(char *file, t_content *content)
{
	char	**map;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(1);
	map = ft_mallocmap(content, fd);
	return (map);
}

void	ft_print_map(char **map, t_content *content)
{
	int	i;

	if (!map)
		ft_error(1);
	printf("=== MAP DEBUG ===\n");
	printf("Dimensions: %d rows x %d cols\n", content->rows, content->cols);
	printf("Player: %d | Exits: %d | Collectibles: %d\n",
		content->p, content->e, content->c);
	i = 0;
	while (map[i] && i < content->rows)
	{
		printf("%2d: [%s]\n", i, map[i]);
		i++;
	}
	if (i != content->rows)
		printf("WARNING: Map has %d rows but content claims %d\n",
			i, content->rows);
	printf("=== END DEBUG ===\n");
}
