/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:54:16 by bde-souz          #+#    #+#             */
/*   Updated: 2024/02/21 18:05:04 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"


void	init_stack_a(t_stack_node **a, char **av)
{
	long	n;
	int		i;

	i = 0;
	while(av[i])
	{
		if(check_syntax_error(av[i]));
			ft_printf("ded, syntax\n"); //clean
		n = ft_atoi(av[i]);
		
		if (n > INT_MAX || n < INT_MIN)
			ft_printf("ded, int max ou int min\n"); // clean
		printf("atoi: %ld\n", n);
		i++;
	}
}