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

#include "utils.h"
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

int	dump_higher(t_stackf *src, t_stackf *dst, int threshold)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = src->stk->size - 1;
	while (i >= 0)
	{
		if (peek_stack(src->idx) > threshold) 
		{
			xpush(dst, src);
			cnt++;
		}
		else 
			rot(src);
		i--;
	}
	return (cnt);
}

int	ndump_higher(t_stackf *src, t_stackf *dst, int threshold, int n)
// n is the maximum number of elements processed
{
	int	i;
	int	cnt;

	cnt = 0;
	i = min(size_stk(src), n);
	while (i > 0)
	{
		if (peek_stack(src->idx) > threshold) 
		{
			xpush(dst, src);
			cnt++;
		}
		else 
			rot(src);
		i--;
	}
	return (cnt);
}
int	dump_lower(t_stackf *src, t_stackf *dst, int threshold)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = src->stk->size - 1;
	while (i >= 0)
	{
		if (peek_stack(src->idx) < threshold)
		{
			xpush(dst, src);
			cnt++;
		}
		else 
			rot(src);
		i--;
	}
	return (cnt);
}

int	ndump_lower(t_stackf *src, t_stackf *dst, int threshold, int n)
// n is the maximum number of elements processed
{
	int	i;
	int	cnt;

	cnt = 0;
	i = min(size_stk(src), n);
	while (i > 0)
	{
		if (peek_stack(src->idx) < threshold)
		{
			xpush(dst, src);
			cnt++;
		}
		else 
			rot(src);
		i--;
	}
	return (cnt);
}


int	wrongdir_rank(t_stackf *aa, t_stackf *bb)
{
	int	res;

	if (size_stk(aa) > 0) 
		res = nondescention(aa->stk->val, size_stk(aa));
	if (size_stk(bb) > 0)	
		res += nonascention(bb->stk->val, size_stk(bb));
	if (size_stk(aa) > 0 && size_stk(bb) > 0) 
		res += (peek(aa) < peek(bb));
	return (res);
}

int	dist_to_brk(const t_stackf *s)
{
	int	i;
	int sz;

	sz = size_stk(s);
	if (sz < 2) 
		return (0);
	i = 0;
	if (s->idx->val[sz - 1] > s->idx->val[0])
		return (0);
	i = 1;	
	while (i < sz / 2)
	{
		if (s->idx->val[sz - 1 - i] > s->idx->val[sz - i])
			return (i);
		if (s->idx->val[i - 1] > s->idx->val[i])
			return (-i);
		i++;
	}
	return (sz + 1);
}

int	dist_to_next(const t_stackf *s)
// positive number -- use rot
// negative number -- use rrot
{
	int	i;
	int sz;
	int	d1;
	int	d2;

	sz = s->idx->size;
	if (sz < 1)
	{ 
		err("dist_to_next: stack is empty");
		return (ERR_STACKF);
	}
	i = min_el(s->idx->val, sz);
	d1 = find_value(i, s->idx->val, sz);
	d2 = rfind_value(i, s->idx->val, sz);
	if (d1 == -1 || d2 == -1) 
		return (ERR_STACKF);
	if (d1 + 1 > sz - 1 - d2)
		return (-min(d1 + 1, sz - 1 - d2));
	else 
		return(min(d1 + 1, sz - 1 - d2));
}

/*
int	dist_to_2ndnext(const t_stackf *s)
{
	t_stackf	tmp;
	int	i;
	int sz;
	int	d1;
	int	d2;

	sz = s->idx->size;
	if (sz < 2) 
	{
		err("dist_to_2ndnext: size is too small");
		return (ERR_STACKF);
	}
	i = dist_to_next(s);
	remove_stk
}*/

int	sortedness_score_for_a(const t_stackf *s)
{
	return (nondescention(s->stk->val, s->stk->size));
}

int	goto_nearest_brk(t_stackf *s)
{
	int	i;
	int	num;

	num = dist_to_brk(s);
	i = 0;
	while (i++ < abs(num))
		if (num > 0)
			rot(s);
		else
			rrot(s);
	return (1);
}

int	range_len(t_stackf *s, int min, int max)
// only scans indexes and only once in rot direction
{
	int	cnt;
	int	i;
	int top;

	cnt = 0;
	i = 0;
	top = size_stk(s) - 1;
	while ( i <= top
		&& s->idx->val[top - i]  >= min 
		&& s->idx->val[top - i]  <= max )
	{
		cnt++;
		i++;
	}
	return (cnt);
}

/*
int	full_path(t_stackf *s)
{
	int	i;

	i = 0;
}

int	dist_to_next(t_stackf *s, int cur)
{
	int	i;

	find_value
}*/
