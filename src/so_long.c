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

void	ft_readmap(char *file)
{
	t_content	*content;

	content = ft_initcontent();
	ft_getrowscols(file, content);
	ft_savemap(file, content);
	ft_countcontent(content);
	ft_print_map(content);
	ft_freecontent(content);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		ft_error("Error. Send only a file", NULL, -1);
	if (!ft_checkext(av[1], ".ber"))
		ft_error("Error. File ext must be .ber", NULL, -1);
	ft_readmap(av[1]);
	return (0);
}
