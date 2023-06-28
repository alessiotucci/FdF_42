/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:33:51 by atucci            #+#    #+#             */
/*   Updated: 2023/06/28 18:51:45 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_ptin
{
	int x;
	int y;
	struct s_ptin *next;
}	t_ptin;

t_ptin	*add_new_node(int x, int y)
{
 	t_ptin	*new_node;

 	new_node = malloc(sizeof(t_ptin));
 	if (!new_node)
 		return (NULL);
 	new_node->x = x;
 	new_node->y = y;
	new_node->next = NULL;
 	return (new_node);
 }

t_ptin *drawline_breseham(t_point a, t_point b)
{
	//this function takes two point as paramater and return 
	// a list of points, those point will be the coordinated of the pixel that need to be lighted up
	int	delta_y;
	int	delta_x;
	t_ptin *return_points;
	// I will need  this parameter to make decisions
	int	decision_paramater;
	// declaring the slop as float;
	int	slope;

	delta_y = b.y - a.y;
	delta_x = b.x - a.x;
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
			if(decision_paramater > 1)
			
			return_points = add_new_node(a.x, a.y + 1);
			
			else
			return_points = add_new_node(a.x, a.y);
		a.x++;
		
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
			if(decision_paramater > 1)
			return_points = add_new_node(a.x + 1, a.y);
			else
			return_points = add_new_node(a.x, a.y);
		}
	}
	// the formula of a line is y = mx + q;
	// I need to apply this same formula to find all the point of the line
	return(&return_points);
}
