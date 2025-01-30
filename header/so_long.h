/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:50:46 by ggirault          #+#    #+#             */
/*   Updated: 2025/01/30 19:00:01 by ggirault         ###   ########.fr       */
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

typedef struct s_data
{
	void	*img;
	char	*addr;
	void	*mlx;
	void	*win;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

//---------------[ Parsing ]---------------------//

void		open_map(char *av[], int ac);
int			pre_parsing(int fd);


//---------------[ Gestions fenetre ]------------//

void		init_window(t_data *img);

//------------------[ Cleanup ]------------------//

int			close_window(t_data *data);
void		free_split(char **tab);

#endif