/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:49:39 by ggirault          #+#    #+#             */
/*   Updated: 2025/02/12 17:47:16 by ggirault         ###   ########.fr       */
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

void	resize_texture(t_data **texture, int width, t_game *game)
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
	(*texture)->addr = (char *)new_data;
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

static void	render_suite(t_game *game, int i, int j)
{
	int	x;
	int	y;

	x = j * game->tile_size;
	y = i * game->tile_size;
	if (game->map[i][j] == '0' || game->map[i][j] == 'F')
		mlx_put_image_to_window(game->window->mlx, game->window->win,
			game->floor_text->img, x, y);
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->window->mlx, game->window->win,
			game->player_text->img, x, y);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->window->mlx, game->window->win,
			game->exit_text->img, x, y);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->window->mlx, game->window->win,
			game->objs_text->img, x, y);
}

int	rendering(void *param)
{
	t_game	*game;
	int		i;
	int		j;

	game = (t_game *)param;
	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == '1')
				render_wall(game, i, j);
			else
				render_suite(game, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
