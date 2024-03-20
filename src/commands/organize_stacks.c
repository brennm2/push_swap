/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:25:04 by bde-souz          #+#    #+#             */
/*   Updated: 2024/03/20 15:25:07 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static void	rotate_a_and_b(t_stack_node **top_a, t_stack_node **top_b,
	t_stack_node *cheapest_node)
{
	while (*top_b != cheapest_node->target_node && *top_a != cheapest_node)
		rr(top_a, top_b, false);
	set_index(*top_a);
	set_index(*top_b);
}

static void	rev_rotate_a_and_b(t_stack_node **top_a, t_stack_node **top_b,
	t_stack_node *cheapest_node)
{
	while (*top_b != cheapest_node->target_node && *top_a != cheapest_node)
		rrr(top_a, top_b, false);
	set_index(*top_a);
	set_index(*top_b);
}

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_mediam
			&& cheapest_node->target_node->above_mediam)
		rotate_a_and_b(a, b, cheapest_node);
	else if (!(cheapest_node->above_mediam)
 			&& !(cheapest_node->target_node->above_mediam))
		rev_rotate_a_and_b(a, b, cheapest_node);
	set_the_top(a, cheapest_node, 'a');
	set_the_top(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
}


static void	set_min_to_top(t_stack_node **a)
{
	t_stack_node	*smallest_number;

	smallest_number = find_smallest_node (*a);
	while ((*a)->nbr != smallest_number->nbr)
	{
		if (smallest_number->above_mediam == true)
			ra(a, false);
		else
			rra(a, false);
	}
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	set_the_top (a, (*b)->target_node, 'a');
	pa(a, b, false);
}

void	organize_stacks(t_stack_node **a, t_stack_node **b)
{
	int		len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !check_stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !check_stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !check_stack_sorted(*a))
	{
		compile_stack_a(*a , *b);
		move_a_to_b (a, b);
	}
	sort_three(a);
	while (*b)
	{
		compile_stack_b(*a, *b);
		move_b_to_a(a, b);
	}
	set_index(*a);
	set_min_to_top(a);
}
