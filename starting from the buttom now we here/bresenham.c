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

