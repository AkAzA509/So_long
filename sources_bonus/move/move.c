/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:17:50 by ggirault          #+#    #+#             */
/*   Updated: 2025/02/12 18:08:37 by ggirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long_bonus.h"

bool	check_collectible(t_game *game)
{
	int	i;
	int	j;
	int	c_count;

	i = 0;
	j = 0;
	c_count = 0;
	while (game->map[i] != NULL)
	{
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'C')
				c_count += 1;
			j++;
		}
		j = 0;
		i++;
	}
	if (c_count != 0)
		return (false);
	return (true);
}

void	move_up(t_game **game, char *move_count)
{
	if ((*game)->map[(*game)->coor->x - 1][(*game)->coor->y] == '1')
		return ;
	else if ((*game)->map[(*game)->coor->x - 1][(*game)->coor->y] == 'E')
	{
		if (check_collectible(*game) == true)
		{
			write (1, "Congrats !! You have finish this game !", 40);
			close_window(*game);
			exit(0);
		}
		else
			return ;
	}
	else
	{
		(*game)->map[(*game)->coor->x][(*game)->coor->y] = '0';
		(*game)->map[(*game)->coor->x - 1][(*game)->coor->y] = 'P';
		(*game)->coor->x -= 1;
	}
	(*game)->count_move += 1;
	move_count = ft_itoa((*game)->count_move);
	write(1, move_count, ft_strlen((const char *)move_count));
	write(1, "\n", 1);
	free(move_count);
}

void	move_down(t_game **game, char *move_count)
{
	if ((*game)->map[(*game)->coor->x + 1][(*game)->coor->y] == '1')
		return ;
	else if ((*game)->map[(*game)->coor->x + 1][(*game)->coor->y] == 'E')
	{
		if (check_collectible(*game) == true)
		{
			write (1, "Congrats !! You have finish this game !", 40);
			close_window(*game);
			exit(0);
		}
		else
			return ;
	}
	else
	{
		(*game)->map[(*game)->coor->x][(*game)->coor->y] = '0';
		(*game)->map[(*game)->coor->x + 1][(*game)->coor->y] = 'P';
		(*game)->coor->x += 1;
	}
	(*game)->count_move += 1;
	move_count = ft_itoa((*game)->count_move);
	write(1, move_count, ft_strlen((const char *)move_count));
	write(1, "\n", 1);
	free(move_count);
}

void	move_left(t_game **game, char *move_count)
{
	if ((*game)->map[(*game)->coor->x][(*game)->coor->y - 1] == '1')
		return ;
	else if ((*game)->map[(*game)->coor->x][(*game)->coor->y - 1] == 'E')
	{
		if (check_collectible(*game) == true)
		{
			write (1, "Congrats !! You have finish this game !", 40);
			close_window(*game);
			exit(0);
		}
		else
			return ;
	}
	else
	{
		(*game)->map[(*game)->coor->x][(*game)->coor->y] = '0';
		(*game)->map[(*game)->coor->x][(*game)->coor->y - 1] = 'P';
		(*game)->coor->y -= 1;
	}
	(*game)->count_move += 1;
	move_count = ft_itoa((*game)->count_move);
	write(1, move_count, ft_strlen((const char *)move_count));
	write(1, "\n", 1);
	free(move_count);
}

void	move_right(t_game **game, char *move_count)
{
	if ((*game)->map[(*game)->coor->x][(*game)->coor->y + 1] == '1')
		return ;
	else if ((*game)->map[(*game)->coor->x][(*game)->coor->y + 1] == 'E')
	{
		if (check_collectible(*game) == true)
		{
			write (1, "Congrats !! You have finish this game !", 40);
			close_window(*game);
			exit(0);
		}
		else
			return ;
	}
	else
	{
		(*game)->map[(*game)->coor->x][(*game)->coor->y] = '0';
		(*game)->map[(*game)->coor->x][(*game)->coor->y + 1] = 'P';
		(*game)->coor->y += 1;
	}
	(*game)->count_move += 1;
	move_count = ft_itoa((*game)->count_move);
	write(1, move_count, ft_strlen((const char *)move_count));
	write(1, "\n", 1);
	free(move_count);
}
