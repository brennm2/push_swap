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
	if (!check_stack_sorted(a))
	{
		ft_printf("dead!\n");
		if (stack_len(a) == 2)
			ft_printf("USING 'SA'\n");
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			ft_printf("SORT stack!\n");
	}
	free_stack(&a);
}
