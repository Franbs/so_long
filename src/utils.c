/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:37:37 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/04/09 20:37:37 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error(int error)
{
	if (error == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

void	ft_getrowscols(char *file, t_content *content)
{
	int			fd;
	char		*line;
	int			current_len;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(1);
	line = get_next_line(fd);
	while (line)
	{
		current_len = (int)ft_strlen(line);
		if (current_len > 0 && line[current_len - 1] == '\n')
			current_len--;
		if (content->rows == 0)
			content->cols = current_len;
		else
		{
			if (content->cols != current_len)
				ft_error(1);
		}
		content->rows++;
		free(line);
		line = get_next_line(fd);
	}
}
