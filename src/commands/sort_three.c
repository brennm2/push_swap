/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:39:44 by bde-souz          #+#    #+#             */
/*   Updated: 2024/02/27 17:16:12 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	sort_three(t_stack_node **stack)
{
	t_stack_node	*biggest_node;

	biggest_node = find_biggest_node(*stack);
	if (biggest_node == *stack)
		ft_printf("ra - put TOP to BOTTOM\n");
	else if ((*stack)->next == biggest_node)
		ft_printf("rra - put BOTTOM to TOP\n");
	if ((*stack)->nbr > (*stack)->next->nbr)
		ft_printf("sa - rotate FIRST and SECOND\n");
}