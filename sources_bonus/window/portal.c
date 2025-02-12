/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:59:47 by ggirault          #+#    #+#             */
/*   Updated: 2025/02/12 18:25:43 by ggirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long_bonus.h"

static void	render_portail_suite(t_game **game)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	(*game)->portal->frame[4] = mlx_xpm_file_to_image((*game)->window->mlx,
			"/textures/portal5.xpm", &width, &height);
	resize_texture((void *)(*game)->portal, width, *game);
	(*game)->portal->frame[5] = mlx_xpm_file_to_image((*game)->window->mlx,
			"/textures/portal6.xpm", &width, &height);
	resize_texture((void *)(*game)->portal, width, *game);
	(*game)->portal->frame[6] = NULL;
	if (!(*game)->portal->frame[4] || !(*game)->portal->frame[5])
	{
		ft_free(game, 1);
		exit(1);
	}
	(*game)->portal->current = 0;
	(*game)->portal->total_frames = 6;
	(*game)->portal->timer = 0;
	(*game)->portal->speed = 10;
}

void	render_portal(t_game **game)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	(*game)->portal->frame[0] = mlx_xpm_file_to_image((*game)->window->mlx,
			"/textures/portal1.xpm", &width, &height);
	resize_texture((void *)(*game)->portal, width, *game);
	(*game)->portal->frame[1] = mlx_xpm_file_to_image((*game)->window->mlx,
			"/textures/portal2.xpm", &width, &height);
	resize_texture((void *)(*game)->portal, width, *game);
	(*game)->portal->frame[2] = mlx_xpm_file_to_image((*game)->window->mlx,
			"/textures/portal3.xpm", &width, &height);
	resize_texture((void *)(*game)->portal, width, *game);
	(*game)->portal->frame[3] = mlx_xpm_file_to_image((*game)->window->mlx,
			"/textures/portal4.xpm", &width, &height);
	resize_texture((void *)(*game)->portal, width, *game);
	if (!(*game)->portal->frame[0] || !(*game)->portal->frame[1]
		|| !(*game)->portal->frame[2] || !(*game)->portal->frame[3])
	{
		ft_free(game, 1);
		exit(1);
	}
	render_portail_suite(game);
}
