/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:52:16 by ggirault          #+#    #+#             */
/*   Updated: 2025/02/12 18:08:21 by ggirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long_bonus.h"

void	find_coordonate(t_game **game, char *map[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				(*game)->coor->p_x_pos = i;
				(*game)->coor->p_y_pos = j;
				(*game)->coor->x = i;
				(*game)->coor->y = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	tab_len(char *tab[])
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

char	**remove_endline(char *map_tab[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_tab[i] != NULL)
	{
		while (map_tab[i][j])
		{
			if (map_tab[i][j] == '\n')
				map_tab[i][j] = '\0';
			j++;
		}
		j = 0;
		i++;
	}
	return (map_tab);
}

int	pre_parsing(int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		i++;
	}
	close(fd);
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
