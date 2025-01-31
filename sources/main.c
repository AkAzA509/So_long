/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:59:24 by ggirault          #+#    #+#             */
/*   Updated: 2025/01/31 11:22:38 by ggirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_carrer(t_data *data, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(data, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_rectangle(t_data *data, int x, int y, int sizex, int sizey, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < sizey)
	{
		j= 0;
		while(j < sizex)
		{
			my_mlx_pixel_put(data, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	printf("%d\n", keycode);
	if (keycode == 65307)
		close_window(data);
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

int	mouse_hook(int mouse, int x, int y, t_data *img)
{
	if (mouse == 1)
	{
		draw_carrer(img, x, y, 100, color_generator());
		mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	}
	return (0);
}

int	main(int ac, char *av[])
{
	//t_data	img;

	open_map(av, ac);
	/* if (av || ac)
		printf("test");
	init_window(&img);

	mlx_key_hook(img.win, key_hook, &img);
	mlx_mouse_hook(img.win, mouse_hook, &img);

	mlx_hook(img.win, DestroyNotify, StructureNotifyMask, close_window, &img);
	
	mlx_loop(img.mlx); */
	return (0);
}
