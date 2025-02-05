/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:13:52 by ggirault          #+#    #+#             */
/*   Updated: 2025/02/05 14:44:36 by ggirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long.h"

void	struct_alloc(t_game **game)
{
	(*game) = malloc(sizeof(t_game));
	(*game)->coor = malloc(sizeof(t_coor));
	(*game)->window = malloc(sizeof(t_window));
	(*game)->data = malloc(sizeof(t_data));
	(*game)->wall_text = malloc(sizeof(t_data));
	(*game)->floor_text = malloc(sizeof(t_data));
	(*game)->player_text = malloc(sizeof(t_data));
	(*game)->objs_text = malloc(sizeof(t_data));
	(*game)->exit_text = malloc(sizeof(t_data));
	(*game)->sakura = malloc(sizeof(t_data));
	(*game)->pine = malloc(sizeof(t_data));
	if (!(*game) || !(*game)->window || !(*game)->data || !(*game)->wall_text
		|| !(*game)->floor_text || !(*game)->player_text || !(*game)->objs_text
		|| !(*game)->exit_text || !(*game)->sakura || !(*game)->pine)
	{
		ft_free(game);
		exit(1);
	}
}

static bool	format_checker(char **map_tab, t_game **game)
{
	if (ft_strlen(map_tab[0]) == tab_len(map_tab))
		return (false);
	(*game)->width = ft_strlen(map_tab[0]);
	(*game)->height = tab_len(map_tab);
	return (true);
}

static char	**read_map(int fd, char *file)
{
	char	**map_tab;
	char	*line;
	int		i;

	i = pre_parsing(fd);
	fd = open(file, O_RDONLY);
	map_tab = malloc(sizeof(char *) * (i + 1));
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
			break ;
		map_tab[i] = line;
		i++;
	}
	map_tab[i] = NULL;
	close(fd);
	map_tab = remove_endline(map_tab);
	return (map_tab);
}

void	open_map(char *av[], int ac, t_game **game)
{
	int		fd;
	char	**map_tab;

	if (ac != 2)
	{
		write(2, "Error : invalid argument, please run", 37);
		write(2, " with ./so_long and only one map.ber\n", 37);
		exit(1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error :");
		exit(1);
	}
	map_tab = read_map(fd, av[1]);
	struct_alloc(game);
	if (!format_checker(map_tab, game) || !configuration_checker(map_tab, game))
	{
		write(2, "Error\nThe map doesn't match, please check it!\n", 46);
		free_split(map_tab);
		ft_free(game);
		exit(1);
	}
	(*game)->map = map_tab;
}
