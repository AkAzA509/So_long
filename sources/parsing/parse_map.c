/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:13:52 by ggirault          #+#    #+#             */
/*   Updated: 2025/01/31 13:31:52 by ggirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long.h"

static bool	format_checker(char **map_tab)
{
	if (ft_strlen(map_tab[0]) == tab_len(map_tab))
		return (false);
	return (true);
}

static char	**read_map(int fd, char *file)
{
	char	**map_tab;
	char *line;
	int	i;

	i = pre_parsing(fd);
	fd = open(file, O_RDONLY);
	map_tab = malloc(sizeof(char *) *(i + 1));
	if (!map_tab || fd < 0)
	{
		perror("Error :");
		exit(1);
	}
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		map_tab[i] = line;
		i++;
	}
	map_tab[i]= NULL;
	close(fd);
	map_tab = remove_endline(map_tab);
	return (map_tab);
}

void	open_map(char *av[], int ac)
{
	int	fd;
	char	**map_tab;
	
	if (ac != 2)
	{
		write (2, "Error : invalid argument, please run with ./so_long and only one map.ber\n", 74);
		exit(1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error :");
		exit(1);
	}
	map_tab = read_map(fd, av[1]);
	if (!format_checker(map_tab) || !configuration_checker(map_tab))
	{
		write(2, "Error\n", 6);
		write(2, "the map is not rectangular or well construct", 45);
		free_split(map_tab);
	}
}
