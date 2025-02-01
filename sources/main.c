/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:59:24 by ggirault          #+#    #+#             */
/*   Updated: 2025/02/01 14:57:38 by ggirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->data->addr + (y * game->data->line_length + x * (game->data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_carrer(t_game *game, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(game, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_rectangle(t_game *game, int x, int y, int sizex, int sizey, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < sizey)
	{
		j= 0;
		while(j < sizex)
		{
			my_mlx_pixel_put(game, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

int	key_hook(int keycode, t_game *game)
{
	printf("%d\n", keycode);
	if (keycode == 65307)
		close_window(game);
	return (0);
}

unsigned int	color_generator(void)
{
	srand(time(NULL));

    unsigned char red = rand() % 256;
    unsigned char green = rand() % 256;
    unsigned char blue = rand() % 256;

    unsigned int color = (red << 16) | (green << 8) | blue;
	return (color);
}

int	mouse_hook(int mouse, int x, int y, t_game *game)
{
	if (mouse == 1)
	{
		draw_carrer(game, x, y, 90, color_generator());
		mlx_put_image_to_window(game->window->mlx, game->window->win, game->data->img, 0, 0);
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_game	*so_long;

	open_map(av, ac);
	
	so_long = malloc(sizeof(t_game));
	so_long->window = malloc(sizeof(t_window));
	so_long->data = malloc(sizeof(t_data));
	init_window(&so_long->data);
	// char *path = "./texture/cave_-_resources_.xpm";
	// int	width = 192;
	// int	height = 160;
	// void	*imgs;

	mlx_mouse_hook(so_long->window->win, mouse_hook, so_long->data->img);
	// imgs = mlx_xpm_file_to_image(img.mlx, path, &width, &height);
	// mlx_put_image_to_window(img.mlx, img.win, imgs, 100, 100);
	mlx_key_hook(so_long->window->win, key_hook, so_long->data->img);
	mlx_hook(so_long->window->win, DestroyNotify, StructureNotifyMask, close_window, so_long->data->img);

	mlx_loop(so_long->window->mlx);
	return (0);
}
