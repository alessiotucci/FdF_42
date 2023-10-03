/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:36:11 by atucci            #+#    #+#             */
/*   Updated: 2023/10/03 19:00:29 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* static function to check the fd*/
static	char	*check_the_fd(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%sInvalid fd[%d]%s\n", RED, fd, RESET);
		ft_printf("%sEXITING THE PROGRAM%s\n", BG_RED, RESET);
		exit (0);
	}
	return (file_name);
}

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
	fd = open(check_the_fd(file_name), O_RDONLY);
	while (1)
	{
		help_line = get_next_line(fd);
		if (help_line == NULL)
			break ;
		matrix_map = ft_split(help_line, ' ');
		while (matrix_map[rows] != NULL)
		{
			create_list(head, rows, colums, matrix_map[rows]);
			free(matrix_map[rows]);
			rows++;
		}
		rows = 0;
		colums++;
		free(help_line);

	}
	free(help_line);
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
			ft_printf("\033[1;31mwrong size of windows\033[0m\n");
			exit (0);
		}
		count++;
	}
	count = 0;
	while (height[count])
	{
		if (!ft_isdigit(height[count]))
		{
			ft_printf("\033[1;31mwrong size of windows\033[0m\n");
			exit (0);
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
		return (0);
	}
	ft_printf("\033[1;41mNot a valid .fdf extension\033[0m\n");
	return (1);
}
/*
	*This is the main body of the function
	*where all the process starts
	*I start with the parsing of the map
	*and then I start creating the windows
*/

int	main(int ac, char *av[])
{
	t_point	*head;
	t_date	info_map;
	int		flag;

	head = NULL;
	info_map.width = DEFAULT_WIDTH;
	info_map.height = DEFAULT_HEIGHT;
	if (ac < 2 || ac > 4 || ac == 3)
		return (ft_printf("%sNot enough, or too much?%s\n", RED, RESET));
	if (ac == 4)
	{
		if (check_windows_size(av[2], av[3]))
		{
			info_map.width = ft_atoi(av[2]);
			info_map.height = ft_atoi(av[3]);
			check_if_windows(&info_map);
		}
	}
	flag = (check_the_extension(av[1]) + check_the_map(av[1], &head));
	if (flag != 0)
		exit (0);
	info_map.map_name = av[1];
	check_and_count(head, &info_map);
	new_windows(&info_map, &head);
	return (0);
}
	/*
		*1) open windows
		*2) draw the image
		*3) put image to windows
		*4) check the pointers because you're dumb. (lsize != rows);
	*/
