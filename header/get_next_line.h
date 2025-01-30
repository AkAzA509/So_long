/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:45:44 by ggirault          #+#    #+#             */
/*   Updated: 2025/01/30 19:55:38 by ggirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 22
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
void				read_and_stock(t_list **reserve, int fd);
void				add_to_stock(t_list **reserve, char *buf, int readed);
void				find_line(t_list *reserve, char **line);
void				clean_reserve(t_list **reserve);
int					if_newline(t_list *reserve);
t_list				*ft_lstlast(t_list *reserve);
void				make_line(t_list *reserve, char **line);
void				free_reserve(t_list *reserve);
int					ft_strlen(const char *s);

#endif
