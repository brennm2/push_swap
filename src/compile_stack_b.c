/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:49:10 by bde-souz          #+#    #+#             */
/*   Updated: 2024/03/04 18:32:55 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_stack_node	*find_smallest_node (t_stack_node *node)
{
	long	smallest;
	t_stack_node	*smallest_node;

	if (!node)
		return (NULL);
	smallest = LONG_MAX;
	while(node)
	{
		if(node->nbr < smallest)
		{
			smallest = node->nbr;
			smallest_node = node;
		}
		node = node->next;
	}
	return (smallest_node);
}


static void	set_target_b(t_stack_node *node_a, t_stack_node *node_b)
{
	t_stack_node *current_node_a;
	t_stack_node *target_node;
	long		closest_biggest_number;

	while (node_b)
	{
		closest_biggest_number = LONG_MAX;
		current_node_a = node_a;
		while(current_node_a)
		{
			if (current_node_a->nbr > node_b->nbr
				&& current_node_a->nbr < closest_biggest_number)
			{
				closest_biggest_number = current_node_a->nbr;
				target_node = current_node_a;
			}
			current_node_a = current_node_a->next;
		}
		if (closest_biggest_number == LONG_MAX)
			node_b->target_node = find_smallest_node (node_a);
		else
			node_b->target_node = target_node;
		node_b = node_b->next;
	}
}

void	compile_stack_b (t_stack_node *a, t_stack_node *b)
{
	set_index(a);
	set_index(b);
	set_target_b(a, b);
}