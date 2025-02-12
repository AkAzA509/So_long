/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:34:38 by ggirault          #+#    #+#             */
/*   Updated: 2025/02/12 18:19:33 by ggirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../header/get_next_line.h"
# include <stdbool.h>

typedef struct s_anim
{
	void	**frame;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		total_frames;
	int		current;
	int		speed;
	int		timer;
}			t_anim;

typedef struct s_map_count
{
	int		c_count;
	int		p_count;
	int		e_count;
}			t_map_count;

typedef struct s_coor
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
	int					count_move;
	struct s_data		*data;
	struct s_coor		*coor;
	struct s_window		*window;;
	struct s_data		*wall_text;
	struct s_data		*floor_text;
	struct s_data		*player_text;
	struct s_data		*objs_text;
	struct s_data		*exit_text;
	struct s_data		*sakura;
	struct s_data		*pine;
	struct s_anim		*portal;
}						t_game;

//---------------[ Parsing ]---------------------//

void		open_map(char *av[], int ac, t_game **game);
int			pre_parsing(int fd);
char		*get_next_line(int fd);
char		**remove_endline(char *map_tab[]);
int			tab_len(char *tab[]);
bool		configuration_checker(char *map[], t_game **game);
void		find_coordonate(t_game **game, char *map[]);

//---------------[ Gestions fenetre ]------------//

void		init_window(t_game *game);
int			close_window(t_game *game);
void		struct_alloc(t_game **game);
int			rendering(void *param);
void		load_texture(t_game **game);
char		*ft_itoa(int n);
void		resize_texture(void **text, int width, t_game *game);
void		render_portal(t_game **game);

//--------------------[ Move ]--------------------//

void		move_up(t_game **game, char *move_count);
void		move_down(t_game **game, char *move_count);
void		move_left(t_game **game, char *move_count);
void		move_right(t_game **game, char *move_count);

//------------------[ Cleanup ]------------------//

void		free_split(char **tab);
void		ft_free(t_game **game, int condition);

#endif