#include "fdf.h"

void	bresenham(t_date *info, t_point *start, t_point *end)
{
	int delta_x = end->x_pixel - start->x_pixel;
	int delta_y = end->y_pixel - start->y_pixel;

	if (delta_x == 0)
		draw_vertical_line(info, start, end);
	else if (delta_y == 0)
		draw_horizontal_line(info, start, end);
	else if (abs(delta_y) < abs(delta_x))
		draw_low_slope_line(info, start, end);
	else
		draw_high_slope_line(info, start, end);
}

void draw_vertical_line(t_date *info, t_point *start, t_point *end)
{
	int y = start->y_pixel;
	while (y <= end->y_pixel)
	{
		draw_point(info, start->x_pixel, y);
		y++;
	}
}

void draw_horizontal_line(t_date *info, t_point *start, t_point *end)
{
	int x = start->x_pixel;
	while (x <= end->x_pixel)
	{
		draw_point(info, x, start->y_pixel);
		x++;
	}
}

void draw_low_slope_line(t_date *info, t_point *start, t_point *end)
{
	int delta_x = end->x_pixel - start->x_pixel;
	int delta_y = end->y_pixel - start->y_pixel;
	int p = 2 * delta_y - delta_x;
	int x = start->x_pixel;
	int y = start->y_pixel;

	while (x <= end->x_pixel)
	{
		draw_point(info, x, y);
		if (p >= 0)
		{
			y++;
			p = p - 2 * delta_x;
		}
		p = p + 2 * delta_y;
		x++;
	}
}

void draw_high_slope_line(t_date *info, t_point *start, t_point *end)
{
	// Implement the high-slope line drawing algorithm here
	// Similar to the low-slope case, but swapping x and y
}
