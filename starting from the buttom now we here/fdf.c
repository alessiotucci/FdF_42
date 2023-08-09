/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:36:11 by atucci            #+#    #+#             */
/*   Updated: 2023/08/09 17:07:23 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fdf.h"

/* static function to check the map */
static int	check_the_map(char *file_name, t_point *head)
{
	int	fd;
	char	*help_line;
	char	**matrix_map;
	int	rows;
	int	colums;

	rows = 0;
	colums = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ft_printf("\033[1;31mCan't read the map 😴 \033[0m\n"));
	while ((help_line = get_next_line(fd)) != NULL)
	{
		ft_printf("this is the line: %s\n", help_line);
		matrix_map = ft_split(help_line, ' ');
		while(matrix_map[rows] != NULL)
		{
			int prova = atoi(matrix_map[rows]);
			ft_printf("x:%d\ny:%d\nz is [%d]\n",rows, colums, prova);
			create_list(&head, rows, colums, matrix_map[rows]);
		rows++;
		}
	rows = 0;
	colums++;
	}
		ft_printf("%s%sRemember to free split\n%s%s", BG_YELLOW, GREEN, BG_RESET, RESET);
		return (0);
}
/* static function to check if the size of windows is digits or not? */
static int	check_windows_size(char *width, char *height)
{
	size_t	count;

	count = 0;
	while (width[count])
	{
		if (!ft_isdigit(width[count]))
		{
			ft_printf("\033[1;31mwrong size\033[0m\n");
			return (0);
		}
		count++;
	}
	count = 0;
	while (height[count])
	{
		if (!ft_isdigit(height[count]))
		{
			ft_printf("\033[1;31mwrong size \033[0m\n");
			return (0);
		}
		count++;
	}
	return (1);
}
/*check the extension of the map*/
static int	check_the_extension(char *name_of_map)
{
	int	len;

	len = strlen(name_of_map);
	if (len <= 4)
	{
		ft_printf("\033[1;41mmap name is very short!\033[0m\n");
		return (0);
	}
	if (strncmp(name_of_map + len - 4, ".fdf", 4) == 0)
	{
		ft_printf("\033[1;32mGood file extension👍 \033[0m\n");
		return (1);
	}
	ft_printf("\033[1;41mNot a valid .fdf extension\033[0m\n");
	return (0);
}

int	main(int ac, char *av[])
{
	int		width;
	int		height;
	t_point	*head;

	head = NULL;
	width = DEFAULT_WIDTH;
	height = DEFAULT_HEIGHT;
	if (ac < 2)
		return (ft_printf("%sNot enough params, did you forget map?%s\n", RED, RESET));
	if (ac == 4)
		{
			if (check_windows_size(av[2], av[3]))
			{
				width = ft_atoi(av[2]);
				height = ft_atoi(av[3]);
			}
		}
	check_the_extension(av[1]);
	check_the_map(av[1], head);
	ft_printf("%swidth:%d\nheight:%d%s\n", YELLOW, width, height, RESET);
	print_colored_list(head);
	return (ft_printf("%s Everything seems good to me %s\n", GREEN, RESET));
	}
