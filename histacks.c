/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histacks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvolikov <pvolikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:17:33 by pvolikov          #+#    #+#             */
/*   Updated: 2025/09/08 20:19:29 by pvolikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void init(t_stackf *s, t_stack *stk, t_stack *idx)
{
	init_stack(stk);
	s->stk = stk;
	init_stack(idx);
	s->idx = idx;
}

int	xpush(t_stackf *dst, t_stackf *src)
{
//	err("xp1");
//	xpush_stack(dst->stk, src->stk);
//	err("xp2");
//	xpush_stack(dst->idx, src->idx);
//	err("xp3");
//	return(1);
	return (xpush_stack(dst->stk, src->stk) & xpush_stack(dst->idx, src->idx));
}

int	pop(t_stackf *s)
{
	return (s->stk->val[--s->stk->size]);
}

int	rot(t_stackf *s)
{
	return (rot_stack(s->stk) & rot_stack(s->idx));
}

int	rrot(t_stackf *s)
{
	return (rrot_stack(s->stk) & rrot_stack(s->idx));
}
