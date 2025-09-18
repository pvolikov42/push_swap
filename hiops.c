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
