/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 14:55:27 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/04/12 14:56:49 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_content	*ft_initcontent(void)
{
	t_content	*content;

	content = malloc(sizeof(t_content));
	if (!content)
		return (NULL);
	content->rows = 0;
	content->cols = 0;
	content->p = 0;
	content->e = 0;
	content->c = 0;
	return (content);
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
		ft_error(1);
}

void	ft_countcontent(char **map, t_content *content)
{
	int	i;
	int	j;

	if (!map || !content)
		ft_error(1);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_checkforcontent(map[i][j], content);
			j++;
		}
		i++;
	}
	if (content->c < 1 || content->e != 1 || content->p != 1)
		ft_error(1);
}
