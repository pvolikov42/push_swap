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

void	sip_approach(t_stackf *aa, t_stackf *bb)
//move all elements of stack aa to stack bb in descending order
// next element are looked for by rotating or revrotating aa
{
	int	i;
	int	j;
	int pos;
	int counter;
	int dir;

	counter = 0;
	i = aa->stk->size - 1;
	while (i >= 0)
	{
		pos = find_value(i, aa->idx->val, aa->idx->size);
		if (pos == -1)  
		{
			i--;  // only decrease after all equal entries are moved
			continue ;
		}
		dir = pos > (aa->stk->size - 2) / 2;
		while (aa->idx->val[aa->stk->size - 1] != i)
		{
			if (dir) 
				rot(aa);
			else
				rrot(aa);
			counter++;
			j++;
		}
		xpush(bb, aa);
		// xpush_stack(b, a);
		counter++;
	}
	//ft_putstr("Number of operations: ");
	//ft_putnbr(counter);
	//ft_putchar('\n');
}

void	rsip_approach(t_stackf *aa, t_stackf *bb)
// sips all elements
{
	int	i;
	int	j;
	int pos;
	int dir;
	int num;

	i = 0;
	num = aa->stk->size;
	while (i < num)
	{
		pos = find_value(i, aa->idx->val, aa->idx->size);
		if (pos == -1)  
		{
			i++;  // only change after all equal entries are processed
			continue ;
		}
		dir = pos > (aa->stk->size - 2) / 2;
		while (aa->idx->val[aa->stk->size - 1] != i)
		{
			if (dir) 
				rot(aa);
			else
				rrot(aa);
			j++;
		}
		xpush(bb, aa);
	}
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

void	find_solution2(t_stackf *aa, t_stackf *bb)
//not just a stub
{
	sip_approach(aa, bb);
	dump(bb, aa);
}

void	find_solution3(t_stackf *aa, t_stackf *bb)
{
	dump_second_half(aa, bb);
	ft_putendl("after dump_second_half");
	print_stk(aa);
	print_stk(bb);
	sip_approach(aa, bb);
	ft_putendl("after sip_approach(aa, bb)");
	print_stk(aa);
	print_stk(bb);
	rsip_approach(bb, aa);
	ft_putendl("after rsip_approach(bb, aa)");
	print_stk(aa);
	print_stk(bb);
	//dump(bb, aa);
}
/*
void	find_solution4(t_stackf *aa, t_stackf *bb)
{
}*/

int	input_vals(char **argv, t_stack *s)
//stub
{
	int	i;
	
	i = 0;
//	(void)argv;
	while (*argv)
	{
		//ft_putendl(*argv);
		s->val[i++] = ft_atoi(*argv);
		argv++;
	}
	s->size = i;
	return (i);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_stack	ai;
	t_stack	bi;
	t_stackf aa;
	t_stackf bb;

	if (argc < 2)
		return (ft_putstr("Error\n"), 1);
	init_stack(&a);
	init_stack(&b);
	init(&aa, &a, &ai);
	init(&bb, &b, &bi);
	if (! input_vals(++argv, &a))
		return (ft_putstr("Error\n"), 2);
	mkidx(&aa);
	ft_putendl("Start a:");
	print_stk(&aa);
	ft_putendl("Start b:");
	print_stk(&bb);
//	find_solution(&a, &b);
//	find_solution2(&aa, &bb);
	find_solution3(&aa, &bb);
/*    mkidx(&aa);
	print_stk(&aa);
	print_stk(&bb);
	rrot(&aa);
	xpush(&bb, &aa);
	xpush(&bb, &aa);
	rot(&aa);
	print_stk(&aa);
	rot(&aa); */
	ft_putendl("Finish a:");
	print_stk(&aa);
	ft_putendl("Finish b: ");
	print_stk(&bb);
	return (0);
}
