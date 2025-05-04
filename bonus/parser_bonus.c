/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:36:54 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/04/09 20:36:54 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_checkext(char *av, char *ext)
{
	int	len;
	int	lenext;
	int	start;

	if (ft_isalnum(av[0]) == 0)
		ft_error("Error. Wrong file name struct", NULL, -1);
	len = ft_strlen(av);
	lenext = ft_strlen(ext);
	start = (len - lenext);
	return (ft_strnstr(av + start, ext, lenext));
}
