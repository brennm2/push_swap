/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:54:20 by bde-souz          #+#    #+#             */
/*   Updated: 2024/03/04 20:54:30 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_stack_node	*find_last_node(t_stack_node *node)
{
	if (!node)
		return (NULL);
	while (node->next) //Loop until the end of the stack is reached
		node = node->next;
	return (node);

	// if (!node)
	// 	return (NULL);
	// while (node->next)
	// 	node = node->next;
	// return (node);
}

int	stack_len (t_stack_node *node)
{
	int	count; //To store the node count

	if (!node) 
		return (0);
	count = 0;
	while (node) //Loop until the end of the stack is reached
	{
		node = node->next; //Move to the next node
		count++;
	}
	return (count);
}

bool	check_stack_sorted (t_stack_node *stack)
{
	if (!stack)
		return (1);
	while(stack->next)
	{
		if(stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}


t_stack_node	*find_biggest_node(t_stack_node *node)
{
	long			max; //To store the biggest value so far
	t_stack_node	*max_node; //To store a pointer that points to the biggest number

	if (!node)
		return (NULL);
	max = LONG_MIN; //Assign to the biggest value so far, the max long integer
	while (node) //Loop until the end of the stack is reached
	{
		if (node->nbr > max) //Check if the current node value is smaller than the biggest so far
		{
			max = node->nbr; //If so, update the biggest number so far
			max_node = node; //Set the pointer to point to the node with the biggest number so far
		}
		node = node->next; //Move to the next node for processing
	}
	return (max_node);

	// long	biggest;
	// t_stack_node	*biggest_node;

	// if(!node)
	// 	return (NULL);
	// biggest = LONG_MIN;
	// while(node)
	// {
	// 	if (node->nbr > biggest)
	// 	{
	// 		biggest = node->nbr;
	// 		biggest_node = node;
	// 	}
	// 	node = node->next;
	// }
	// return (biggest_node);
}
