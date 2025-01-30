/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:52:16 by ggirault          #+#    #+#             */
/*   Updated: 2025/01/30 18:59:54 by ggirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long.h"

int	pre_parsing(int fd)
{
	int	i;
	char *line;
	
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		free(line);
		i++;
	}
	return (i);
}

void	free_split(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}