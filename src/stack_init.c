/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:54:16 by bde-souz          #+#    #+#             */
/*   Updated: 2024/03/01 18:15:12 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_stack_node	*get_cheapest(t_stack_node *node)
{
	if (!node)
		return (NULL);
	while (node)
	{
		if (node->cheapest == true)
			return (node);
		node = node->next;
	}
	return (NULL);
}

static void	put_node(t_stack_node **stack, int n)
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
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void init_stack_a(t_stack_node **a, char **av)
{
	long n;
	int i;

	i = 0;
	while (av[i])
	{
		if (check_syntax_error(av[i]))
			free_error(a);
		n = ft_atoi(av[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			ft_printf("Error\nYour number is too big or too small!\n");
			free_error(a);
		}
		if (check_duplicates(*a, (int)n))
		{
			ft_printf("Error\nYou have a duplicated number\n");
			free_error(a);
		}
		put_node(a, (int)n);
		i++;
	}
}
