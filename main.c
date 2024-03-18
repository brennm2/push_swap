/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:56:56 by bde-souz          #+#    #+#             */
/*   Updated: 2024/03/18 16:07:33 by bde-souz         ###   ########.fr       */
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


static int	word_counter(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
		{
			i++;
		}
		if (s[i] != '\0')
		{
			counter++;
		}
		while (s[i] != c && s[i] != '\0')
		{
			i++;
		}
	}
	return (counter);
}

char	**ftt_split(char const *s, char c)
{
	char	**str_array;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	str_array = malloc(sizeof(char *) * (word_counter(s, c) + 1));
	if (!str_array)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
		{
			str_array[j] = ft_substr(s, i, string_size(s + i, c));
			j++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	str_array[j] = 0;
	return (str_array);
}




char	*ft_jointfree(char *str, char *buff)
{
	char	*tmp;

	tmp = ft_strjoin(str, buff);
	free(str);
	return (tmp);
}

char	*ftt_strdup(const char *s)
{
	char	*s_copy;
	int		i;

	s_copy = malloc(ft_strlen(s) + 1);
	i = 0;
	if (!s_copy)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		s_copy[i] = s[i];
		i++;
	}
	s_copy[i] = '\0';
	return (s_copy);
}

char	**preparestrings(int argc, char **argv)
{
	int		i;
	char	*number_str;
	char	**strs;

	number_str = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		number_str = ft_jointfree(number_str, argv[i]);
		number_str = ft_jointfree(number_str, " ");
		i++;
	}
	strs = ft_split(number_str, ' ');
	free(number_str);
	return (strs);
}
// int	check_syntax_begin(char *av)
// {
// 	int i;

// 	i = 0;
	
// 	while (av[i])
// 	{
// 		if (!(av[i] >= '0' && av[i] <= '9') || (av[i] == " " && av[i + 1] !))
// 			return (1);

// 	}
// }

int main(int ac, char **av)
{
	t_stack_node *a;
	t_stack_node *b;
	char	**strs;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && av[1][0] == '\0') || (av[1][0] == ' ' && av[1][1] == '\0'))
	{
		//ft_printf("Error\nProblem with syntax\n");
		free_error(&a);
		//return (0);
	}
	strs = preparestrings(ac, av);
	
	// if (ac == 1 || !strs[1])
	// {
	// 	free_av(ac, strs);
	// 	free_error(&a);
	// }
	init_stack_a(&a, strs, ac);
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
	free_av(ac, strs);




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
