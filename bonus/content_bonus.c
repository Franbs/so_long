/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 14:55:27 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/05/04 15:45:31 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_content_bonus	*ft_initcontent(void)
{
	t_content_bonus	*content;

	content = malloc(sizeof(t_content_bonus));
	if (!content)
		return (NULL);
	content->map = NULL;
	content->rows = 0;
	content->cols = 0;
	content->p = 0;
	content->e = 0;
	content->c = 0;
	return (content);
}

void	ft_freecontent(t_content_bonus *content)
{
	int	i;

	if (!content)
		return ;
	if (content->map)
	{
		i = 0;
		while (i < content->rows && content->map[i])
		{
			free(content->map[i]);
			i++;
		}
		free(content->map);
	}
	free(content);
}
