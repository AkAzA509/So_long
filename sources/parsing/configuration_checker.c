/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configuration_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:27:25 by ggirault          #+#    #+#             */
/*   Updated: 2025/02/04 08:34:52 by ggirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long.h"

typedef struct s_map_count
{
	int		c_count;
	int		p_count;
	int		e_count;
}			t_map_count;

static bool	flood_fill(int pos_x, int pos_y, char target, char *map[])
{
	if (map[pos_x][pos_y] == 'E')
		return (true);
	if (map[pos_x][pos_y] == target || map[pos_x][pos_y] == 'C')
	{
		if (map[pos_x][pos_y] == '0')
			map[pos_x][pos_y] = 'F';
		if (flood_fill(pos_x - 1, pos_y, '0', map))
			return (true);
		if (flood_fill(pos_x + 1, pos_y, '0', map))
			return (true);
		if (flood_fill(pos_x, pos_y - 1, '0', map))
			return (true);
		if (flood_fill(pos_x, pos_y + 1, '0', map))
			return (true);
	}
	return (false);
}

static bool	check_pec(char *map[], t_map_count *map_count)
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
				map_count->p_count += 1;
			if (map[i][j] == 'E')
				map_count->e_count += 1;
			if (map[i][j] == 'C')
				map_count->c_count += 1;
			j++;
		}
		j = 0;
		i++;
	}
	if (map_count->p_count != 1 || map_count->e_count != 1
		|| map_count->c_count < 1)
		return (false);
	return (true);
}

static bool	check_line_lenght(char *line, int len)
{
	if (ft_strlen(line) - 1 != len)
		return (false);
	return (true);
}

static bool	check_border(char *map[])
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = tab_len(map) - 1;
	while (1)
	{
		if (map[0][i] == '\0' || map[j][i] == '\0')
			break ;
		if (map[0][i] != '1' || map[j][i] != '1')
			return (false);
		i++;
	}
	i = 0;
	k = 1;
	j = ft_strlen(map[1]) - 1;
	while (map[k] != NULL)
	{
		if (map[k][i] != '1' || map[k][j] != '1' || !check_line_lenght(map[k],
				j))
			return (false);
		k++;
	}
	return (true);
}

bool	configuration_checker(char *map[])
{
	t_map_count	*map_count;
	t_coor		*coor;

	map_count = malloc(sizeof(t_map_count));
	coor = malloc(sizeof(t_coor));
	if (!map || !coor)
	{
		free(map_count);
		// free(coor);
		perror("Error :");
		exit(1);
	}
	map_count->c_count = 0;
	map_count->e_count = 0;
	map_count->p_count = 0;
	find_coordonate(&coor, map);
	if (!check_border(map) || !check_pec(map, map_count)
		|| !flood_fill(coor->p_x_pos, coor->p_y_pos, 'P', map))
	{
		free(map_count);
		// free(coor);
		return (false);
	}
	free(map_count);
	return (true);
}
