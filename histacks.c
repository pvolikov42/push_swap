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

void	print_stk(t_stackf *s)
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
	ft_putendl("xpush");
	xpush_stack(dst->stk, src->stk);
	xpush_stack(dst->idx, src->idx);
	ft_putstr(" src:");
	print_stack(src->stk);
	ft_putstr("sidx:");
	print_stack(src->idx);
	ft_putstr(" dst:");
	print_stack(dst->stk);
	ft_putstr("didx:");
	print_stack(dst->idx);
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

int	rot(t_stackf *s)
{
	ft_putendl("rot");
	return (rot_stack(s->stk) & rot_stack(s->idx));
}

int	rrot(t_stackf *s)
{
	ft_putendl("rrot");
	return (rrot_stack(s->stk) & rrot_stack(s->idx));
}

