/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvolikov <pvolikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 20:17:33 by pvolikov          #+#    #+#             */
/*   Updated: 2025/08/04 20:19:29 by pvolikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"
#define STACK_LEN 1000

typedef struct s_stack
//an array where the first element is the bottom of the stack
{
	int	val[STACK_LEN];
	// int top;
	int	size;
}	t_stack;


int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	
	if (argc < 2)
		return ( ft_putstr("Error\n"), 1);
	if (! input_vals(argv, &a))
		return ( ft_putstr("Error\n"), 2);
	find_solution(&a, &b);
	return (0);
}
