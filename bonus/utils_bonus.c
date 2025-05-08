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

#include "../includes/so_long_bonus.h"

void	ft_error(char *str, t_content *content, int fd)
{
	if (fd >= 0)
		ft_cleangnl(fd);
	if (content)
		ft_freecontent(content);
	ft_printf("%s\n", str);
	exit(1);
}

void	ft_errorgame(char *str, t_game *game, int fd)
{
	if (fd >= 0)
		ft_cleangnl(fd);
	if (game)
		ft_freegame(game);
	ft_printf("%s\n", str);
	exit(1);
}

void	ft_cleangnl(int fd)
{
	char	*line;

	if (fd < 0)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	ft_win(char *str, t_game *game)
{
	if (game)
		ft_freegame(game);
	ft_printf("%s\n", str);
	exit(1);
}
