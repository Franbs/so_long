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

#include "../includes/so_long.h"

void	ft_getrowscols(t_content  *content, char *map)
{
	int			fd;
	char		*line;
	int			current_len;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error(1);
	line = get_next_line(fd);
	while (line)
	{
		current_len = ft_strlen(line);
		if (line[current_len - 1] == '\n')
			current_len--;
		if (content->rows == 0)
			content->cols == ft_strlen(line - 1);
		else
		{
			if (content->cols != ft_strlen(line - 1))
				ft_error(1);
		}
		content->rows++;
		free(line);
		line = get_next_line(fd);
	}
}

void	ft_readmap(char *map)
{
	t_content	*content;

	content = ft_inimap();
	ft_getrowscols(content, map);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		ft_error(1);
	if (!ft_checkext(av[1], ".ber"))
		ft_error(1);
	ft_readmap(av[1]);
	return (0);
}
