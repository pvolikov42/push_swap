/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hiops2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvolikov <pvolikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:17:33 by pvolikov          #+#    #+#             */
/*   Updated: 2025/09/18 20:19:29 by pvolikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"
#include "libft/libft.h"

int	dist_to_elem(const t_stackf *s, int i)
// positive number -- use rot
// negative number -- use rrot
// probably should go into stack domain
{
	int	sz;
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
	int	sz;
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
		return (min(d1 + 1, sz - 1 - d2));
}

int	dist_2ndstep(const t_stackf *s, int i, int delta)
// distance from i-th element to (i + delta)-th element
{
	t_stackf	*s_cpy;
	int			d;

	if (size_stk(s) < 2)
	{
		err("dist_2ndstep: size is too small");
		return (ERR_STACKF);
	}
	s_cpy = dup_stk(s);
	s_cpy->id = 't';
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

int	range_len(t_stackf *s, int min, int max)
// only scans indexes and only once in rot direction
{
	int	cnt;
	int	i;
	int	top;

	cnt = 0;
	i = 0;
	top = size_stk(s) - 1;
	while (i <= top
		&& s->idx->val[top - i] >= min
		&& s->idx->val[top - i] <= max)
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
