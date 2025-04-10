/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:31:52 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/04/07 18:31:52 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_content
{
	int	rows;
	int	cols;
	int	p;
	int	e;
	int	c;
}	t_content;

// utils.c
void	ft_error(int error);

// parser.c
char	*ft_checkext(char *av, char *ext);

// map.c
t_content	*ft_inimap();

#endif