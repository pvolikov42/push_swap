/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histacks4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvolikov <pvolikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:17:33 by pvolikov          #+#    #+#             */
/*   Updated: 2025/12/04 15:31:35 by pvolikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include "utils.h"

int	mrot(t_stackf *s, int ops)
{
	ft_d("_mrot started\n");
	while (ops-- > 0)
		rot(s);
	return (1);
}

int	mrrot(t_stackf *s, int ops)
{
	ft_d("_mrrot started\n");
	while (ops-- > 0)
		rrot(s);
	return (1);
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

int is_perfect_seq(const t_stackf *s, int start, int end)
{
	int	i;
	int	inc;

	i = 0;
	inc = (end >= start) * 2 - 1;
	ft_d2("_is_perfect_seq: checking seq from start=", start);
	ft_d2(" with size=", s->stk->size);
	ft_d3(" to end=", end, "\n");
	while (i < s->stk->size && (end - start) * inc >= 0)
	{
		ft_d2("_perf_index=", i);
		ft_d3(" curval=", start, "\n");
		if (s->idx->val[s->stk->size - 1 - i] != start)
			return (0);
		i++;
		start += inc;
	}
	return (1);
}