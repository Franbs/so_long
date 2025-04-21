/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:29:40 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/04/21 13:55:51 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_mallocmap(t_content *content, int fd)
{
	int		i;
	char	*line;

	content->map = malloc(sizeof(char *) * (content->rows + 1));
	if (!content->map)
		return ;
	i = 0;
	while (i < content->rows)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		content->map[i] = malloc(sizeof(char) * (content->cols + 1));
		if (!content->map[i])
			ft_error("Error");
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
		ft_error("Error opening file");
	ft_mallocmap(content, fd);
}

void	ft_print_map(t_content *content)
{
	int	i;

	if (!content->map)
		ft_error("Error");
	printf("========= MAP DEBUG =========\n");
	printf("Dimensions: %d rows x %d cols\n", content->rows, content->cols);
	printf("Player: %d | Exits: %d | Collectibles: %d\n",
		content->p, content->e, content->c);
	i = 0;
	while (content->map[i] && i < content->rows)
	{
		printf("%2d: [%s]\n", i, content->map[i]);
		i++;
	}
	if (i != content->rows)
		printf("WARNING: Map has %d rows but content claims %d\n",
			i, content->rows);
	printf("========= END DEBUG =========\n");
}
