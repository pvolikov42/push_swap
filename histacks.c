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

void	init(t_stackf *s, t_stack *stk, t_stack *idx)
{
	init_stack(stk);
	s->stk = stk;
	init_stack(idx);
	s->idx = idx;
}

void	print_stk(const t_stackf *s)
{
	ft_putstr("stk:");
	print_stack(s->stk);
	ft_putstr("idx:");
	print_stack(s->idx);
}

void	mkidx(t_stackf *s)
{
	int		i;
	t_stack	tmp;
	
	copy_stack(&tmp, s->stk);
	bubble_rsort(tmp.val, tmp.size);
	i = 0;
	while (i < s->stk->size)
	{
		s->idx->val[i] = find_value(s->stk->val[i], tmp.val, s->stk->size);
		i++;
	}
	s->idx->size = i;
}

int	xpush(t_stackf *dst, t_stackf *src)
{
	ft_putendl("+xpush");
	xpush_stack(dst->stk, src->stk);
	xpush_stack(dst->idx, src->idx);
/*	ft_putstr(" src:");
	print_stack(src->stk);
	ft_putstr("sidx:");
	print_stack(src->idx);
	ft_putstr(" dst:");
	print_stack(dst->stk);
	ft_putstr("didx:");
	print_stack(dst->idx);*/
	return(1);
//	return (xpush_stack(dst->stk, src->stk) & xpush_stack(dst->idx, src->idx));
}

int	pop(t_stackf *s)
{	
	//--s->idx->size;
	return (s->stk->val[--s->stk->size]);
}

int	peek(t_stackf *s)
{
	return (peek_stack(s->stk));
}

int	peek2(t_stackf *s)
{
	return (peek2_stack(s->stk));
}


int swap(t_stackf *s)
{
	ft_putendl("+swap");
	return (swap_stack(s->stk) & swap_stack(s->idx));
}

int	swap2(t_stackf *s1, t_stackf *s2)
{
	ft_putendl("+swap2");
	return (swap_stack(s1->stk) & swap_stack(s1->idx) \
		& swap_stack(s2->stk) & swap_stack(s2->idx));
}

int	rot(t_stackf *s)
{
	ft_putendl("+rot");
	return (rot_stack(s->stk) & rot_stack(s->idx));
}

int	rrot(t_stackf *s)
{
	ft_putendl("+rrot");
	return (rrot_stack(s->stk) & rrot_stack(s->idx));
}

int	rot2(t_stackf *s1, t_stackf *s2)
{
	ft_putendl("+rot2");
	return (rot_stack(s1->stk) & rot_stack(s1->idx)\
		& rot_stack(s2->stk) & rot_stack(s2->idx));
}

int	rrot2(t_stackf *s1, t_stackf *s2)
{
	ft_putendl("+rrot2");
	return (rrot_stack(s1->stk) & rrot_stack(s1->idx)\
		& rrot_stack(s2->stk) & rrot_stack(s2->idx));
}

int dump(t_stackf *src, t_stackf *dst)
{
	while (src->stk->size)
		xpush(dst, src);
	return (1);
}
