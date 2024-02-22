/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:11:13 by bde-souz          #+#    #+#             */
/*   Updated: 2024/02/22 17:04:12 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libs/Libft/libft.h"
#include <stdbool.h>
#include <limits.h>

typedef struct s_stack_node
{
	int nbr;
	int index;
	bool above_mediam;
	bool cheapest;
	struct s_stack_node *target_node;
	struct s_stack_node *next;
	struct s_stack_node *prev;

} t_stack_node;

//	SRC/STACK_UNIT.C
void init_stack_a(t_stack_node **a, char **av);

//	SRC/STACK_UTILS.C
int check_syntax_error(char *av);
int check_duplicates(t_stack_node *a, int n);

int validate_arg(int ac);
#endif