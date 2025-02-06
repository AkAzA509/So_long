/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:59:24 by ggirault          #+#    #+#             */
/*   Updated: 2025/02/06 18:45:01 by ggirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"



int	key_hook(int keycode, t_game *game)
{
	char	*move_count;

	move_count = ft_itoa(game->count_move += 1);
	write (1, move_count, ft_strlen((const char *)move_count));
	write(1, "\n", 1);
	free(move_count);
	if (keycode == 65307)
		close_window(game);
	if (keycode == 119 || keycode == 65362)
		move_up(&game);
	if (keycode == 115 || keycode == 65364)
		move_down(&game);
	if (keycode == 97 || keycode == 65361)
		move_left(&game);
	if (keycode == 100 || keycode == 65363)
		move_right(&game);
	return (0);
}

void	ft_free(t_game **game)
{
	if (!game)
		return ;
	free((*game)->window);
	free((*game)->data);
	// free((*game)->coor);
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
	load_texture(&so_long);

	mlx_loop_hook(so_long->window->mlx, rendering, so_long);
	mlx_hook(so_long->window->win, 2, 1L<<0, key_hook, so_long);
	mlx_hook(so_long->window->win, DestroyNotify, StructureNotifyMask, close_window, so_long);

	mlx_loop(so_long->window->mlx);
	return (0);
}
