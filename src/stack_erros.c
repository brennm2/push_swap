/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_erros.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:39:47 by bde-souz          #+#    #+#             */
/*   Updated: 2024/02/27 13:40:09 by bde-souz         ###   ########.fr       */
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
	if (!(*av == '-' || *av == '+' || (*av >= '0' && *av <= '9')))
		return (1);
	if ((*av == '-' || *av == '+') && (!(av[1] >= '0' || av[1] <= '9')))
		return (1);
	while (*++av)
	{
		if (!(*av >= '0' && *av <= '9'))
			return (1);
	}
	return (0);
}

void free_stack(t_stack_node **stack)
{
	t_stack_node *next_node;
	t_stack_node *node;

	if(!stack)
		return ;
	node = *stack;
	while (node)
	{
		next_node = node->next;
		node->nbr = 0;
		free(node);
		node = next_node;
	}
	*stack = NULL;
}

void free_error(t_stack_node **stack)
{
	free_stack(stack);
	ft_printf("Error\nProblem with syntax!!!!!\n");
	exit(1);
}