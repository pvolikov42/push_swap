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
#include <stdlib.h>
#include "utils.h"
#include "libft/libft.h"
#include "push_swap.h"

void	sip_approach(t_stackf *aa, t_stackf *bb)
//move all elements of stack aa to stack bb in backward order
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

int	sip_range(t_stackf *aa, t_stackf *bb, int min, int max)
//move elements of stack aa to stack bb in backward order
// next element are looked for by rotating or revrotating aa
// indexes are in range [min, max] (inclusively)
// returns the number of sipped (xpushed) elements
{
	int	i;
	int pos;
	int counter;
	int dir;

	counter = 0;
	i = max;
	while (i >= min)
	{
		pos = find_value(i, aa->idx->val, aa->idx->size);
		if (pos == -1)
		{
			i--;  // only decrease after all equal entries are moved
			continue ;
		}
		dir = pos > (size_stk(aa) - 2) / 2;
		while (aa->idx->val[size_stk(aa) - 1] != i)
			if (dir) 
				rot(aa);
			else
				rrot(aa);
		xpush(bb, aa);
		counter++;
	}
	//ft_putstr("Number of operations: ");
	//ft_putnbr(counter);
	//ft_putchar('\n');
	return (counter);
}

void	rsip_approach(t_stackf *aa, t_stackf *bb)
// sips all elements in first-to-last order
{
	int	i;
	int pos;
	int dir;
	int num;

	i = 0;
	num = aa->stk->size + bb->stk->size;
	while (i < num && aa->stk->size)
	{
		pos = find_value(i, aa->idx->val, aa->idx->size);
		if (pos == -1)  
		{
			i++;  // only change after all equal entries are processed
			continue ;
		}
		dir = pos > (aa->stk->size - 2) / 2;
		while (aa->idx->val[aa->stk->size - 1] != i)
			if (dir) 
				rot(aa);
			else
				rrot(aa);
		xpush(bb, aa);
	}
}

void	rsip_level(t_stackf *aa, t_stackf *bb, int thr)
// sips all elements increasing level/index until the threshold
{
	int	i;
	int pos;
	int dir;

	i = 0;
	while (i < thr && aa->stk->size)
	{
		pos = find_value(i, aa->idx->val, aa->idx->size);
		if (pos == -1)  
		{
			i++;  // only change after all equal entries are processed
			continue ;
		}
		dir = pos > (aa->stk->size - 2) / 2;
		while (aa->idx->val[aa->stk->size - 1] != i)
			if (dir) 
				rot(aa);
			else
				rrot(aa);
		xpush(bb, aa);
	}
}

int	rsip_range(t_stackf *aa, t_stackf *bb, int min, int max)
// sips all elements in first-to-last order 
// index is in range [min, max] inclusively
{
	int	i;
	int pos;
	int dir;
	int	counter;

	counter = 0;
	i = min;
	while (i <= max && aa->stk->size)
	{
		pos = find_value(i, aa->idx->val, aa->idx->size);
		if (pos == -1)  
		{
			i++;  // only change after all equal entries are processed
			continue ;
		}
		dir = pos > (aa->stk->size - 2) / 2;
		while (aa->idx->val[aa->stk->size - 1] != i)
			if (dir) 
				rot(aa);
			else
				rrot(aa);
		xpush(bb, aa);
		counter++;
	}
	return (counter);
}

int	divide_n_sip(t_stackf *aa, t_stackf *bb, int min, int max)
// aa is sorted
// bb is unsorted but the upper chunk contains all values 
// above min and below max
{
	long int	chunk;
	int			thr;
	int			num;
	int			workleft;

	ft_putstr("_sip_nn: min="); ft_putnbr(min);
	ft_putstr(" max="); ft_putnbr(max); ft_putstr("\n");
	print_stk(aa);
	print_stk(bb);
	chunk = max - min + 1;
	if (chunk <= OPTIMUM)
	{
		ft_putendl("_nn: OPTIMUM branch");
		rsip_range(bb, aa, min, max);
	}
	if (chunk > OPTIMUM) 
	{
		ft_putendl("_nn: non-OPTIMUM branch");
		thr = min + chunk / 2;
		num = range_len(bb, min, max); //chunk volume
		workleft = size_stk(bb) - num; //unsorted volume
		ft_putstr("_params: num="); ft_putnbr(num);
		ft_putstr(" workleft="); ft_putnbr(workleft); 
		ft_putstr(" thr="); ft_putnbr(thr); 
		ft_putstr("\n");
		num = num - ndump_lower(bb, aa, thr + 1, num); //remaining volume
		divide_n_sip_lr(aa, bb, min, thr);
		if (num < workleft) 
			mrrot(bb, num);
		else
			mrot(bb, workleft);
		divide_n_sip(aa, bb, thr + 1, max);
	}	
	return (1);
}

int	divide_n_sip_lr(t_stackf *aa, t_stackf *bb, int min, int max)
// aa is sorted until min and has a chunk of unsorted 
// from min to max
// bb is unsorted but all above max
{
	long int	chunk;
	int			thr;
	int			num;
	int			workdone;

	ft_putstr("_sip_lr: min="); ft_putnbr(min);
	ft_putstr(" max="); ft_putnbr(max); ft_putstr("\n");
	print_stk(aa);
	print_stk(bb);
	chunk = max - min + 1;
	if (chunk <= OPTIMUM)
	{
		ft_putendl("_lr: OPTIMUM branch");
		num = sip_range(aa, bb, min, max);
		ndump(bb, aa, num);
	}
	if (chunk > OPTIMUM) 
	{
		ft_putendl("_lr: non-OPTIMUM branch");
		thr = min + chunk / 2;
		num = range_len(aa, min, max); //chunk volume
		workdone = size_stk(aa) - num; //sorted volume
		ft_putstr("_params: num="); ft_putnbr(num);
		ft_putstr(" workdone="); ft_putnbr(workdone); 
		ft_putstr(" thr="); ft_putnbr(thr); 
		ft_putstr("\n");
		num = num - ndump_higher(aa, bb, thr, num); //remaining volume
		if (num < workdone) 
			mrrot(aa, num);
		else
			mrot(aa, workdone);
		divide_n_sip_lr(aa, bb, min, thr);
		divide_n_sip(aa, bb, thr + 1, max);
	}	
	return (1);
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

void	find_solution4(t_stackf *aa, t_stackf *bb)
{
	int	thr;

	thr = (aa->stk->size - 1) / 4; 
	dump_higher(aa, bb, 3 * thr);
	dump_higher(aa, bb, 2 * thr);
	dump_higher(aa, bb, thr);
	ft_putendl("after 3 dumps");
	print_stk(aa);
	print_stk(bb);
	sip_approach(aa, bb);
	rsip_approach(bb, aa);
}

void	find_solution6(t_stackf *aa, t_stackf *bb)
{
	int	thr;
	int	num;

	thr = (aa->stk->size - 1) / 2; 
	dump_higher(aa, bb, thr);
	err("1\n");
	dump_higher(aa, bb, thr / 2);
	err("2\n");
	dump(aa, bb);
	ft_putendl("after dumps");
	print_stk(aa);
	print_stk(bb);
	rsip_level(bb, aa, thr);
	err("3\n");
	num = dump_lower(bb, aa, 3 * thr / 2);
	err("4\n");
	ndump(aa, bb, num);
	err("5\n");
	rsip_approach(bb, aa);
}

void	find_solution8(t_stackf *aa, t_stackf *bb)
{
	int	thr;
	int	num;
	int	i;

	num = 10;
	thr = (aa->stk->size - 1) / num; 
	i = num - 1; 
	while (i > 0)
	{
		dump_higher(aa, bb, i * thr);
		i--;
	}
	ft_putendl("after all dumps");
	print_stk(aa);
	print_stk(bb);
	sip_approach(aa, bb);
	rsip_approach(bb, aa);
}

void	find_solution9(t_stackf *aa, t_stackf *bb)
{
	int thr;

	thr = size_stk(aa) + size_stk(bb);
	divide_n_sip_lr(aa, bb, 0, thr);
}

void	find_solution5(t_stackf *aa, t_stackf *bb)
//ironing approach
{
	int	i;
	int	j;
	int	num;

	dump_second_half(aa, bb);
	ft_putstr("start score: ");
	ft_putnbr(wrongdir_rank(aa, bb));
	ft_putendl("");
	if (aa->stk->size > bb->stk->size) 
		num = aa->stk->size - 1;
	else
		num = bb->stk->size - 1;
	j = 0;
	while (j < num / 2 && wrongdir_rank(aa, bb) != 0)
	{
		i = 2 * num - j;
		while (i > j + 1) // 
		{
			if (i > num)
				rot2(aa, bb);
			else
				rrot2(aa, bb);
			if ((peek(aa) > peek2(aa)) & (peek(bb) < peek2(bb)))
				swap2(aa, bb);
			else if (peek(aa) > peek2(aa))
				swap(aa);
			else if (peek(bb) < peek2(bb))
				swap(bb);
			i--;
			ft_putendl("after a round");
			print_stk(aa);
			print_stk(bb);
		}
		j += 2;
		ft_putstr("intermediate score: ");
		ft_putnbr(wrongdir_rank(aa, bb));
		ft_putendl("");
	}
	ft_putstr("testing goto_neareast ");
	print_stk(aa);
	ft_putnbr(dist_to_brk(aa));
	goto_nearest_brk(aa);
	print_stk(aa);
	goto_nearest_brk(bb);
	rsip_approach(bb, aa);
}

int	input_vals(char **argv, t_stack *s)
{
	t_stack	tmp;
	char	*str;
	int		val;
	
	init_stack(&tmp);
	while (*argv)
	{
		val = ft_atoi(*argv);
		str = ft_itoa(val);
		if (ft_strncmp(str, *argv, ft_strlen(*argv)) != 0)
		{
			err("Error\n");
			return(free((void *)str), 0);
		}
		free((void *)str);
		push_stack(&tmp, val);
		argv++;
	}
	while (size_stack(&tmp))
		xpush_stack(s, &tmp);
	return (size_stack(s));
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
	init_stk(&aa, &a, &ai, 'a');
	init_stk(&bb, &b, &bi, 'b');
	if (! input_vals(++argv, &a))
		return (ft_putstr("Error\n"), 2);
	mkidx(&aa);
	ft_putendl("Start a:");
	print_stk(&aa);
	ft_putendl("Start b:");
	print_stk(&bb);
//	find_solution(&a, &b);
//	find_solution2(&aa, &bb);
	find_solution9(&aa, &bb);
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
	ft_putstr("finish score: ");
	ft_putnbr(wrongdir_rank(&aa, &bb));
	ft_putendl("");
	return (0);
}
