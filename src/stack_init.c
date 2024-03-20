/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:54:16 by bde-souz          #+#    #+#             */
/*   Updated: 2024/03/20 15:22:21 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_stack_node	*get_cheapest(t_stack_node *node)
{
	if (!node)
		return (NULL);
	while (node)
	{
		if (node->cheapest)
			return (node);
		node = node->next;
	}
	return (NULL);
}

static void	put_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->cheapest = NULL;
	node->nbr = n;
	node->next = NULL;
	if (!(*stack))
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

void	set_the_top(t_stack_node **stack, t_stack_node *top_node,
	char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_mediam == true)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_mediam == true)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

void	init_stack_a(t_stack_node **a, char **av, int ac)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		if (check_syntax_error(av[i]))
		{
			free_av(ac, av);
			free_error(a);
		}
		n = ft_atoi(av[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			free_av(ac, av);
			free_error(a);
		}
		if (check_duplicates(*a, (int)n))
		{
			free_av(ac, av);
			free_error(a);
		}
		put_node(a, (int)n);
		i++;
	}
}
