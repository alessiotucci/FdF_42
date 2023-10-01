/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:35:56 by atucci            #+#    #+#             */
/*   Updated: 2023/10/01 14:28:55 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_colored_list(t_point **head)
{
	t_point		*current;
	static int	count;

	ft_printf("\n\n\n");
	count = 0;
	current = *head;
	while (current != NULL)
	{
		ft_printf("\n---------------------------------\n");
		ft_printf("|POINT:%d ADDRESS:%p |\n", count++, current);
		ft_printf("---------------------------------\n");
		ft_printf("\033[0;30;42mx_map: %d\t\t\t|\033[0m\n", current->x_map);
		ft_printf("\033[0;30;42my_map: %d\t\t\t|\033[0m\n", current->y_map);
		ft_printf("\033[0;30;42mz_map: %d\t\t\t|\033[0m\n", current->z_map);
		ft_printf("%s x pixel: %d\t\t\t|%s\n", CYAN, current->x_pixel, RESET);
		ft_printf("%s y pixel: %d\t\t\t|%s\n", CYAN, current->y_pixel, RESET);
		ft_printf("\033[0;30;43mgo_right:%p\t\t|\033[0m\n", current->go_right);
		ft_printf("\033[0;30;43mgo_down: %p\033[0m\n", current->go_down);
		ft_printf("\033[0;30;41mnext: %p\033[0m\n", current->next);
		ft_printf("---------------------------------\n");
		ft_printf("\n\n\n");
		current = current->next;
	}
}

int	free_split(char **tab)
{
	int	count;

	count = 0;
	while (tab[count])
	{
		free(tab[count++]); 
	}
	free(tab);
	return (0);
}

void	ft_draw_instructions(t_date *env)
{
	mlx_string_put(env->mlx, env->window, 5, 0, COLOR_RED,"Alessio tucci FDF");
	mlx_string_put(env->mlx, env->window, 5, 20, COLOR_YELLOW,
		"testing the function mlx string put...");
	mlx_string_put(env->mlx, env->window, 5, 40, COLOR_MAGENTA,
		"cant do any bonuses");
}

void	test_function(t_date *env)
{
	static int	count;

	count = 0;
	mlx_string_put(env->mlx, env->window, 5 + count, 60 + count, COLOR_GREEN,"void test_function");
	count += 10;
}
/* In this function we will try to set pixel in the img of mlx*/
void	draw_point(t_date *info, int x, int y)
{
	ft_printf("\t[%d][%d]\t\n", x, y);
	if (x >= 0 && x < DEFAULT_WIDTH && y >= 0 && y < DEFAULT_HEIGHT)
		my_mlx_pixel_put(info, x, y, COLOR_WHITE);
	return ;
}
