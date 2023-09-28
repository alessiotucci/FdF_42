/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_manag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:19:48 by atucci            #+#    #+#             */
/*   Updated: 2023/09/28 13:42:54 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"


void	new_image(t_date *inf)
{
	ft_printf("\nInside new image function;\ngetting address in img_data\n:::::::::::::::::\n\n");
	inf->img_pointer = mlx_new_image(inf->window, inf->width, inf->height);
	if (inf->img_pointer == NULL) // this will be modify later on
		exit(0);// use the clean_close?
	inf->img_string = mlx_get_data_addr(inf->img_pointer, &(inf->bits), &(inf->rows), &(inf->endian));
	if (inf->img_string == NULL)
		exit(0); // use the clean close?
	//ft_bzero(inf->img_string, inf->width * inf->height * (inf->bits / 8));

}
/* This function perfom a cleana close and then exit*/
void	clean_close(t_date *project)
{
	mlx_destroy_window(project->mlx, project->window);
	exit(0);
}

/* This function handle the ESC key press*/
int	esc_pressed(int keycode, void *param)
{
	if (keycode == ESCAPE)
	{
		t_date *help = (t_date *) param;
		clean_close(help);
	}
		return (1);
}

void	new_windows(t_date *help, t_point **head)
{
	help->mlx = mlx_init(); ft_printf("mlx_init has started\t");
	if (help->mlx == NULL)
		exit(0);
	help->window = mlx_new_window(help->mlx, help->width, help->height, "testing out");
	new_image(help);
	mlx_hook(help->window, 2, 1, esc_pressed, help); // to be tested

	draw_lines(help, head);

	mlx_put_image_to_window(help->mlx, help->window, help->img_pointer, 0, 0);
	ft_draw_instructions(help);

	mlx_loop(help->mlx);
	return ;
}
