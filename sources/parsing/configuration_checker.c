/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configuration_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:27:25 by ggirault          #+#    #+#             */
/*   Updated: 2025/01/31 13:30:57 by ggirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/so_long.h"

/* static bool	check_pec(char *map[])
{

} */

static bool	check_border(char *map[])
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = tab_len(map);
	while (1)
	{
		if (map[0][i] != 1 || map[j][i] != 1)
			return (false);
		if(map[0][i] != '\0' || map[j][i] != '\0')
			i++;
		else
			break;
	}
	i = 0;
	k = 1;
	j = ft_strlen(map[1]);
	while (map[k] != NULL)
	{
		if (map[k][i] != 1 || map[k][j] != 1)
			return(false);
		k++;
	}
	return(true);
}

bool	configuration_checker(char *map[])
{
	if (!check_border(map) /* || !check_pec(map) */)
		return (false);
	return (true);
}