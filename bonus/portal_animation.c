/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:32:27 by ggirault          #+#    #+#             */
/*   Updated: 2025/02/08 11:18:05 by ggirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"
#include "so_long_bonus.h"

static void	render_portail_suite(t_game **game)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	(*game)->portal_anim->frame[3] = mlx_xpm_file_to_image((*game)->window->mlx,
			"/textures/portal4.xpm", &width, &height);
	resize_texture((*game)->portal_anim->frame[3], width, *game);
	(*game)->portal_anim->frame[4] = mlx_xpm_file_to_image((*game)->window->mlx,
			"/textures/portal5.xpm", &width, &height);
	resize_texture(&(*game)->portal_anim->frame[4], width, *game);
	(*game)->portal_anim->frame[5] = mlx_xpm_file_to_image((*game)->window->mlx,
			"/textures/portal6.xpm", &width, &height);
	resize_texture(&(*game)->portal_anim->frame[5], width, *game);
	if (!(*game)->portal_anim->frame[3] || !(*game)->portal_anim->frame[4]
		|| !(*game)->portal_anim->frame[5])
	{
		ft_free(game);
		exit(1);
	}
}

void	render_portal(t_game **game)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	(*game)->portal_anim->frame[0] = mlx_xpm_file_to_image((*game)->window->mlx,
			"/textures/portal1.xpm", &width, &height);
	resize_texture(&(*game)->portal_anim->frame[0], width, *game);
	(*game)->portal_anim->frame[1] = mlx_xpm_file_to_image((*game)->window->mlx,
			"/textures/portal2.xpm", &width, &height);
	resize_texture(&(*game)->portal_anim->frame[1], width, *game);
	(*game)->portal_anim->frame[2] = mlx_xpm_file_to_image((*game)->window->mlx,
			"/textures/portal3.xpm", &width, &height);
	resize_texture(&(*game)->portal_anim->frame[2], width, *game);
	if (!(*game)->portal_anim->frame[0] || !(*game)->portal_anim->frame[1]
		|| !(*game)->portal_anim->frame[2])
	{
		ft_free(game);
		exit(1);
	}
}
