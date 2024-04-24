/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:11:13 by bde-souz          #+#    #+#             */
/*   Updated: 2024/03/20 15:12:54 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/Libft/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_mediam;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

//	SRC/STACK_UNIT.C
t_stack_node	*get_cheapest(t_stack_node *node);
void			init_stack_a(t_stack_node **a, char **av, int ac);
void			set_the_top(t_stack_node **stack, t_stack_node *top_node,
					char stack_name);

//	SRC/STACK_UTILS.C
t_stack_node	*find_last_node(t_stack_node *node);
t_stack_node	*find_biggest_node(t_stack_node *node);
int				stack_len(t_stack_node *node);
bool			check_stack_sorted(t_stack_node *stack);

//	SRC/COMPILE_STACK_A.C
void			compile_stack_a(t_stack_node *a, t_stack_node *b);
void			find_cheapest(t_stack_node *node);
void			set_index(t_stack_node *node);

//	SRC/COMPILE_STACK_B.C
t_stack_node	*find_smallest_node(t_stack_node *node);
void			compile_stack_b(t_stack_node *a, t_stack_node *b);

//	SRC/STACK_ERROS.C
int				check_syntax_error(char *av);
int				check_duplicates(t_stack_node *a, int n);
void			free_stack(t_stack_node **stack);
void			free_error(t_stack_node **stack);

//	SRC/COMMANDS/SORT_THREE.C
void			sort_three(t_stack_node **stack);

//	SRC/COMMANDS/ROTATE.C
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);

//	SRC/COMMANDS/REVERSE_ROTATE.C
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);

//	SRC/COMMANDS/SWAP.C
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);

//	SRC/COMMANDS/PUSH.C
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **a, t_stack_node **b, bool print);

//	SRC/COMMANDS/ORGANIZE_STACKS.C
void			organize_stacks(t_stack_node **a, t_stack_node **b);
void			free_av(int ac, char **av);

#endif