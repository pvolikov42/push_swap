/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvolikov <pvolikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 20:17:33 by pvolikov          #+#    #+#             */
/*   Updated: 2025/08/04 20:19:29 by pvolikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft/libft.h"
#include "push_swap.h"

void	sip_approach(t_stackf *aa, t_stackf *bb)
//move all elements of stack aa to stack bb in backward order
// next element are looked for by rotating or revrotating aa
{
	int	i;
	int	pos;
	int	dir;

	i = aa->stk->size - 1;
	while (i >= 0)
	{
		pos = find_value(i, aa->idx->val, aa->idx->size);
		if (pos == -1)
		{
			i--;
			continue ;
		}
		dir = pos > (aa->stk->size - 2) / 2;
		while (aa->idx->val[aa->stk->size - 1] != i)
		{
			if (dir)
				rot(aa);
			else
				rrot(aa);
		}
		xpush(bb, aa);
	}
}

void	rsip_approach(t_stackf *aa, t_stackf *bb)
// sips all elements in first-to-last order
{
	int	i;
	int	pos;
	int	num;

	i = 0;
	num = aa->stk->size + bb->stk->size;
	while (i < num && aa->stk->size)
	{
		pos = find_value(i, aa->idx->val, aa->idx->size);
		if (pos == -1)
		{
			i++;
			continue ;
		}
		goto_el(aa, i);
		xpush(bb, aa);
	}
}

/*
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
	ft_d("a indexed: ");
	print_stack(&ai);
	init_stack(b);
	xpush_stack(b, a);
	rot_stack(a);
	rot_stack(a);
//	xpush_stack(b, a);
//	sip_approach(a, b, &ai);
	ft_d("\nrr\nrrr");
}
*/

void	find_solution2(t_stackf *aa, t_stackf *bb)
//not just a stub
{
	sip_approach(aa, bb);
	dump(bb, aa);
}

void	find_solution3(t_stackf *aa, t_stackf *bb)
{
	dump_second_half(aa, bb);
	ft_d("after dump_second_half\n");
	print_stk(aa);
	print_stk(bb);
	sip_approach(aa, bb);
	ft_d("after sip_approach(aa, bb)\n");
	print_stk(aa);
	print_stk(bb);
	rsip_approach(bb, aa);
	ft_d("after rsip_approach(bb, aa)\n");
	print_stk(aa);
	print_stk(bb);
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
