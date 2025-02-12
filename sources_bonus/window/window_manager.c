/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:48:22 by ggirault          #+#    #+#             */
/*   Updated: 2025/02/12 14:45:04 by ggirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long.h"

static void	load_texture_suite(t_game **game)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	(*game)->pine->img = mlx_xpm_file_to_image((*game)->window->mlx,
			"texture/pine_tree.xpm", &width, &height);
	resize_texture(&(*game)->pine, width, *game);
	(*game)->objs_text->img = mlx_xpm_file_to_image((*game)->window->mlx,
			"texture/coll.xpm", &width, &height);
	resize_texture(&(*game)->objs_text, width, (*game));
	(*game)->exit_text->img = mlx_xpm_file_to_image((*game)->window->mlx,
			"texture/portal1.xpm", &width, &height);
	resize_texture(&(*game)->exit_text, width, *game);
	if (!(*game)->pine || !(*game)->objs_text || !(*game)->exit_text)
	{
		perror("Error ");
		exit(1);
	}
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
	if (!(*game)->floor_text || !(*game)->wall_text || !(*game)->player_text
		|| !(*game)->sakura)
	{
		perror("Error ");
		exit(1);
	}
	load_texture_suite(game);
}

int	close_window(t_game *game)
{
	if (game->wall_text->img)
		mlx_destroy_image(game->window->mlx, game->wall_text->img);
	if (game->floor_text->img)
		mlx_destroy_image(game->window->mlx, game->floor_text->img);
	if (game->player_text->img)
		mlx_destroy_image(game->window->mlx, game->player_text->img);
	if (game->objs_text->img)
		mlx_destroy_image(game->window->mlx, game->objs_text->img);
	if (game->exit_text->img)
		mlx_destroy_image(game->window->mlx, game->exit_text->img);
	if (game->sakura->img)
		mlx_destroy_image(game->window->mlx, game->sakura->img);
	if (game->pine->img)
		mlx_destroy_image(game->window->mlx, game->pine->img);
	mlx_destroy_window(game->window->mlx, game->window->win);
	mlx_destroy_image(game->window->mlx, game->data->img);
	mlx_destroy_display(game->window->mlx);
	ft_free(&game, 1);
	exit(0);
}

void	init_window(t_game *game)
{
	int	tile_x;
	int	tile_y;

	tile_x = 1920 / game->width;
	tile_y = 1080 / game->height;
	if (tile_x < tile_y)
		game->tile_size = tile_x;
	else
		game->tile_size = tile_y;
	game->count_move = 0;
	game->window->mlx = mlx_init();
	if (!game->window->mlx)
		close_window(game);
	game->window->win = mlx_new_window(game->window->mlx, game->width
			* game->tile_size, game->height * game->tile_size, "So_long");
	game->data->img = mlx_new_image(game->window->mlx, 1920, 1080);
	game->data->addr = mlx_get_data_addr(game->data->img,
			&game->data->bits_per_pixel, &game->data->line_length,
			&game->data->endian);
}
