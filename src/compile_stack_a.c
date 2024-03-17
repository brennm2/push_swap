/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:01:04 by bde-souz          #+#    #+#             */
/*   Updated: 2024/03/04 20:58:24 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	set_index(t_stack_node *node)
{
	int	i; //To store the index of the current node
	int	median; //To store the position of the median of the stack

	i = 0; //The first index is `0`
	if (!node) //Check for am empty stack
		return ;
	median = stack_len(node) / 2; //Calculate the median by dividing the length of a stack by 2
	while (node) //Loop through all the nodes until the end of the stack is reached
	{
		node->index = i; //Assign the current index value to the current node
		if (i <= median) //Check whether the current node is above or below the median
			node->above_mediam = true; //If above, set the above_median data of the node to true
		else
			node->above_mediam = false; //If below, set the above_median data of the node to false
		node = node->next; //Move to the next node for indexing
		++i; //Increment the index value to set the next node with
	}


	// int		i;
	// int		median;

	// i = 0;
	// median = stack_len (node) / 2;
	// if(!node)
	// 	return ;
	// while (node)
	// {
	// 	node->index = i;
	// 	if (i <= median)
	// 		node->above_mediam = true;
	// 	if	(i > median)
	// 		node->above_mediam = false;
	// 	node = node->next;
	// 	i++;
	// }
}

static void	set_target_a(t_stack_node *node_a, t_stack_node *node_b)
{
	t_stack_node	*current_b; //To store the pointer to the current node in stack `b` and iterate through each node following
	t_stack_node	*target_node; //To store the pointer to the target node in stack `b`
	long			best_match_index; //In this case, the best match indexe stores the value of the "closest smaller number" so far

	while (node_a) //As long as we have nodes in stack `a`
	{
		best_match_index = LONG_MIN; //Assign the smallest `long` as the closest smaller number so far
		current_b = node_b; //Assign to `current_b` the current `b` node
		while (current_b) //Iteratively search through all the nodes in stack `b` until the end of the stack is reached
		{
			if (current_b->nbr < node_a->nbr 
				&& current_b->nbr > best_match_index) //Check if `b` node is smaller than `a` node && bigger than the closest smaller number so far
			{
				best_match_index = current_b->nbr; //If so, update the value of the closest smaller number so far
				target_node = current_b; //Assign the current `b` node as the `target_node`
			}
			current_b = current_b->next; //Move to the next `b` node for comparison, until a "closer smaller number" is found
		}
		if (best_match_index == LONG_MIN) //Check if the LONG_MIN hasn't changed, it means we haven't found anything smaller
			node_a->target_node = find_biggest_node(node_b); //If so, find the biggest `nbr` and set this as the target node
		else
			node_a->target_node = target_node; //If no "closer smaller number" is found, and the best match has changed
		node_a = node_a->next; //Move to the next `a` node to find it's target `b` node
	}


	// t_stack_node	*current_node_b;
	// t_stack_node	*target_node;
	// long		closest_smaller_number;

	// while (node_a)
	// {
	// 	closest_smaller_number = LONG_MIN;
	// 	current_node_b = node_b;
	// 	while (current_node_b)
	// 	{
	// 		if(node_a->nbr > current_node_b->nbr
	// 			&& current_node_b->nbr > closest_smaller_number)
	// 		{
	// 			closest_smaller_number = current_node_b->nbr;
	// 			target_node = current_node_b;
	// 		}
	// 		current_node_b = current_node_b->next;
	// 	}
	// 	if (closest_smaller_number == LONG_MIN)
	// 		node_a->target_node = find_biggest_node(node_b);
	// 	else
	// 		node_a->target_node = target_node;
	// 	node_a = node_a->next;
	// }
}

static void	find_cost_a(t_stack_node *a, t_stack_node *b)
{
	int		len_a;
	int		len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while(a)
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
	long	cheapest_value;
	t_stack_node	*cheapest_node;
	
	if(!node)
		return ;
	cheapest_value = LONG_MAX;
	while(node)
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