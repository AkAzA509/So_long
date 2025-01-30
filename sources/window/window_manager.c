/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:48:22 by ggirault          #+#    #+#             */
/*   Updated: 2025/01/30 18:06:41 by ggirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long.h"

void	init_window(t_data *img)
{
	img->mlx = mlx_init();
	if (!img->mlx)
		close_window(img);
	img->win = mlx_new_window(img->mlx, 1920, 1080, "So_long");
	img->img = mlx_new_image(img->mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}