/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hiops1.c                                           :+:      :+:    :+:   */
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

int	adjust_stk(t_stackf *s, int dist)
// should return the number of moves done
{
	if (dist == ERR_STACKF)
		return (ERR_STACKF);
	if (dist > 0)
		return (mrot(s, dist));
	if (dist < 0)
		return (mrrot(s, -dist));
	return (0);
}

int	goto_el(t_stackf *s, int idx)
// rotates or revrotates stack to get idx element on top
// should return the number of moves done
{
	int	dist;

	dist = dist_to_elem(s, idx);
	return (adjust_stk(s, dist));
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
	int	sz;

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

int	goto_nearest_brk(t_stackf *s)
{
	int	i;
	int	num;

	num = dist_to_brk(s);
	i = 0;
	while (i++ < abs(num))
	{
		if (num > 0)
			rot(s);
		else
			rrot(s);
	}
	return (1);
}
