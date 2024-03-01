/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:56:56 by bde-souz          #+#    #+#             */
/*   Updated: 2024/03/01 16:52:46 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/push_swap.h"

int main(int ac, char **av)
{
	t_stack_node *a;
	t_stack_node *b;

	a = NULL;
	b = NULL;

	if (ac == 1 || (ac == 2 && !av[1][0]))
	{
		ft_printf("Error\nProblem with arguments\n");
		return (1);
	}
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		init_stack_a(&a, av);
	}
	else
		init_stack_a(&a, av + 1);

	//#TODO INICAR A ORGANIZAÇÃO DOS NODES
	//#TODO RETIRAR PRINTF
	//#TODO ORGANIZAR AS STACKS
	if (!check_stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			organize_stacks(&a, &b);
	}
	// DELETE
	ft_printf("\n\nstack A: ");
	while (a)
	{
		ft_printf("%d ", a->nbr);
		a = a->next;
	}
	ft_printf("\n\nstack B: ");
	while (b)
	{
		ft_printf("%d ", b->nbr);
		b = b->next;
	}
	ft_printf("\n\n");
	//DELETE
	free_stack(&a);
}
