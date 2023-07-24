/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_registration_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:59:31 by fporciel          #+#    #+#             */
/*   Updated: 2023/07/24 09:26:46 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* 
* This software is made available to anyone who wants to retrace the 
* author's learning path through the projects of school 42.
* Copyright (C) 2023  fporciel
* 
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
*
* You can contact the author at: 
*- fporciel@student.42roma.it
*/

#include "fdf_bonus.h"

// Function to clean the memory allocated by the split operation
static int clean_split_operation(t_data *info, char ***split_result)
{
	// Initialize garbage variable to count elements to free
	info->garbage = 0;

	// Check if split_result and *split_result are not NULL
	if (split_result && (*split_result))
	{
		// Free each element and count the number of elements freed
		while ((*split_result)[info->garbage] != NULL)
			free((*split_result)[info->garbage++]);

		// Free the split_result itself
		free(*split_result);
		(*split_result) = NULL;
	}
	return (0);
}

// Function to clean the memory allocated for the map
static int clean_map_memory(t_map ***map, t_data *info, char **line)
{
	// Free the line pointer if it's not NULL
	if (line && (*line))
	{
		free(*line);
		(*line) = NULL;
	}

	// Free each row of the map and set pointers to NULL
	if (map && (*map) && (info->y_count > 0))
	{
		while (info->y_count >= 0)
		{
			free((*map)[info->y_count]);
			((*map)[info->y_count--]) = NULL;
		}
	}

	// Free the map itself and set the pointer to NULL
	if (map && (*map))
	{
		free(*map);
		(*map) = NULL;
	}
	return (0);
}

// Function to generate point attributes for the map
static void generate_point_attributes(t_map *map, t_data *info, int param)
{
	// Assign the corresponding x, y, and z values to the point
	map[info->x_count].x_orthogonal = info->x_count;
	map[info->x_count].x_display = info->x_count;
	map[info->x_count].y_orthogonal = info->y_count;
	map[info->x_count].y_display = info->y_count;
	map[info->x_count].z_orthogonal = info->z_count;
	map[info->x_count].z_display = info->z_count;

	// Set the right_point and down_point to NULL
	map[info->x_count].right_point = NULL;
	map[info->x_count].down_point = NULL;

	// Assign the stop_param value based on the 'param' argument
	if (param == 0)
		map[info->x_count].stop_param = 0;
	if (param == 1)
		map[info->x_count].stop_param = 1;
}

// Function to divide the input line into map elements
static int divide_map_line(t_data *info, t_map **map, char *line)
{
	char **splitted_line;

	// Split the line by space characters (ASCII 32)
	splitted_line = ft_split(line, 32);
	if (splitted_line == NULL)
		return (0);

	// Initialize count to 0
	info->count = 0;

	// Count the number of elements in the splitted_line
	while (splitted_line[info->count] != NULL)
		info->count++;

	// Allocate memory for the row of the map
	map[info->y_count] = (t_map *)malloc(sizeof(t_map) * (info->count + 1));
	if (map == NULL)
		return (clean_split_operation(info, &splitted_line));

	// Initialize x_count to 0
	info->x_count = 0;

	// Iterate through the splitted_line elements and populate the map
	while (splitted_line[info->x_count] != NULL)
	{
		info->z_count = ft_atoi(splitted_line[info->x_count]);
		generate_point_attributes(map[info->y_count], info, 0);
		(info->x_count)++;
	}

	// Set the attributes for the last point in the row
	generate_point_attributes(map[info->y_count], info, 1);

	// Clean up the splitted_line and return the status
	info->garbage = clean_split_operation(info, &splitted_line);
	return (1);
}

// Function to register the map data
int register_map_data(t_data *info)
{
	// Static map variable to store the map data
	static t_map **map;

	// Line variable to read each line from the input file
	char *line;

	// Allocate memory for the map variable
	map = (t_map **)malloc(sizeof(t_map *) * (info->max_y + 2));
	if (map == NULL)
		return (0);

	// Loop through each row of the map
	while (info->y_count <= info->max_y)
	{
		// Read a line from the input file
		line = get_next_line(info->fd);

		// Check if line is NULL and y_count is less than or equal to max_y
		if ((line == NULL) && (info->y_count <= info->max_y))
			return (clean_map_memory(&map, info, NULL));

		// Process the line and divide it into map elements
		if (line != NULL)
			info->garbage = divide_map_line(info, map, line);

		// Check if line is not NULL and the garbage is 0 (no errors)
		if ((line != NULL) && (info->garbage == 0))
			return (clean_map_memory(&map, info, &line));

		// Move to the next row of the map
		(info->y_count)++;

		// Free the line pointer
		if (line != NULL)
			free(line);
	}

	// Set the last element of the map to NULL
	map[info->y_count] = NULL;

	// Perform points conjunction and store the result in info->garbage
	info->garbage = points_conjuction(info, &map);

	// Clean up the map memory and return the status
	return (clean_map_memory(&map, info, NULL));
}

