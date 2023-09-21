/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:35:56 by atucci            #+#    #+#             */
/*   Updated: 2023/09/21 15:02:25 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_colored_list(t_point **head)
{
	ft_printf("\n\n\n");
	t_point	*current;
	static int count;

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
		ft_printf("\033[0;30;43mgo_right:%p\t\t|\033[0m\n", (void *)current->go_right);
		ft_printf("\033[0;30;43mgo_down: %p\033[0m\n", (void *)current->go_down);
		ft_printf("\033[0;30;41mnext: %p\033[0m\n", (void *)current->next);
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
