/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:39:44 by bde-souz          #+#    #+#             */
/*   Updated: 2024/02/28 17:48:50 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	sort_three(t_stack_node **stack)
{
	t_stack_node	*biggest_node;

	biggest_node = find_biggest_node(*stack);
	if (biggest_node == *stack)
		ra(stack, false);
	else if ((*stack)->next == biggest_node)
		rra(stack, false);
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(stack, false);
}