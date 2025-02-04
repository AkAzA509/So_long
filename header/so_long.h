/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:50:46 by ggirault          #+#    #+#             */
/*   Updated: 2025/02/04 14:24:13 by ggirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

////////////////////////////////////
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
////////////////////////////////////

# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "get_next_line.h"
# include <stdbool.h>

/* typedef struct s_texture
{
	void	*est_wall_text;
	void	*west_wall_text;
	void	*wall_text;
	void	*floor_text;
	void	*player_text;
	void	*objs_text;
	void	*exit_text;
}			t_texture; */

typedef struct t_coor
{
	int		p_x_pos;
	int		p_y_pos;
	int		x;
	int		y;
}			t_coor;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_window
{
	void	*mlx;
	void	*win;
}			t_window;

typedef struct s_game
{
	char				**map;
	int					width;
	int					height;
	int					tile_size;
	struct s_data		*data;
	struct s_coor		*coor;
	struct s_window		*window;
	struct s_data		*est_wall_text;
	struct s_data		*west_wall_text;
	struct s_data		*wall_text;
	struct s_data		*floor_text;
	struct s_data		*player_text;
	struct s_data		*objs_text;
	struct s_data		*exit_text;
	struct s_data		*sakura;
	struct s_data		*pine;
}						t_game;

//---------------[ Parsing ]---------------------//

void		open_map(char *av[], int ac, t_game **game);
int			pre_parsing(int fd);
char		*get_next_line(int fd);
char		**remove_endline(char *map_tab[]);
int			tab_len(char *tab[]);
bool		configuration_checker(char *map[]);
void		find_coordonate(t_coor **coor, char *map[]);

//---------------[ Gestions fenetre ]------------//

void		init_window(t_game *game);
int			close_window(t_game *game);
void		struct_alloc(t_game **game);
void		rendering(t_game *game);

//------------------[ Cleanup ]------------------//

void		free_split(char **tab);
void		ft_free(t_game **game);

#endif