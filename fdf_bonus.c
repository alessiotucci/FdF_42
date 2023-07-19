/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:59:31 by atucci            #+#    #+#             */
/*   Updated: 2023/07/19 11:56:21 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	check_the_map(char *file_name, t_data info)
{
	int	fd;
	char	*helping;
	char	**matrix;
	int	count_y;
	int	count_x;
	
	count_x = 0;
	count_y = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("\033[1;31mCan't read the map 😴 \033[0m\n");
		return (fd);
	}
	while (helping = get_next_line(fd));
	{
	if (!helping)
		return (-1);
	matrix = ft_split(helping, ' ');
	while (matrix[count_y] != NULL)
	{
		count_x = 0;
		while (matrix[count_y][count_x] != '\0' &&  matrix[count_y][count_x] != '\n')
			count_x++;
	}
	count_y++;
	}
	info.max_x = count_x;
	info.max_y = count_y;
	ft_printf("map max x %d\n", info.max_x);
	ft_printf("map max y %d\n", info.max_y);

	return (fd);	
}

static int	what_kind_project(char *str)
{
	if (strncmp(str, "isometric", 9) == 0)
        {
		ft_printf("\033[1;42mIsometric\033[0m\n");
		return (69);
	}
	else if (strncmp(str, "parallel", 8) == 0)
	{
		ft_printf("\033[1;42mParallel\033[0m\n");
		return (70);
	}
	else if (strncmp(str, "equirectangular", 15) == 0)
        {
		ft_printf("\033[1;42mequirecrangular\033[0m\n");
		return (65);
	}
	else
		return (0);
}

static int check_windows_size(char *width, char *height)
{
	size_t	count;

	count = 0;
	while (width[count])
	{
		if ((width[count] < 48) || (width[count] > 57))
		{
			ft_printf("\033[1;31mwrong size\033[0m\n");
			return (0);
		}
		count++;
	}
	count = 0;
	while (height[count])
	{
		if ((height[count] < 48) || (height[count] > 57))
		{
			ft_printf("\033[1;31mwrong size \033[0m\n");
			return (0);
		}
		count++;
	}
	return (1);
}

static int  check_the_extension(char *name_of_map)
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
	static t_data	info;
	
	info.win_width = DEFAULT_WIDTH;
	info.win_height = DEFAULT_HEIGHT;	
	info.fd = ft_printf("let me check the params\n");
	if (ac < 2)
		return(ft_printf("Not  enough params\n"));
	if ((ac >= 2) && (ac <= 5))
	{
		info.fd = check_the_extension(av[1]);
		if (info.fd == 0)
			return (0);
		if (ac >= 4)
		{
			if (check_windows_size(av[2], av[3]))
			{
				info.win_width = ft_atoi(av[2]);
				info.win_height = ft_atoi(av[3]);
			}
		}	
		if (ac == 5)
			info.projection_type = what_kind_project(av[4]);
		info.fd = check_the_map(av[1], info);
	}	
	ft_printf("finestra opt%d\n", info.win_width);
	ft_printf("finestra opt%d\n", info.win_height);
	ft_printf("fd:%d\n", info.fd);
// call the other funciton passing the fd file descriptor;
	return (0);
}
