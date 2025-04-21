/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:44:20 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/04/21 14:57:21 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_setcols(t_content *content, char *line, int current_len, int fd)
{
	if (content->rows == 0)
		content->cols = current_len;
	else
	{
		if (content->cols != current_len)
		{
			free(line);
			ft_error("Error. All rows and cols must have same length",
				content, fd);
		}
	}
}

void	ft_getrowscols(char *file, t_content *content)
{
	int			fd;
	char		*line;
	int			current_len;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Error opening file", content, fd);
	line = get_next_line(fd);
	while (line)
	{
		current_len = (int)ft_strlen(line);
		if (current_len > 0 && line[current_len - 1] == '\n')
			current_len--;
		ft_setcols(content, line, current_len, fd);
		content->rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	ft_checkborders(char c, int i, int j, t_content *content)
{
	if (i == 0 && c != '1')
		ft_error("Error. All borders must be 1", content, -1);
	else if (i == (content->rows - 1) && c != '1')
		ft_error("Error. All borders must be 1", content, -1);
	else if (j == 0 && c != '1')
		ft_error("Error. All borders must be 1", content, -1);
	else if (j == (content->cols - 1) && c != '1')
		ft_error("Error. All borders must be 1", content, -1);
}

void	ft_checkforcontent(char c, t_content *content)
{
	if (c == 'E')
		content->e++;
	else if (c == 'P')
		content->p++;
	else if (c == 'C')
		content->c++;
	else if (c != '0' && c != '1')
		ft_error("Error. Wrong char detected", content, -1);
}

void	ft_countcontent(t_content *content)
{
	int	i;
	int	j;

	if (!content->map || !content)
		ft_error("Error", content, -1);
	i = 0;
	while (content->map[i])
	{
		j = 0;
		while (content->map[i][j])
		{
			ft_checkforcontent(content->map[i][j], content);
			ft_checkborders(content->map[i][j], i, j, content);
			j++;
		}
		i++;
	}
	if (content->c < 1 || content->e != 1 || content->p != 1)
		ft_error("Error. At least 1 c, only 1 e and p", content, -1);
}
