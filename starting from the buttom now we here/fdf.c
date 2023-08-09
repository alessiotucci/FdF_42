/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:36:11 by atucci            #+#    #+#             */
/*   Updated: 2023/08/09 11:04:35 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fdf.h"

/* static function to check the map */
static int	check_the_map(char *file_name)
{
	int	fd;
	char	*help_line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ft_printf("\033[1;31mCan't read the map 😴 \033[0m\n"));
	help_line = get_next_line(fd);
	return (ft_printf("this is the help_line: %s\n", help_line));
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

int	main(int ac, char *av[])
{
	int	width;
	int	height;

	width = DEFAULT_WIDTH;
	height = DEFAULT_HEIGHT;
	ft_printf("%sDefault width:%d\nDefault height:%d%s\n", YELLOW, width, height, RESET);
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
	check_the_map(av[1]);
	return (ft_printf("%s Everything seems good to me %s\n", GREEN, RESET));
	}
