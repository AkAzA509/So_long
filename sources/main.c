/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:59:24 by ggirault          #+#    #+#             */
/*   Updated: 2025/02/12 14:36:47 by ggirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	key_hook(int keycode, t_game *game)
{
	char	*move_count;

	move_count = NULL;
	if (keycode == 65307)
		close_window(game);
	if (keycode == 119 || keycode == 65362)
		move_up(&game, move_count);
	if (keycode == 115 || keycode == 65364)
		move_down(&game, move_count);
	if (keycode == 97 || keycode == 65361)
		move_left(&game, move_count);
	if (keycode == 100 || keycode == 65363)
		move_right(&game, move_count);
	return (0);
}

static void	ft_free_suite(t_game **game, int condition)
{
	if ((*game)->data)
		free((*game)->data);
	if (condition == 1)
	{
		if ((*game)->window)
		{
			if ((*game)->window->mlx)
				free((*game)->window->mlx);
		}
	}
	free((*game)->window);
	free(*game);
	*game = NULL;
}

void	ft_free(t_game **game, int condition)
{
	if (!game || !*game)
		return ;
	if (condition == 1)
		free_split((*game)->map);
	free((*game)->coor);
	if ((*game)->wall_text)
		free((*game)->wall_text);
	if ((*game)->floor_text)
		free((*game)->floor_text);
	if ((*game)->player_text)
		free((*game)->player_text);
	if ((*game)->objs_text)
		free((*game)->objs_text);
	if ((*game)->exit_text)
		free((*game)->exit_text);
	if ((*game)->sakura)
		free((*game)->sakura);
	if ((*game)->pine)
		free((*game)->pine);
	ft_free_suite(game, condition);
}

int	main(int ac, char *av[])
{
	t_game	*so_long;

	so_long = NULL;
	open_map(av, ac, &so_long);
	init_window(so_long);
	load_texture(&so_long);
	mlx_loop_hook(so_long->window->mlx, rendering, so_long);
	mlx_hook(so_long->window->win, 2, 1L << 0, key_hook, so_long);
	mlx_hook(so_long->window->win, DestroyNotify, StructureNotifyMask,
		close_window, so_long);
	mlx_loop(so_long->window->mlx);
	return (0);
}
