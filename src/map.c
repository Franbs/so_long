/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:29:40 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/04/21 15:00:44 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_mallocmap(t_content *content, int fd)
{
	int		i;
	char	*line;

	content->map = malloc(sizeof(char *) * (content->rows + 1));
	if (!content->map)
		ft_error("Error", content, fd);
	i = 0;
	while (i < content->rows)
	{
		line = get_next_line(fd);
		if (!line)
			ft_error("Error", content, fd);
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		content->map[i] = malloc(sizeof(char) * (content->cols + 1));
		if (!content->map[i])
		{
			free(line);
			ft_error("Error", content, fd);
		}
		ft_strlcpy(content->map[i], line, content->cols + 1);
		free(line);
		i++;
	}
	content->map[i] = NULL;
}

void	ft_savemap(char *file, t_content *content)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Error opening file", content, fd);
	ft_mallocmap(content, fd);
	ft_cleangnl(fd);
	close(fd);
}

void	ft_print_map(t_content *content)
{
	int	i;

	if (!content->map)
		ft_error("Error", content, -1);
	ft_printf("========= MAP DEBUG =========\n");
	ft_printf("Dimensions: %d rows x %d cols\n", content->rows, content->cols);
	ft_printf("Player: %d | Exits: %d | Collectibles: %d\n",
		content->p, content->e, content->c);
	i = 0;
	while (content->map[i] && i < content->rows)
	{
		ft_printf("%d: [%s]\n", i, content->map[i]);
		i++;
	}
	if (i != content->rows)
		ft_printf("WARNING: Map has %d rows but content claims %d\n",
			i, content->rows);
	ft_printf("========= END DEBUG =========\n");
}
