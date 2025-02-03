/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:48:22 by ggirault          #+#    #+#             */
/*   Updated: 2025/02/03 10:12:15 by ggirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long.h"

int close_window(t_game *game)
{
	mlx_destroy_window(game->window->mlx, game->window->win);
	mlx_destroy_image(game->window->mlx, game->data->img);
	mlx_destroy_display(game->window->mlx);
	free(game->window->mlx);
	exit(0);
}

void init_window(t_game *game)
{
	int tile_x;
	int tile_y;

	tile_x = 1920 / game->width;
	tile_y = 1080 / game->height;
	if (tile_x < tile_y)
		game->tile_size = tile_x;
	else
		game->tile_size = tile_y;
	game->window->mlx = mlx_init();
	if (!game->window->mlx)
		close_window(game);
	game->window->win = mlx_new_window(game->window->mlx, game->width * game->tile_size, game->height * game->tile_size, "So_long");
	game->data->img = mlx_new_image(game->window->mlx, 1920, 1080);
	game->data->addr = mlx_get_data_addr(game->data->img, &game->data->bits_per_pixel,
										 &game->data->line_length, &game->data->endian);
}
