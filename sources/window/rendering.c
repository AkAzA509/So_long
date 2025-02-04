/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:49:39 by ggirault          #+#    #+#             */
/*   Updated: 2025/02/04 15:09:23 by ggirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long.h"

static int	rewrite_pixel(t_game *game, int width, int *new_data, int *data)
{
	int	new_x;
	int	new_y;
	int	old_x;
	int	old_y;

	new_y = 0;
	while (new_y < game->tile_size)
	{
		new_x = 0;
		while (new_x < game->tile_size)
		{
			old_x = (new_x * width) / game->tile_size;
			old_y = (new_y * width) / game->tile_size;
			new_data[new_y * game->tile_size + new_x] = data[old_y * width
				+ old_x];
			new_x++;
		}
		new_y++;
	}
	return (0);
}

static void	resize_texture(t_data **texture, int width, t_game *game)
{
	void	*new;
	int		*data;
	int		*new_data;

	new = mlx_new_image(game->window->mlx, game->tile_size, game->tile_size);
	data = (int *)mlx_get_data_addr((*texture)->img,
			&(*texture)->bits_per_pixel, &(*texture)->line_length,
			&(*texture)->endian);
	new_data = (int *)mlx_get_data_addr(new, &(*texture)->bits_per_pixel,
			&(*texture)->line_length, &(*texture)->endian);
	rewrite_pixel(game, width, new_data, data);
	mlx_destroy_image(game->window->mlx, (*texture)->img);
	(*texture)->img = new;
}

static void	load_texture(t_game **game)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	(*game)->floor_text->img = mlx_xpm_file_to_image((*game)->window->mlx,
			"texture/floor.xpm", &width, &height);
	resize_texture(&(*game)->floor_text, width, *game);
	(*game)->est_wall_text->img = mlx_xpm_file_to_image((*game)->window->mlx,
			"texture/est_wall.xpm", &width, &height);
	resize_texture(&(*game)->est_wall_text, width, *game);
	(*game)->west_wall_text->img = mlx_xpm_file_to_image((*game)->window->mlx,
			"texture/west_wall.xpm", &width, &height);
	resize_texture(&(*game)->west_wall_text, width, *game);
	(*game)->wall_text->img = mlx_xpm_file_to_image((*game)->window->mlx,
			"texture/wall_top_floor.xpm", &width, &height);
	resize_texture(&(*game)->wall_text, width, *game);
	(*game)->player_text->img = mlx_xpm_file_to_image((*game)->window->mlx,
			"texture/patrick.xpm", &width, &height);
	resize_texture(&(*game)->player_text, width, *game);
	(*game)->sakura->img = mlx_xpm_file_to_image((*game)->window->mlx,
			"texture/sakura_tree.xpm", &width, &height);
	resize_texture(&(*game)->sakura, width, *game);
	(*game)->pine->img = mlx_xpm_file_to_image((*game)->window->mlx,
			"texture/pine_tree.xpm", &width, &height);
	resize_texture(&(*game)->pine, width, *game);
	if (!(*game)->floor_text || !(*game)->est_wall_text
		|| !(*game)->west_wall_text || !(*game)->wall_text)
	{
		perror("Error ");
		exit(1);
	}
}

void	render_wall(t_game *game, int i, int j)
{
	int	x;
	int	y;

	x = j * game->tile_size;
	y = i * game->tile_size;
	printf("i = %d, j = %d\n", i, j);
	if (i >= 1 && i < (tab_len(game->map) - 1) && j == (ft_strlen(game->map[i]) - 1))
	{
		printf("test est\n");
		mlx_put_image_to_window(game->window->mlx, game->window->win, game->est_wall_text->img, x, y);
	}
	else if (i >= 1 && i < (tab_len(game->map) - 1) && j == 0)
	{
		printf("test west\n");
		mlx_put_image_to_window(game->window->mlx, game->window->win, game->west_wall_text->img, x, y);
	}
	else
	{
		printf("test wall\n");
		mlx_put_image_to_window(game->window->mlx, game->window->win, game->wall_text->img, x, y);
	}
}

void	rendering(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	j = 0;
	load_texture(&game);
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			x = j * game->tile_size;
			y = i * game->tile_size;
			if (game->map[i][j] == '1')
				render_wall(game, i, j);
			else if (game->map[i][j] == '0' || game->map[i][j] == 'P')
				mlx_put_image_to_window(game->window->mlx, game->window->win,
					game->floor_text->img, x, y);
			else if (game->map[i][j] == 'F')
			{
				mlx_put_image_to_window(game->window->mlx, game->window->win, game->floor_text->img, x, y);
				mlx_put_image_to_window(game->window->mlx, game->window->win, game->sakura->img, x, y);
			}
			j++;
		}
		i++;
	}
}
