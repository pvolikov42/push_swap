/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hiops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvolikov <pvolikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:17:33 by pvolikov          #+#    #+#             */
/*   Updated: 2025/09/10 20:19:29 by pvolikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dump_second_half(t_stackf *src, t_stackf *dst)
{
	int	threshold;
	int	i;

	i = src->stk->size - 1;
	threshold = i / 2;
	while (i >= 0)
	{
		if (peek_stack(src->idx) >= threshold) 
			xpush(dst, src);
		else 
			rot(src);
		i--;
	}
	return (1);
}

int	dump_part(t_stackf *src, t_stackf *dst, int threshold)
{
	int	i;

	i = src->stk->size - 1;
	while (i >= 0)
	{
		if (peek_stack(src->idx) >= threshold) 
			xpush(dst, src);
		else 
			rot(src);
		i--;
	}
	return (1);
}

int	dirpoint_rank(t_stackf *aa, t_stackf *bb)
{
	return (nondescention(aa->stk->val, aa->stk->size)\
		+ (peek(aa) < peek(bb))\
		+ nonascention(bb->stk->val, bb->stk->size));
}

