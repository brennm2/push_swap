/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:01:04 by bde-souz          #+#    #+#             */
/*   Updated: 2024/03/20 15:18:51 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	set_index(t_stack_node *node)
{
	int		i;
	int		median;

	i = 0;
	median = stack_len (node) / 2;
	if (!node)
		return ;
	while (node)
	{
		node->index = i;
		if (i <= median)
			node->above_mediam = true;
		if (i > median)
			node->above_mediam = false;
		node = node->next;
		i++;
	}
}

static void	set_target_a(t_stack_node *node_a, t_stack_node *node_b)
{
	t_stack_node	*current_node_b;
	t_stack_node	*target_node;
	long			closest_smaller_number;

	while (node_a)
	{
		closest_smaller_number = LONG_MIN;
		current_node_b = node_b;
		while (current_node_b)
		{
			if (node_a->nbr > current_node_b->nbr
				&& current_node_b->nbr > closest_smaller_number)
			{
				closest_smaller_number = current_node_b->nbr;
				target_node = current_node_b;
			}
			current_node_b = current_node_b->next;
		}
		if (closest_smaller_number == LONG_MIN)
			node_a->target_node = find_biggest_node(node_b);
		else
			node_a->target_node = target_node;
		node_a = node_a->next;
	}
}

static void	find_cost_a(t_stack_node *a, t_stack_node *b)
{
	int		len_a;
	int		len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (a->above_mediam == false)
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_mediam == true)
			a->push_cost = a->push_cost + a->target_node->index;
		else
			a->push_cost = a->push_cost + len_b - (a->target_node->index);
		a = a->next;
	}
}

void	find_cheapest(t_stack_node *node)
{
	long				cheapest_value;
	t_stack_node		*cheapest_node;

	if (!node)
		return ;
	cheapest_value = LONG_MAX;
	while (node)
	{
		if (cheapest_value > node->push_cost)
		{
			cheapest_value = node->push_cost;
			cheapest_node = node;
		}
		node = node->next;
	}
	cheapest_node->cheapest = true;
}

void	compile_stack_a(t_stack_node *a, t_stack_node *b)
{
	set_index(a);
	set_index(b);
	set_target_a(a, b);
	find_cost_a(a, b);
	find_cheapest(a);
}
