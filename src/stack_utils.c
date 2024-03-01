/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:54:20 by bde-souz          #+#    #+#             */
/*   Updated: 2024/03/01 14:12:55 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_stack_node	*find_last_node(t_stack_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

int	stack_len (t_stack_node *node)
{
	int	len;

	len = 0;
	if (!node)
		return (0);
	while(node)
	{
		len++;
		node = node->next;
	}
	return (len);
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
	long	biggest;
	t_stack_node	*biggest_node;

	if(!node)
		return (NULL);
	biggest = LONG_MIN;
	while(node)
	{
		if (node->nbr > biggest)
		{
			biggest = node->nbr;
			biggest_node = node;
		}
		node = node->next;
	}
	return (biggest_node);
}
