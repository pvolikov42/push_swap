/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histacks3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvolikov <pvolikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:17:33 by pvolikov          #+#    #+#             */
/*   Updated: 2025/09/18 20:19:29 by pvolikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include "utils.h"

int	xpush(t_stackf *dst, t_stackf *src)
{
	if (dst->id == 'a' || dst->id == 'b' || DEBUG > 0)
	{
		ft_d("+");
		ft_putstr("p");
		ft_putchar(dst->id);
		ft_d2(" ", peekidx(src));
		ft_putendl("");
	}
	xpush_stack(dst->stk, src->stk);
	xpush_stack(dst->idx, src->idx);
	return (1);
}

int	rot(t_stackf *s)
{
	if (s->id == 'a' || s->id == 'b' || DEBUG > 0)
	{
		ft_d("+");
		ft_putstr("r");
		ft_putchar(s->id);
		ft_putendl("");
	}
	return (rot_stack(s->stk) && rot_stack(s->idx));
}

int	rrot(t_stackf *s)
{
	if (s->id == 'a' || s->id == 'b' || DEBUG > 0)
	{
		ft_d("+");
		ft_putstr("rr");
		ft_putchar(s->id);
		ft_putendl("");
	}
	return (rrot_stack(s->stk) && rrot_stack(s->idx));
}

int	rot2(t_stackf *s1, t_stackf *s2)
{
	int	res;

	ft_putendl("+rr");
	res = rot_stack(s1->stk) && rot_stack(s1->idx);
	return (res && rot_stack(s2->stk) && rot_stack(s2->idx));
}

int	rrot2(t_stackf *s1, t_stackf *s2)
{
	int	res;

	ft_putendl("+rrr");
	res = rrot_stack(s1->stk) && rrot_stack(s1->idx);
	return (res && rrot_stack(s2->stk) && rrot_stack(s2->idx));
}
