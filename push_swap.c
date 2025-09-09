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

void	find_solution(t_stack *a, t_stack *b)
//not just a stub
{
	int		i;
	t_stack	ai;
	//t_stack	bi;
	//t_stack	t;
	
	copy_stack(b, a);
	bubble_rsort(b->val, b->size);
	i = 0;
	while (i < a->size)
	{
		ai.val[i] = find_value(a->val[i], b->val, a->size);
		i++;
	}
	ai.size = i;
	ft_putstr("a indexed: ");
	print_stack(&ai);
	init_stack(b);
	xpush_stack(b, a);
	rot_stack(a);
	rot_stack(a);
//	xpush_stack(b, a);
//	sip_approach(a, b, &ai);
	ft_putendl("\nrr\nrrr");
}

void	sip_approach(t_stack *a, t_stack *b, t_stack *ai)
{
	int	i;
	int	j;
	int	num;
	int pos;
	int counter;

	counter = 0;
	i = 0;
	num = a->size;
	while (i < num - 1)
	{
		pos = find_value(i, ai->val, ai->size);
		j = 0;
		if (pos > a->size / 2)  //-2
			while (j < a->size - pos)
			{
				rot_stack(a);
				rot_stack(ai);
				counter++;
				j++;
			}
		else
			while (j < pos)
			{
				rrot_stack(a);
				rrot_stack(ai);
				counter++;
				j++;
			}
		xpush_stack(b, a);
		counter++;
		i++;
	}
	ft_putnbr(counter);
}

int	input_vals(char **argv, t_stack *s)
//stub
{
	(void)argv;
	s->size = 6;
	s->val[0] = 1;
	s->val[1] = 111;
	s->val[2] = 22;
	s->val[3] = 24;
	s->val[4] = 27;
	s->val[5] = 29;
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
//	t_stackf aa;
//	t_stackf bb;

	if (argc < 2)
		return (ft_putstr("Error\n"), 1);
	init_stack(&a);
	init_stack(&b);
	if (! input_vals(argv, &a))
		return (ft_putstr("Error\n"), 2);
	ft_putendl("Start");
	ft_putstr("a: ");
	print_stack(&a);
	ft_putchar('\n');
	ft_putstr("b: ");
	print_stack(&b);
	ft_putchar('\n');
	find_solution(&a, &b);
	ft_putendl("Finish");
	ft_putstr("a: ");
	print_stack(&a);
	ft_putchar('\n');
	ft_putstr("b: ");
	print_stack(&b);
	ft_putchar('\n');
	return (0);
}
