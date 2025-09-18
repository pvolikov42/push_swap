/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvolikov <pvolikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 20:17:33 by pvolikov          #+#    #+#             */
/*   Updated: 2025/09/18 20:19:29 by pvolikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft/libft.h"
#include "push_swap.h"

int	sip_range(t_stackf *s1, t_stackf *s2, int min, int max)
//move elements of stack s1 to stack s2 in backward order
// next element are looked for by rotating or revrotating s1
// indexes are in range [min, max] (inclusively)
// returns the number of sipped (xpushed) elements
{
	int	i;
	int	pos;
	int	counter;

	counter = 0;
	i = max;
	while (i >= min)
	{
		pos = find_value(i, s1->idx->val, s1->idx->size);
		if (pos == -1)
		{
			i--; // only decrease after all equal entries are moved
			continue ;
		}
		goto_el(s1, i);
		xpush(s2, s1);
		counter++;
	}
	return (counter);
}

int	rsip_range(t_stackf *s1, t_stackf *s2, int min, int max)
// sips all elements in normal (first-to-last) order
// index is in range [min, max] inclusively
{
	int	i;
	int	pos;
	int	counter;

	counter = 0;
	i = min;
	while (i <= max && s1->stk->size)
	{
		pos = find_value(i, s1->idx->val, s1->idx->size);
		if (pos == -1)
		{
			i++; // only change after all equal entries are processed
			continue ;
		}
		goto_el(s1, i);
		xpush(s2, s1);
		counter++;
	}
	return (counter);
}

void	find_solution9(t_stackf *aa, t_stackf *bb)
// sorting the desert
// split until sippable
// sorted sequence grows inside stack aa
{
	int	thr;

	thr = size_stk(aa) + size_stk(bb);
	divide_n_sip_cl(aa, bb, 0, thr);
}
