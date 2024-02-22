/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:54:20 by bde-souz          #+#    #+#             */
/*   Updated: 2024/02/22 17:04:11 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int check_duplicates(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

int check_syntax_error(char *av)
{
	int i;

	i = 0;
	if (!(av[i] == '-' || av[i] == '+' || (av[i] >= '0' && av[i] <= '9')))
		return (1);
	if ((av[i] == '-' || av[i] == '+') && (!(av[i + 1] >= '0' || av[i + 1] <= '9')))
		return (1);
	while (av[++i])
	{
		if (!(av[i] >= '0' && av[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}
// #TODO Finish put_node
static void	put_node (t_stack_node **stack, int n)
{
	t_stack_node *node;
	t_stack_node *last_node;
	
	if(!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if(!node)
		return ;
	node->nbr = n;
	node->next = NULL;
	if(!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		
	}
}
