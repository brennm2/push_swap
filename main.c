/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:56:56 by bde-souz          #+#    #+#             */
/*   Updated: 2024/03/20 15:52:03 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/push_swap.h"

bool	number_validator(char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
	{
		if (av[1][i] >= '0' && av[1][i] <= '9')
			return (true);
		i++;
	}
	return (false);
}

void	free_av(int ac, char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free (av[i]);
		i++;
	}
	free(av);
}

char	*clean_join(char *temp_string, char *buff)
{
	char	*tmp;

	tmp = ft_strjoin(temp_string, buff);
	free(temp_string);
	return (tmp);
}

char	**init_strig(int ac, char **av)
{
	int		i;
	char	**string;
	char	*temp_string;

	i = 1;
	temp_string = ft_strdup("");
	while (ac > i)
	{
		temp_string = clean_join(temp_string, av[i]);
		temp_string = clean_join(temp_string, " ");
		i++;
	}
	string = ft_split(temp_string, ' ');
	free(temp_string);
	return (string);
}

int	main(int ac, char **av)
{
	t_stack_node		*a;
	t_stack_node		*b;
	char				**string;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	if ((ac == 2 && av[1][0] == '\0')
		|| (number_validator(av) == false))
		free_error(&a);
	string = init_strig(ac, av);
	init_stack_a(&a, string, ac);
	if (!check_stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			organize_stacks(&a, &b);
	}
	free_stack(&a);
	free_av(ac, string);
}
