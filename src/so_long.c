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

void	ft_readmap(char *file, t_content *content)
{
	ft_getrowscols(file, content);
	ft_savemap(file, content);
	ft_countcontent(content);
	ft_print_map(content);
}

void	ft_startmlx(t_content *content)
{
	mlx_t	*mlx;

	mlx = mlx_init((content->cols * IMG_W), (content->rows * IMG_H),
			"SO_LONG", false);
	mlx_key_hook(mlx, &ft_close, mlx);
	mlx_loop(mlx);
}

int	main(int ac, char **av)
{
	t_content	*content;

	if (ac != 2)
		ft_error("Error. Send only a file", NULL, -1);
	if (!ft_checkext(av[1], ".ber"))
		ft_error("Error. File ext must be .ber", NULL, -1);
	content = ft_initcontent();
	ft_readmap(av[1], content);
	ft_startmlx(content);
	ft_freecontent(content);
	return (0);
}
