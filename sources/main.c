/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:59:24 by ggirault          #+#    #+#             */
/*   Updated: 2025/01/28 13:39:32 by ggirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	main(int ac, char *av[])
{
	void	*ptr;
	void	*ptr_init;

	if(ac > 2)
		printf("oui");
	if(!av)
		printf("non");
	ptr_init = mlx_init();	
	ptr = mlx_new_window(ptr_init, 10, 10, "So_long");
	mlx_clear_window(ptr_init, ptr);
	return (0);
}