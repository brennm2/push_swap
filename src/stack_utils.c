/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:54:20 by bde-souz          #+#    #+#             */
/*   Updated: 2024/02/21 18:06:26 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"


int	check_syntax_error(char *av)
{
	int	i;

	i = 0;
	ft_printf("ded0\n");
	if (!(av[i] == '-' || av[i] == '+' || (av[i] >= '0' && av[i] <= '9')))
	{
		ft_printf("ded1\n");
		return (1);
	}
	ft_printf("ded0\n");
	if ((av[i] == '-' || av[i] == '+') 
		|| (!(av[i + 1] >= '0' || av[i + 1] <= '9')))
	{
		ft_printf("ded2\n");
		return (1);
	}
	ft_printf("dedaaa\n");

	while (av[i] >= '0' || av[i] <= '9')
	{
		if (!(av[i] >= '0' || av[i] <= '9'))
		{
			ft_printf("ded3\n");
			return (1);
		}
		i++;
	}
	return (0);
}