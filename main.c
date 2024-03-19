/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:56:56 by bde-souz          #+#    #+#             */
/*   Updated: 2024/03/19 16:32:52 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/push_swap.h"

void free_av(int ac, char **av)
{
	int	i;

	i = 0;
	//if (ac == 2)
	//{
		while (av[i])
		{
			free (av[i]);
			i++;
		}
		free(av);
	//}
}
static int	string_size(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}


// static int	word_counter(char const *s, char c)
// {
// 	int	i;
// 	int	counter;

// 	i = 0;
// 	counter = 0;
// 	while (s[i] != '\0')
// 	{
// 		while (s[i] == c && s[i] != '\0')
// 		{
// 			i++;
// 		}
// 		if (s[i] != '\0')
// 		{
// 			counter++;
// 		}
// 		while (s[i] != c && s[i] != '\0')
// 		{
// 			i++;
// 		}
// 	}
// 	return (counter);
// }


// char	*ft_jointfree(char *str, char *buff)
// {
// 	char	*tmp;

// 	tmp = ft_strjoin(str, buff);
// 	free(str);
// 	return (tmp);
// }


// char	**preparestrings(int argc, char **argv)
// {
// 	int		i;
// 	char	*number_str;
// 	char	**strs;

// 	number_str = ft_strdup("");
// 	i = 1;
// 	while (i < argc)
// 	{
// 		number_str = ft_jointfree(number_str, argv[i]);
// 		number_str = ft_jointfree(number_str, " ");
// 		i++;
// 	}
// 	strs = ft_split(number_str, ' ');
// 	free(number_str);
// 	return (strs);
// }

char *clean_join(char *temp_string, char *buff)
{
	char	*tmp;

	tmp = ft_strjoin(temp_string, buff);
	free(temp_string);
	return(tmp);
}

char	**init_strig(int ac, char **av)
{
	int	i;
	char **string;
	char *temp_string;

	i = 1;
	temp_string = ft_strdup("");
	while(ac > i)
	{
		temp_string = clean_join(temp_string, av[i]);
		temp_string = clean_join(temp_string, " ");
		i++;
	}
	string = ft_split(temp_string, ' ');
	free(temp_string);
	return(string);
}

int main(int ac, char **av)
{
	t_stack_node *a;
	t_stack_node *b;
	char	**string;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && av[1][0] == '\0') 
		|| (av[1][0] == ' ' && av[1][1] == '\0'))
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




	// t_stack_node *a;
	// t_stack_node *b;
	// //char	**strs;

	// a = NULL;
	// b = NULL;

	// if (ac == 1 || (ac == 2 && !av[1][0]))
	// 	free_error(&a);
	// // else if (ac == 2 && av[1] && av[2] == NULL || av)
	// // 	free_error(&a);
	// else if (ac == 2)
	// {
	// 	av = ft_split(av[1], ' ');
	// 	//init_stack_a(&a, av, ac);
	// }
	// // else
	// // 	init_stack_a(&a, av + 1, ac);
	// init_stack_a(&a, av + 1, ac);
	// if (!check_stack_sorted(a))
	// {
	// 	if (stack_len(a) == 2)
	// 		sa(&a, false);
	// 	else if (stack_len(a) == 3)
	// 		sort_three(&a);
	// 	else
	// 		organize_stacks(&a, &b);
	// }
	// free_stack(&a);
	// free_av(ac, av);
}
