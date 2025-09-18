/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histacks2.c                                        :+:      :+:    :+:   */
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

int	peekidx(const t_stackf *s)
{
	return (peek_stack(s->idx));
}

int	peek2(const t_stackf *s)
{
	return (peek2_stack(s->stk));
}

int	swap(t_stackf *s)
{
	ft_d("+");
	ft_putstr("s");
	ft_putchar(s->id);
	ft_putendl("");
	return (swap_stack(s->stk) && swap_stack(s->idx));
}

int	swap2(t_stackf *s1, t_stackf *s2)
{
	int	res;

	ft_d("+");
	ft_putendl("ss");
	res = swap_stack(s1->stk) && swap_stack(s1->idx);
	return (res && swap_stack(s2->stk) && swap_stack(s2->idx));
}
