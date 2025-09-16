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

#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

int	create_stk(t_stackf *s)
{
	s->stk = (t_stack *)malloc(sizeof(t_stack));
	s->idx = (t_stack *)malloc(sizeof(t_stack));
	if (s->stk == NULL || s->idx == NULL)
		return (0);
	return (1);
}

void	init_stk(t_stackf *s, t_stack *stk, t_stack *idx, char id)
{
	init_stack(stk);
	s->stk = stk;
	init_stack(idx);
	s->idx = idx;
	s->id = id;
}

void	release_stk(t_stackf *s)
{
	free((void *)s->stk);
	free((void *)s->idx);
}

void	print_stk(const t_stackf *s)
{
	ft_putchar(s->id);
	ft_putstr(":stk:");
	print_stack(s->stk);
	ft_putchar(s->id);
	ft_putstr(":idx:");
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

int	push(t_stackf *dst, int val)
{
//	ft_putendl("+push");
	push_stack(dst->stk, val);
	mkidx(dst);
	return (1);
}


int	xpush(t_stackf *dst, t_stackf *src)
{
	ft_putstr("+p");
	ft_putchar(dst->id);
	ft_putnbr(peekidx(src));
	ft_putendl("");
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

int	peek(const t_stackf *s)
{
	return (peek_stack(s->stk));
}

int	peekidx(const t_stackf *s)
{
	return (peek_stack(s->idx));
}

int	peek2(const t_stackf *s)
{
	return (peek2_stack(s->stk));
}

int swap(t_stackf *s)
{
	ft_putstr("+s");
	ft_putchar(s->id);
	ft_putendl("");
	return (swap_stack(s->stk) && swap_stack(s->idx));
}

int	swap2(t_stackf *s1, t_stackf *s2)
{
	ft_putendl("+ss");
	return (swap_stack(s1->stk) && swap_stack(s1->idx) \
		&& swap_stack(s2->stk) && swap_stack(s2->idx));
}

int	rot(t_stackf *s)
{
	ft_putstr("+r");
	ft_putchar(s->id);
	ft_putendl("");
	return (rot_stack(s->stk) && rot_stack(s->idx));
}

int	mrot(t_stackf *s, int ops)
{
	ft_putendl("_mrot started");
	while (ops-- > 0) 
		rot(s);
	return (1);
}

int	rrot(t_stackf *s)
{
	ft_putstr("+rr");
	ft_putchar(s->id);
	ft_putendl("");
	return (rrot_stack(s->stk) && rrot_stack(s->idx));
}

int	mrrot(t_stackf *s, int ops)
{
	ft_putendl("_mrrot started");
	while (ops-- > 0) 
		rrot(s);
	return (1);
}

int	rot2(t_stackf *s1, t_stackf *s2)
{
	ft_putendl("+rr");
	return (rot_stack(s1->stk) && rot_stack(s1->idx)\
		&& rot_stack(s2->stk) && rot_stack(s2->idx));
}

int	rrot2(t_stackf *s1, t_stackf *s2)
{
	ft_putendl("+rrr");
	return (rrot_stack(s1->stk) && rrot_stack(s1->idx)\
		&& rrot_stack(s2->stk) && rrot_stack(s2->idx));
}

int	dump(t_stackf *src, t_stackf *dst)
{
	int	cnt;

	cnt = 0;
	while (src->stk->size)
	{
		xpush(dst, src);
		cnt++;
	}
	return (cnt);
}

int	ndump(t_stackf *src, t_stackf *dst, int num)
{
	int	i;
	
	i = 0;
	while (i < num && src->stk->size)
	{
		xpush(dst, src);
		i++;
	}
	return (i);
}


int	size_stk(const t_stackf *s)
{
	return (size_stack(s->stk));
}

