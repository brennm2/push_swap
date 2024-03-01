/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:33:22 by bde-souz          #+#    #+#             */
/*   Updated: 2024/03/01 15:55:47 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static void		push(t_stack_node **top_dst, t_stack_node **top_src)
{
	t_stack_node	*top_node;

	if(!top_src)
		return ;
	top_node = *top_src;
	

	*top_src = (*top_src)->next;
	if (*top_src)
		(*top_src)->prev = NULL;
	top_node->prev = NULL;
	if (!(*top_dst))
	{
		*top_dst = top_node;
		top_node->next = NULL;
	}
	else
	{
		top_node->next = *top_dst;
		//(*top_dst)->prev = top_node; // ------
		top_node->next->prev = top_node; // -----
		*top_dst = top_node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if(!print)
		ft_printf("pa\n");
}

void	pb(t_stack_node **a, t_stack_node **b, bool print)
{
	push(b, a);
	if(!print)
		ft_printf("pb\n");
}