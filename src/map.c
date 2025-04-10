/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:29:40 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/04/10 18:40:24 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_content	*ft_inimap()
{
	t_content	*map;

	map = malloc(sizeof(t_content));
	if (!map)
		return (NULL);
	map->rows = 0;
	map->cols = 0;
	map->p = 0;
	map->e = 0;
	map->c = 0;

	return (map);
}
