/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:30:57 by atucci            #+#    #+#             */
/*   Updated: 2023/08/09 17:07:03 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void print_colored_list(t_point *head)
{
	ft_printf("%spointer head is: {%p}%s\n", RED, head, RESET);
	t_point *current;
	int count;

	count = 0;
	current = head;
	while (current != NULL)
	{
		count++;
		ft_printf("\033[0;30;42mx_map: %d\033[0m\n", current->x_map);
		ft_printf("\033[0;30;44mx_pixel: %d\033[0m\n", current->x_pixel);
		ft_printf("\033[0;30;42my_map: %d\033[0m\n", current->y_map);
		ft_printf("\033[0;30;44my_pixel: %d\033[0m\n", current->y_pixel);
		ft_printf("\033[0;30;43mgo_right: %p\033[0m\n", (void *)current->go_right);
		ft_printf("\033[0;30;43mgo_down: %p\033[0m\n", (void *)current->go_down);
		ft_printf("\033[0;30;41mnext: %p\033[0m\n", (void *)current->next);
		ft_printf("\n");
		current = current->next;
	}
	ft_printf("if the count[%d] is 0 there is a issue\n", count);
}

void	create_list(t_point **head, int x, int y, char *z_string)
{
	int		z;
	t_point	*new_node;
	t_point	*current;

	z = atoi(z_string);
	new_node = (t_point *)malloc(sizeof(t_point));
	if (new_node == NULL)
		exit(1);
	new_node->x_map = x;
	new_node->y_map = y;
	new_node->z_map = z;
	new_node->x_pixel = 0;
	new_node->y_pixel = 0;
	new_node->go_right = NULL;
	new_node->go_down = NULL;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}
