/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:13:52 by ggirault          #+#    #+#             */
/*   Updated: 2025/01/30 19:36:27 by ggirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long.h"

static void	read_map(int fd)
{
	char **map_line;
	char *line;
	int	i;

	i = pre_parsing(fd);	
	map_line = malloc((sizeof(char *) * i) + 1);
	if (!map_line)
	{
		perror("Error : malloc have been failed");
		exit(1);
	}
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		printf("line = %s\n", line);
		if (line == NULL)
			break;
		map_line[i] = line;
		free(line);
		i++;
	}
	close(fd);
	map_line[i] = NULL;
	for(int j = 0; map_line[j] != NULL; j++)
		printf("map = %s\n", map_line[j]);
	free_split(map_line);
}

void	open_map(char *av[], int ac)
{
	int	fd;
	
	if (ac != 2)
	{
		write (2, "Error : invalid argument, please run with ./so_long and only one map.ber\n", 74);
		exit(1);
	}
	fd = open(av[1], O_RDONLY);
	printf("fd = %d\n", fd);
	if (fd < 0)
	{
		perror("Error : open file have been failed");
		exit(1);
	}
	read_map(fd);
	
}