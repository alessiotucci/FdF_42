/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_connection_management_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:53:52 by atucci            #+#    #+#             */
/*   Updated: 2023/07/27 07:22:06 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h" 

// Handle the release of certain keys to prevent continuous events
static int release_management(int keycode, t_data *info)
{
    // Check if the keycode matches any of the keys that should be handled
    if (((keycode == 65362) || (keycode == 65364) || (keycode == 65361)
        || (keycode == 65363) || (keycode == 119) || (keycode == 97)
        || (keycode == 115) || (keycode == 100) || (keycode == 65451)
        || (keycode == 65453))
        && (info->keyrel == 0))
    {
        // Set the keyrel flag to 1 to prevent continuous events
        info->keyrel = 1;
    }
    return (0);
}

// Handle various transformations and projection changes based on the keycode
static int transformations_management(int keycode, t_data *info)
{
    // Handle projection changes
    if ((keycode == 65293) && (info->projection_check < 2))
    {
        info->projection_check++;
    }
    else if ((keycode == 65293) && (info->projection_check == 2))
    {
        info->projection_check = 0;
    }
    // Handle transformations
    else if ((keycode > 65360) && (keycode < 65365))
    {
        transformation_function(info, info->map, keycode, 0);
    }
    else if ((keycode == 119) || (keycode == 97) || (keycode == 115)
        || (keycode == 100))
    {
        transformation_function(info, info->map, keycode, 1);
    }
    else if ((keycode == 65451) || (keycode == 65453))
    {
        transformation_function(info, info->map, keycode, 2);
    }

    // Handle projection type changes
    if (keycode == 65293)
    {
        if (info->projection_check == 0)
        {
            info->projection_type = 105; // 'i' for isometric
        }
        else if (info->projection_check == 1)
        {
            info->projection_type = 112; // 'p' for parallel
        }
        else
        {
            info->projection_type = 101; // 'e' for equirectangular
        }
        // Perform the projection based on the selected type
        projection_function(info, info->map);
    }
    return (0);
}

// Handle image management and drawing
static int image_management(int keycode, t_data *info)
{
    int bits;
    int lsize;
    int endian;

    // If a valid keycode is provided, clear the previous image and apply transformations
    if (keycode != 0)
    {
        mlx_destroy_image(info->mlx, info->img);
        mlx_clear_window(info->mlx, info->win);
        transformations_management(keycode, info);
    }

    // Create a new image and set img_data for further drawing
    info->img = mlx_new_image(info->mlx, info->width, info->height);
    info->img_data = mlx_get_data_addr(info->img, &bits, &lsize, &endian);
    info->bits = &bits;
    info->lsize = &lsize;
    info->endian = &endian;

    // If keycode is 0, apply the initial projection and transformations
    if (keycode == 0)
    {
        projection_function(info, info->map);
        transformation_function(info, info->map, keycode, 3);
    }

    // Draw lines based on the updated image data
    draw_lines(info, info->map);

    // Put the updated image to the window
    mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
    return (0);
}

// Handle window closing events
static int closing_management(int keycode, t_data *info)
{
    // Handle certain key events
    if ((keycode == 65362) || (keycode == 65364) || (keycode == 65361)
        || (keycode == 65363) || (keycode == 119) || (keycode == 97)
        || (keycode == 115) || (keycode == 100) || (keycode == 65451)
        || (keycode == 65453))
    {
        // Reset the keyrel flag and update the image accordingly
        info->keyrel = 0;
        image_management(keycode, info);

        // Wait for the keyrel flag to be set again before proceeding
        while (info->keyrel != 1)
        {
            image_management(keycode, info);
        }
    }
    // Handle window close events
    else if (keycode == 65307 || keycode == 0)
    {
        // Destroy the image, window, and display, then exit the program
        mlx_destroy_image(info->mlx, info->img);
        mlx_destroy_window(info->mlx, info->win);
        mlx_destroy_display(info->mlx);
        exit(0);
    }
    else
    {
        return (0);
    }
    return (0);
}

// Main function to handle connection management with MiniLibX
int connection_management(t_data *info)
{
    // Initialize MiniLibX
    info->mlx = mlx_init();

    // Create a window with the specified dimensions and title
    info->win = mlx_new_window(info->mlx, info->width, info->height, "FdF");

    // Set closing_management function to handle window close events
    mlx_hook(info->win, 2, (1L << 0), closing_management, info);
    mlx_hook(info->win, 17, (1L << 2), closing_management, info);

    // Initialize image and draw the initial map
    image_management(0, info);

    // Set release_management function to handle key release events
    mlx_hook(info->win, 3, (1L << 1), release_management, info);

    // Start the MiniLibX loop for event handling
    mlx_loop(info->mlx);

    return (0);
}

