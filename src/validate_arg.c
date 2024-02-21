#include "../header/push_swap.h"

int	validate_arg (int ac)
{
	if (ac < 2)
	{
		ft_printf("You have too few arguments\n");
		return (1);
	}
	else 
		ft_printf("Its ok!\n");
	return (0);
}