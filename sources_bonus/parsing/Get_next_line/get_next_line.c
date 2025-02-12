/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:44:34 by ggirault          #+#    #+#             */
/*   Updated: 2025/01/31 10:01:34 by ggirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/get_next_line.h"

// fais les verification et appele toute les fonctions
char	*get_next_line(int fd)
{
	static t_list	*reserve = NULL;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_and_stock(&reserve, fd);
	if (!reserve)
		return (NULL);
	find_line(reserve, &line);
	clean_reserve(&reserve);
	if (line[0] == '\0')
	{
		free_reserve(reserve);
		reserve = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

// lis et verifie a chaque iteration la presence d'un \n avec ifnewline 
//puis envois le buffer pour le mettre en reserve
void	read_and_stock(t_list **reserve, int fd)
{
	int		readed;
	char	*buf;

	readed = 1;
	while (!if_newline(*reserve) && readed != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		readed = (int)read(fd, buf, BUFFER_SIZE);
		if (readed == -1 || (*reserve == NULL && readed == 0))
		{
			free(buf);
			return ;
		}
		buf[readed] = '\0';
		add_to_stock(reserve, buf, readed);
		free(buf);
	}
}

// alloue un nouveau noeud, et transfert le buffer dans le noeud,
// puis ajoute le noeud a la fin de la liste
void	add_to_stock(t_list **reserve, char *buf, int readed)
{
	t_list	*new;
	t_list	*last;
	int		i;

	i = 0;
	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->next = NULL;
	new->content = malloc(sizeof(char) * (readed + 1));
	if (!new->content)
		return ;
	while (buf[i] && i < readed)
	{
		new->content[i] = buf[i];
		i++;
	}
	new->content[i] = '\0';
	if (*reserve == NULL)
	{
		*reserve = new;
		return ;
	}
	last = ft_lstlast(*reserve);
	last->next = new;
}

// parcours mes noeuds jusqu'a un \n puis stock la ligne
void	find_line(t_list *reserve, char **line)
{
	int	i;
	int	j;

	j = 0;
	if (!reserve)
		return ;
	make_line(reserve, line);
	if (!line)
		return ;
	while (reserve)
	{
		i = 0;
		while (reserve->content[i])
		{
			if (reserve->content[i] == '\n')
			{
				(*line)[j++] = reserve->content[i];
				break ;
			}
			(*line)[j++] = reserve->content[i++];
		}
		reserve = reserve->next;
	}
	(*line)[j] = '\0';
}

// parcours mes noeuds jusqu'a un \n puis ajoute la suite dans un nouveau noeuds
// et supprime la ligne precedente du noeud et free les noeud non utiliser
void	clean_reserve(t_list **reserve)
{
	t_list	*last;
	t_list	*clean;
	int		i;
	int		j;

	i = 0;
	j = 0;
	clean = malloc(sizeof(t_list));
	if (reserve == NULL || clean == NULL)
		return ;
	clean->next = NULL;
	last = ft_lstlast(*reserve);
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] && last->content[i] == '\n')
		i++;
	clean->content = malloc(sizeof(char) * (ft_strlen(last->content) - i + 1));
	if (clean == NULL)
		return ;
	while (last->content[i])
		clean->content[j++] = last->content[i++];
	clean->content[j] = '\0';
	free_reserve(*reserve);
	*reserve = clean;
}
