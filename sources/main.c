/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:59:24 by ggirault          #+#    #+#             */
/*   Updated: 2025/02/04 10:31:24 by ggirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

/* void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
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
} */

int	key_hook(int keycode, t_game *game)
{
	printf("%d\n", keycode);
	if (keycode == 65307)
		close_window(game);
	return (0);
}

/* unsigned int	color_generator(void)
{
	srand(time(NULL));

    unsigned char red = rand() % 256;
    unsigned char green = rand() % 256;
    unsigned char blue = rand() % 256;

    unsigned int color = (red << 16) | (green << 8) | blue;
	return (color);
} */

void	ft_free(t_game **game)
{
	if (!game)
		return ;
	free((*game)->window);
	free((*game)->data);
	//free((*game)->coor);
	free((*game)->est_wall_text);
	free((*game)->west_wall_text);
	free((*game)->wall_text);
	free((*game)->floor_text);
	free((*game)->player_text);
	free((*game)->objs_text);
	free((*game)->exit_text);
	free((*game));
}

int	main(int ac, char *av[])
{
	t_game	*so_long;
	
	so_long = NULL;
	open_map(av, ac, &so_long);
	init_window(so_long);
	rendering(so_long);
	
	mlx_hook(so_long->window->win, DestroyNotify, StructureNotifyMask, close_window, so_long);
	mlx_loop(so_long->window->mlx);
	return (0);
}
