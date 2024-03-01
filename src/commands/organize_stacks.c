/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:25:04 by bde-souz          #+#    #+#             */
/*   Updated: 2024/03/01 18:15:45 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *cheapest_node;

	cheapest_node = get_cheapest(*a);
}


void	organize_stacks (t_stack_node **a, t_stack_node **b)
{
	int		len_a;
	len_a = stack_len(*a);
	if (len_a-- > 3 && !check_stack_sorted(*a))
		pb(a, b, false);
	if (len_a-- > 3 && !check_stack_sorted(*a))
		pb(a, b, false);
	while (len_a-- > 3 && !check_stack_sorted(*a))
	{
		compile_stack_a(*a , *b);
		move_a_to_b (a, b);
	}

}