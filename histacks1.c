/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histacks1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvolikov <pvolikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:17:33 by pvolikov          #+#    #+#             */
/*   Updated: 2025/09/18 20:19:29 by pvolikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include "utils.h"

void	mkidx(t_stackf *s)
// creates an index for each value (descending)
// if strictness == 0 then indexes for equal values are equal
// if strictness != 0 then indexes will be unique
{
	int		i;
	int		pos;
	t_stack	tmp;
	t_stack	used;
	int		strictness;

	copy_stack(&tmp, s->stk);
	bubble_rsort(tmp.val, tmp.size);
	strictness = 1;
	used.size = size_stk(s);
	zero_stack(&used);
	i = 0;
	while (i < size_stk(s))
	{
		pos = find_value(s->stk->val[i], tmp.val, s->stk->size);
		s->idx->val[i] = pos + used.val[pos];
		if (strictness)
			used.val[pos]++;
		i++;
	}
	s->idx->size = i;
}

int	size_stk(const t_stackf *s)
{
	return (size_stack(s->stk));
}

int	push(t_stackf *dst, int val)
{
	push_stack(dst->stk, val);
	mkidx(dst);
	return (1);
}

int	pop(t_stackf *s)
{
	return (s->stk->val[--s->stk->size]);
}

int	peek(const t_stackf *s)
{
	return (peek_stack(s->stk));
}
