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
#include "libft/libft.h"

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

int	dist_to_elem(const t_stackf *s, int i)
// positive number -- use rot
// negative number -- use rrot
// probably should go into stack domain
{
	int sz;
	int	d1;
	int	d2;

	sz = size_stk(s);
	if (sz < 1)
	{ 
		err("dist_to_elem: stack is empty");
		return (ERR_STACKF);
	}
	d1 = find_value(i, s->idx->val, sz);
	d2 = rfind_value(i, s->idx->val, sz);
	if (d1 == -1 || d2 == -1) 
		return (ERR_STACKF);
	if (d1 + 1 > sz - 1 - d2)
		return (sz - 1 - d2);
	else 
		return (-1 * (d1 + 1));
}

int	dist_to_next(const t_stackf *s, int i, int max)
// positive number -- use rot
// negative number -- use rrot
{
	int sz;
	int	d1;
	int	d2;

	sz = size_stk(s);
	if (sz < 1)
	{ 
		err("dist_to_next: stack is empty");
		return (ERR_STACKF);
	}
	d1 = find_value(i, s->idx->val, sz);
	while (i <= max && d1 == -1)
	{
		i++;
		d1 = find_value(i, s->idx->val, sz);
	}
	d2 = rfind_value(i, s->idx->val, sz);
	if (d1 == -1 || d2 == -1) 
		return (ERR_STACKF);
	if (d1 + 1 > sz - 1 - d2)
		return (-min(d1 + 1, sz - 1 - d2));
	else 
		return(min(d1 + 1, sz - 1 - d2));
}

int	goto_el(t_stackf *s, int idx)
// rotates or revrotates stack to get idx element on top
// should return the number of moves done
{
	int	dist;

//	ft_putendl("_gotoel");
	dist = dist_to_elem(s, idx);
	return(adjust_stk(s, dist));
}

int	adjust_stk(t_stackf *s, int dist)
// should return the number of moves done
{
	if (dist == ERR_STACKF) 
		return(ERR_STACKF);
	if (dist > 0)
		return(mrot(s, dist));
	if (dist < 0)
		return(mrrot(s, -dist));
	return (0);
}

int	dist_2ndstep(const t_stackf *s, int i, int delta)
// distance from i-th element to (i + delta)-th element
{
	t_stackf	*s_cpy;
	int	d;

	if (size_stk(s) < 2) 
	{
		err("dist_2ndstep: size is too small");
		return (ERR_STACKF);
	}
	s_cpy = dup_stk(s);
	s_cpy->id = 't';  //  i.e temporary
	goto_el(s_cpy, i);
	pop(s_cpy);
	d = dist_to_elem(s_cpy, i + delta);
	release_stk(s_cpy);
	return (d);
}

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

int	is_sip_2step_optimizable(t_stackf *s, int idx)
{
	int dist1;
	int dist2;
	
	dist1 = dist_to_elem(s, idx);
//	if (dist1 == ERR_STACKF) 
//		return (0);
	dist2 = dist_2ndstep(s, idx, -1);
	ft_d3("_dist1=", dist1, " ");
	ft_d3(" dist2=", dist2, "\n");
	return (abs(dist1 + dist2) + 1 + sign(dist2) < abs(dist1)); 
}

int	is_rsip_2step_optimizable(t_stackf *s, int idx)
{
	int dist1;
	int dist2;
	
	dist1 = dist_to_elem(s, idx);
//	if (dist1 == ERR_STACKF) 
//		return (0);
	dist2 = dist_2ndstep(s, idx, +1);
	ft_d3("_dist1=", dist1, " ");
	ft_d3(" dist2=", dist2, "\n");
	return (abs(dist1 + dist2) + 1 + sign(dist2) < abs(dist1));
}
