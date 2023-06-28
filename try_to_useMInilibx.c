/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_to_useMInilibx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 09:40:49 by atucci            #+#    #+#             */
/*   Updated: 2023/06/28 09:51:34 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>


int	main()
{
	void *windows_pointer;
	void *pointer_needed;
	// we will need this pointer to start working with mlx
	pointer_needed = mlx_init();
	// now I will open a window
	windows_pointer = mlx_new_window(pointer_needed, 500, 500, "questa e una prova"); // this function takes 4 paramaters
	mlx_loop(pointer_needed);	

}
