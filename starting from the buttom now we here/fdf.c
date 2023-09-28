/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:36:11 by atucci            #+#    #+#             */
/*   Updated: 2023/09/28 10:08:21 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fdf.h"

/* static function to check the map */
static int	check_the_map(char *file_name, t_point **head)
{
	int		fd;
	char	*help_line;
	char	**matrix_map;
	int		rows;
	int		colums;

	rows = 0;
	colums = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ft_printf("\033[1;31mCan't read the map 😴 \033[0m\n"));
	while ((help_line = get_next_line(fd)) != NULL)
	{
		ft_printf("this is the line: %s\n", help_line);
		matrix_map = ft_split(help_line, ' ');
		while (matrix_map[rows] != NULL)
		{
			create_list(head, rows, colums, matrix_map[rows]);
			rows++;
		}
		rows = 0;
		colums++;
	}
	free_split(matrix_map);
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
	if (len < 4)
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
/*
	*This is the main body of the function
	*where all the process starts
	*I start with the parsing of the map
	*and then I start creating the windows*/

int	main(int ac, char *av[])
{
	t_point	*head;
	t_date	info_map;

	head = NULL;
	info_map.width = DEFAULT_WIDTH;
	info_map.height = DEFAULT_HEIGHT;
	if (ac < 2)
		return (ft_printf("%sNot enough, forget map?%s\n", RED, RESET));
	if (ac == 4)
	{
		if (check_windows_size(av[2], av[3]))
		{
			info_map.width = ft_atoi(av[2]);
			info_map.height = ft_atoi(av[3]);
		}
	}
	check_the_extension(av[1]);
	check_the_map(av[1], &head);
	ft_printf("%swidth:%d\nheight:%d%s\n", YELLOW, info_map.width, info_map.height, RESET);
	info_map.total_points = check_and_count(head, &info_map);
	point_connect(&head);
	space_and_scale(&info_map);
	int_to_pixel(&info_map, &head);
	ft_printf("%sThe lenght of the list is :%d%s\n", GREEN, info_map.total_points, RESET);
	ft_printf("%sThe map is a [%d X %d]%s\n", GREEN, info_map.colums, info_map.rows, RESET);
	print_colored_list(&head);
	print_infos(&info_map);
	new_windows(&info_map, &head);
	free_list(head);
	return (ft_printf("%s Everything seems good to me %s\n", GREEN, RESET));
}
	/*
		*1) open windows
		*2) draw the image
		*3) put image to windows
	*/
