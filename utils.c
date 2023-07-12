/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:33:51 by atucci            #+#    #+#             */
/*   Updated: 2023/07/12 16:44:02 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


t_line *drawline_breseham(t_line a, t_line b)
{
	//this function takes two point as paramater and return 
	// a list of points, those point will be the coordinated of the pixel that need to be lighted up
	int	delta_y;
	int	delta_x;
	t_line *return_points;
	t_line *new_node;
	// I will need  this parameter to make decisions
	int	decision_paramater;
	// declaring the slop as float;
	int	slope;

	new_node = NULL;
	return_points = NULL;
	delta_y = b.y - a.y;
	delta_x = b.x - a.x;
	// check the dimostration of the algorithm
	decision_paramater = 2 * (delta_y - delta_x);
	// I need now to calculate the slope of the line
	slope = delta_y / delta_x;
	if (slope >= 1) // if the slope is greater than zero it means you move vertically
// 	  y
//    │
//  7 │       *
//  6 │      *
//  5 │     *
//  4 │	   *
//  3 │	  *   
//  2 │  *
//  1 │ *      
//  0 └─────────────────── x
//    0  1  2  3  4  5  6
	{
		while (a.x <= b.x)
		{
			if(decision_paramater > 0)
			{			
			// create the new node
			decision_paramater -= 2 * delta_x;  // Update the decision parameter
			}
			else
			{
			// create the new node
			new_node->next = return_points;	
			}
		a.x++;
		// update the decison paramater
		decision_paramater += 2 *delta_y;
		}
	}
	else
	// 	  y
//    │
//  7 │
//  6 │
//  5 │
//  4 │		  		*
//  3 │			*   
//  2 │		*   
//  1 │*      
//  0 └─────────────────── x
//    0  1  2  3  4  5  6
	{
		while (a.y <= b.y)
		{
			if(decision_paramater > 0)
			{
			decision_paramater -= 2 * delta_y;
			}
			else
		a.y++;
		// update the decision paramater
		decision_paramater  += 2 * delta_x;
		}
	}
	// the formula of a line is y = mx + q;
	// I need to apply this same formula to find all the point of the line
	return(return_points);
}
t_line *dham(t_line a, t_line b)
{
	t_line	*start;
	t_line	*end;
	t_line	*current;
	int		delta_x;
	int		delta_y;
	int		slope;
	int		decision_paramater;
	end = from_ints_to_nodes(b.x, b.y, b.z, 'e');// End node of the line
    start = from_ints_to_nodes(a.x, a.y, a.z, 's');
	current = start;// Pointer to traverse the linked list
	delta_x = abs(b.x - a.x);
	delta_y = abs(b.y - a.y);
    if (delta_y > delta_x)
		slope = 1;
	else
		slope = 0;
// Determine the decision parameter based on the slope
    if (slope)
        decision_paramater = 2 * delta_x - delta_y;
    else
        decision_paramater = 2 * delta_y - delta_x;
 // Generate the points using Bresenham's algorithm
    while (current->x != end->x || current->y != end->y)
    {
        if (slope)
        {
            if (decision_paramater > 0)
            {
                decision_paramater -= 2 * delta_y;
                //current->x += (b.x > a.x) ? 1 : -1;
				if (b.x > a.x)
					current->x += 1;
				else
					current->x -= 1;
            }
            decision_paramater += 2 * delta_x;
            //current->y += (b.y > a.y) ? 1 : -1;
			if (b.y > a.y)
				current->y += 1;
			else
				current->y -= 1;
		}
        else
        {
            if (decision_paramater > 0)
            {
                decision_paramater -= 2 * delta_x;
            //   current->y += (b.y > a.y) ? 1 : -1;
				if (b.y > a.y)
					current->y += 1;
				else
					current->y -= 1;
			}
            decision_paramater += 2 * delta_y;
            //current->x += (b.x > a.x) ? 1 : -1;
			if (b.x > a.x)
				current->x += 1;
			else
				current->x -= 1;
        }

        // Create a new node for the next point
        current->next = from_ints_to_nodes(current->x, current->y, current->z, 'q');
        current = current->next;
    }

    return start;  // Return the start node of the linked list
}

