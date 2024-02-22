/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:54:16 by bde-souz          #+#    #+#             */
/*   Updated: 2024/02/22 16:05:41 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void init_stack_a(t_stack_node **a, char **av)
{
	long n;
	int i;

	i = 0;
	while (av[i])
	{
		if (check_syntax_error(av[i]))
		{
			ft_printf("Error\nProblem with syntax!\n");
			// clean
		}
		n = ft_atoi(av[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			ft_printf("Error\nYour number is too big or too small!\n");
			// clean
		}
		if (check_duplicates(*a, (int)n))
		{
			ft_printf("Error\nYou have a duplicated number\n");
			// clean
		}
		printf("atoi: %ld\n", n);
		i++;
	}
}