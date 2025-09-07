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
#include "push_swap.h"

void	init_stack(t_stack *s)
{
	s->size = 0;
}

void	find_solution(t_stack *s1, t_stack *s2)
//just a stub
{
	ft_putendl("rr\nrrr");
}

int	input_vals(char **argv, t_stack *s)
//stub
{
	s->size = 3;
	s->val[0] = 1;
	s->val[1] = 111;
	s->val[2] = 22;
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (ft_putstr("Error\n"), 1);
	init_stack(&a);
	init_stack(&b);
	if (! input_vals(argv, &a))
		return (ft_putstr("Error\n"), 2);
	ft_putendl("Start");
	ft_putstr("a: ");
	print_stack(a);
	ft_putchar('\n');
	ft_putstr("b: ");
	print_stack(b);
	ft_putchar('\n');
	find_solution(&a, &b);
	ft_putendl("Finish");
	ft_putstr("a: ");
	print_stack(a);
	ft_putchar('\n');
	ft_putstr("b: ");
	print_stack(b);
	ft_putchar('\n');
	return (0);
}
