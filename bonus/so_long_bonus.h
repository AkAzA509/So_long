/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:34:38 by ggirault          #+#    #+#             */
/*   Updated: 2025/02/08 11:09:55 by ggirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

typedef struct s_anim
{
	void	*img;
	void	**frame;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_anim;

void	render_portal(t_game **game);

#endif