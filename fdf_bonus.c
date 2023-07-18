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

static int	check_the_map(int fd)
{
	char	*ret;
	char	**thot; // 2D array to store map data

	// Open the file for reading

	ret = get_next_line(fd);
	// Read the file line by line using get_next_line
//	while (ret)
//	{
		// Here, 'line' contains the current line read from the file
		// You can process the line as needed (e.g., split it into tokens or convert characters to integers)
		// After processing, you can store the data in your map data structure
		thot = ft_split(ret, ' '); // Split the line into tokens based on spaces
		ft_printf(" this is the fist line %s\n", thot[0]);
		// Now 'map_data' contains an array of strings, each element representing a value in the map
		// You can convert these strings to integers and store them in your map structure
//	}

	// Check for errors or end of file
	if (ret == NULL)
	{
		// Error occurred during file read, handle the error here (e.g., close the file and free memory)
		ft_printf("\033[1;41mError: reading the map\n\033[0m"); // Red background for error message
		// FREE SPLIT NEEDED Free the memory allocated for 'map_data' if there was an error
		close(fd);
		return (-1);
	}

	// Close the file since it's no longer needed
	close(fd);

	// Return success
	return (0);
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
		info.fd = check_the_map(info.fd);
	}	
	ft_printf("larghezza%d\n", info.win_widht);
	ft_printf("lunghezza%d\n", info.win_height);
	ft_printf("fd:%d\n", info.fd);
// call the other funciton passing the fd file descriptor;
	return (0);
	
}

