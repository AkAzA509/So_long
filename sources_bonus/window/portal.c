/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:59:47 by ggirault          #+#    #+#             */
/*   Updated: 2025/02/13 12:00:50 by ggirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long_bonus.h"

long	time_anim(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

static int	rewrite_portal(t_game *game, int width, int *new_data, int *data)
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

static void	resize_portal(t_anim **texture, int width, t_game *game, int i)
{
	void	*new;
	int		*data;
	int		*new_data;

	new = mlx_new_image(game->window->mlx, game->tile_size, game->tile_size);
	data = (int *)mlx_get_data_addr((*texture)->frame[i],
			&(*texture)->bits_per_pixel, &(*texture)->line_length,
			&(*texture)->endian);
	new_data = (int *)mlx_get_data_addr(new, &(*texture)->bits_per_pixel,
			&(*texture)->line_length, &(*texture)->endian);
	rewrite_portal(game, width, new_data, data);
	mlx_destroy_image(game->window->mlx, (*texture)->frame[i]);
	(*texture)->frame[i] = new;
	(*texture)->addr[i] = (char *)new_data;
	if (i == 6)
		(*texture)->addr[i + 1] = NULL;
}

static void	render_portail_suite(t_game **game)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	(*game)->portal->frame[4] = mlx_xpm_file_to_image((*game)->window->mlx,
			"texture/portal5.xpm", &width, &height);
	resize_portal(&(*game)->portal, width, *game, 4);
	(*game)->portal->frame[5] = mlx_xpm_file_to_image((*game)->window->mlx,
			"texture/portal6.xpm", &width, &height);
	resize_portal(&(*game)->portal, width, *game, 5);
	(*game)->portal->frame[6] = NULL;
	if (!(*game)->portal->frame[4] || !(*game)->portal->frame[5])
	{
		ft_free(game, 1);
		exit(1);
	}
	(*game)->portal->current = 0;
	(*game)->portal->total_frames = 6;
	(*game)->portal->timer = 0;
	(*game)->portal->speed = 100;
	(*game)->portal->update = 0;
}

void	render_portal(t_game **game)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	(*game)->portal->frame[0] = mlx_xpm_file_to_image((*game)->window->mlx,
			"texture/portal1.xpm", &width, &height);
	resize_portal(&(*game)->portal, width, *game, 0);
	(*game)->portal->frame[1] = mlx_xpm_file_to_image((*game)->window->mlx,
			"texture/portal2.xpm", &width, &height);
	resize_portal(&(*game)->portal, width, *game, 1);
	(*game)->portal->frame[2] = mlx_xpm_file_to_image((*game)->window->mlx,
			"texture/portal3.xpm", &width, &height);
	resize_portal(&(*game)->portal, width, *game, 2);
	(*game)->portal->frame[3] = mlx_xpm_file_to_image((*game)->window->mlx,
			"texture/portal4.xpm", &width, &height);
	resize_portal(&(*game)->portal, width, *game, 3);
	if (!(*game)->portal->frame[0] || !(*game)->portal->frame[1]
		|| !(*game)->portal->frame[2] || !(*game)->portal->frame[3])
	{
		ft_free(game, 1);
		exit(1);
	}
	render_portail_suite(game);
}
