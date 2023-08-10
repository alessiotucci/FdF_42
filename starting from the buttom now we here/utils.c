/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:35:56 by atucci            #+#    #+#             */
/*   Updated: 2023/08/10 09:38:16 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_colored_list(t_point **head)
{
	t_point	*current;

	current = *head;
	while (current != NULL)
	{
		ft_printf("\033[0;30;42mx_map: %d\033[0m\n", current->x_map);
		ft_printf("\033[0;30;42my_map: %d\033[0m\n", current->y_map);
		ft_printf("\033[0;30;42mz_map: %d\033[0m\n", current->z_map);
		ft_printf("%s x pixel: %d%s\n", CYAN, current->x_pixel, RESET);
		ft_printf("%s y pixel: %d%s\n", CYAN, current->y_pixel, RESET);
		ft_printf("\033[0;30;43mgo_right: %p\033[0m\n", (void *)current->go_right);
		ft_printf("\033[0;30;43mgo_down: %p\033[0m\n", (void *)current->go_down);
		ft_printf("\033[0;30;41mnext: %p\033[0m\n", (void *)current->next);
		ft_printf("\n");
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
