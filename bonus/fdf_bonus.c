/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:59:31 by atucci            #+#    #+#             */
/*   Updated: 2023/07/18 14:50:43 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	check_the_map(char *file_name)
{
	int	fd;
	char	*helping;
	//char	**matrix;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("can't open the map\n");
		return (fd);
	}
	helping = malloc(sizeof(char) * 1000);
	return(read(fd, helping, 1000));
	//matrix = ft_split(helping, '\n');
	// now I need to check  the matrix  to perfom the map checks...
	//return 0;	
}

static int	what_kind_project(char *str)
{	
	if (strncmp(str, "isometric", 9) == 0)
        	return (69); // The string is equal to "isometric".
	else if (strncmp(str, "parallel", 8) == 0)
		return (70); // The string is equal to "parallel".
	else if (strncmp(str, "equirectangular", 15) == 0)
        	return (65); // The string is equal to "equirectangular"
	else
		return (0);
}

static int check_windows_size(char *larghe, char *altezz)
{
	size_t	count;
	count = 0;
	while (larghe[count])
	{
		if (ft_isdigit(larghe[count]) != 0)
		return (0);
	count++;
	}
	count = 0;
	while (altezz[count])
	{
		if (ft_isdigit(altezz[count]) != 0)
		return (0);
	count++;
	}
	return (1);
}

static int  check_the_extension(char *name_of_map)
{
	int	len;
	len = strlen(name_of_map);
	if (len < 4)
		return (0);
	if (strncmp(name_of_map + len - 4, ".fdf", 4) == 0)
		return (1);
	return (0);
}

int	main(int ac, char *av[])
{
	static t_data	info; // this is the struct that is gonna be initialized
	
	info.win_widht = DEFAULT_WIDTH;
	info.win_height = DEFAULT_HEIGHT;	
	info.fd = ft_printf("let me check the params\n");
	if ((ac >= 2) && (ac != 3) && (ac < 5))
	{
		info.fd = check_the_extension(av[1]);
		if (info.fd == 0)
			return (0);
		if (ac == 4) // i have the widht and height explicit
		{
			if (check_windows_size(av[2], av[3]))
			{
				info.win_widht = ft_atoi(av[2]);
				info.win_height = ft_atoi(av[3]);
			}
		
		}	
		if (ac == 5)
			info.project_type = what_kind_project(av[4]);
		info.fd = check_the_map(av[1]);
	}	
	ft_printf("larghezza%d\n", info.win_widht);
	ft_printf("lunghezza%d\n", info.win_height);
	ft_printf("fd:%d\n", info.fd);
// call the other funciton passing the fd file descriptor;
	return (0);
	
}

