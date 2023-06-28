/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:33:06 by atucci            #+#    #+#             */
/*   Updated: 2023/06/28 10:04:39 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

static	void	open_windows()
{
	void	*windows_pointer;
	void	*pointer_needed;
	
	pointer_needed = mlx_init();
	
	windows_pointer = mlx_new_window(pointer_needed, 500, 500, "this is a try");

	mlx_loop(pointer_needed);
}

int	main(int ac, char *av[])
{
	if (ac != 2 && av)
	{
		ft_printf("exit\n");
		exit(0);
	}
	else
		open_windows();
}