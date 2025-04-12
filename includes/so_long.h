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
void		ft_error(int error);
void		ft_getrowscols(char *file, t_content *content);
// parser.c
char		*ft_checkext(char *av, char *ext);
// map.c
void		ft_print_map(char **map, t_content *content);
char		**ft_savemap(char *file, t_content *content);
// content.c
t_content	*ft_initmap(void);
void		ft_checkforcontent(char c, t_content *content);
void		ft_countcontent(char **map, t_content *content);

#endif