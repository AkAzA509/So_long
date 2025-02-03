/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:49:39 by ggirault          #+#    #+#             */
/*   Updated: 2025/02/03 19:05:45 by ggirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long.h"

void	load_texture(t_game **game)
{
	int	width;
	int	height;
	
	width = 0;
	height = 0;
	(*game)->texture->floor_text = mlx_xpm_file_to_image((*game)->window->mlx, "texture/floor.xpm", &width, &height);
	(*game)->texture->est_wall_text = mlx_xpm_file_to_image((*game)->window->mlx, "texture/est_wall.xpm", &width, &height);
	(*game)->texture->west_wall_text = mlx_xpm_file_to_image((*game)->window->mlx, "texture/west_wall.xpm", &width, &height);
	(*game)->texture->wall_text = mlx_xpm_file_to_image((*game)->window->mlx, "texture/wall_top_floor.xpm", &width, &height);
	if (!(*game)->texture->floor_text || !(*game)->texture->est_wall_text || !(*game)->texture->west_wall_text || !(*game)->texture->wall_text)
	{
		perror("Error ");
		exit(1);
	}
}

void rendering(t_game *game)
{
    int i = 0;
    int j = 0;

    load_texture(&game);  // Charge les textures

    while (game->map[i] != NULL)  // Parcours des lignes
    {
        j = 0;
        while (game->map[i][j] != '\0')  // Parcours des colonnes
        {
            int x = j * game->tile_size;  // Position X en pixels
            int y = i * game->tile_size;  // Position Y en pixels
			printf("current pos = %c\n", game->map[i][j]);
            if (game->map[i][j] == '1' || game->map[i][j] == '1')
                mlx_put_image_to_window(game->window->mlx, game->window->win, game->texture->wall_text, x, y);
            else if (game->map[i][j] == '0' || game->map[i][j] == 'P' || game->map[i][j] == 'F')
                mlx_put_image_to_window(game->window->mlx, game->window->win, game->texture->floor_text, x, y);            
            j++;  // Passe à la colonne suivante
        }
        i++;  // Passe à la ligne suivante
    }
}

