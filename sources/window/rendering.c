/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:49:39 by ggirault          #+#    #+#             */
/*   Updated: 2025/02/05 15:26:22 by ggirault         ###   ########.fr       */
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

void	load_texture(t_game **game)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	(*game)->floor_text->img = mlx_xpm_file_to_image((*game)->window->mlx,
			"texture/floor.xpm", &width, &height);
	resize_texture(&(*game)->floor_text, width, *game);
	(*game)->wall_text->img = mlx_xpm_file_to_image((*game)->window->mlx,
			"texture/wall_top_floor.xpm", &width, &height);
	resize_texture(&(*game)->wall_text, width, *game);
	(*game)->player_text->img = mlx_xpm_file_to_image((*game)->window->mlx,
			"texture/player.xpm", &width, &height);
	resize_texture(&(*game)->player_text, width, *game);
	(*game)->sakura->img = mlx_xpm_file_to_image((*game)->window->mlx,
			"texture/sakura_tree.xpm", &width, &height);
	resize_texture(&(*game)->sakura, width, *game);
	(*game)->pine->img = mlx_xpm_file_to_image((*game)->window->mlx,
			"texture/pine_tree.xpm", &width, &height);
	resize_texture(&(*game)->pine, width, *game);
	if (!(*game)->floor_text || !(*game)->wall_text)
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
	if (i == 0 || i == (tab_len(game->map) - 1))
		mlx_put_image_to_window(game->window->mlx, game->window->win,
			game->wall_text->img, x, y);
	else
	{
		if (((x * 123 + y * 456 + 9876) / 17) % 2 == 0)
			mlx_put_image_to_window(game->window->mlx, game->window->win,
				game->sakura->img, x, y);
		else
			mlx_put_image_to_window(game->window->mlx, game->window->win,
				game->pine->img, x, y);
	}
}

int	rendering(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	int	i;
	int	j;
	int	x;
	int	y;
	
	i = 0;
	mlx_clear_window(game->window->mlx, game->window->win);
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			x = j * game->tile_size;
			y = i * game->tile_size;
			if (game->map[i][j] == '1')
				render_wall(game, i, j);
			else if (game->map[i][j] == '0' || game->map[i][j] == 'F')
				mlx_put_image_to_window(game->window->mlx, game->window->win,
					game->floor_text->img, x, y);
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->window->mlx, game->window->win,
					game->player_text->img, x, y);
			j++;
		}
		i++;
	}
	return (0);
}
