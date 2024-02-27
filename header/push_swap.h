/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:11:13 by bde-souz          #+#    #+#             */
/*   Updated: 2024/02/27 17:12:16 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libs/Libft/libft.h"
#include <stdbool.h>
#include <limits.h>

typedef struct s_stack_node
{
	int	nbr;
	int	index;
	int	push_cost;
	bool above_mediam;
	bool cheapest;
	struct s_stack_node *target_node;
	struct s_stack_node *next;
	struct s_stack_node *prev;

} t_stack_node;

//	SRC/STACK_UNIT.C
void init_stack_a(t_stack_node **a, char **av);

//	SRC/STACK_UTILS.C
t_stack_node	*find_last_node(t_stack_node *node);
bool	check_stack_sorted (t_stack_node *stack);
int	stack_len (t_stack_node *node);
t_stack_node	*find_biggest_node(t_stack_node *node);



//	SRC/STACK_ERROS.C
int check_syntax_error(char *av);
int check_duplicates(t_stack_node *a, int n);
void free_stack(t_stack_node **stack);
void free_error(t_stack_node **stack);

//	SRC/COMMANDS/SORT_THREE.C
void	sort_three(t_stack_node **stack);


#endif