/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_manag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:19:48 by atucci            #+#    #+#             */
/*   Updated: 2023/10/03 20:26:19 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	new_image(t_date *inf)
{
	ft_printf("%sgetting address in img_data%s\n", BG_YELLOW, RESET);
	inf->img_pointer = mlx_new_image(inf->mlx, inf->width,
			inf->height);
	inf->img_string = mlx_get_data_addr(inf->img_pointer, &(inf->bits),
			&(inf->lsize), &(inf->endian));
}
/* This function perfom a cleana close and then exit*/

void	clean_close(t_date *project)
{
	ft_printf("%sdestroying the windows\nexit(0)%s\n", RED, RESET);
	mlx_destroy_window(project->mlx, project->window);
	exit(0);
}
/* This function handle the ESC key press*/

int	key_pressed(int keycode, void *param)
{
	t_date	*help;

	help = (t_date *) param;
	if (keycode == ESCAPE)
		clean_close(help);
	else if (keycode == PLUS)
		test_function(help);
	else if (keycode == MINUS)
		test_function(help);
	else if (keycode == SPACE)
		test_function(help);
	return (1);
}
/* Saw online */

int	window_close(void *param)
{
	t_date	*help;

	help = (t_date *)param;
	clean_close(help);
	return (0);
}

void	new_windows(t_date *help, t_point **head)
{
	help->mlx = mlx_init();
	ft_printf("%smlx_init has started%s\n", YELLOW, RESET);
	if (help->mlx == NULL)
		exit(0);
	help->window = mlx_new_window(help->mlx, help->width,
			help->height, help->map_name);
	new_image(help);
	mlx_hook(help->window, 2, 1, key_pressed, help);
	mlx_hook(help->window, 17, 0L, window_close, help);
	draw_lines(help, head);
	mlx_put_image_to_window(help->mlx, help->window, help->img_pointer, 0, 0);
	ft_draw_instructions(help);
	free_list(*head);
	mlx_loop(help->mlx);
	return ;
}
