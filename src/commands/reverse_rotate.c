/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:18:36 by bde-souz          #+#    #+#             */
/*   Updated: 2024/02/28 17:52:40 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	//#TODO Verificar se isso esta certo
	t_stack_node *last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last_node(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void	rra (t_stack_node **a, bool print)
{
	reverse_rotate(a);
	if(!print)
		ft_printf("rra\n");
}

void	rrb (t_stack_node **b, bool print)
{
	reverse_rotate(b);
	if(!print)
		ft_printf("rrb\n");
}

void	rrr (t_stack_node **a, t_stack_node **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if(!print)
		ft_printf("rrr\n");
}