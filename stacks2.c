/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvolikov <pvolikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:17:33 by pvolikov          #+#    #+#             */
/*   Updated: 2025/09/18 20:19:29 by pvolikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft/libft.h"
#include "push_swap.h"

int	swap_stack(t_stack *s)
{
	int	tmp;

	if (s->size < 2)
		return (0);
	tmp = s->val[s->size - 1];
	s->val[s->size - 1] = s->val[s->size - 2];
	s->val[s->size - 2] = tmp;
	return (1);
}

int	rot_stack(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->size < 2)
		return (1);
	tmp = s->val[0];
	s->val[0] = s->val[s->size - 1];
	i = s->size;
	while (i > 1)
	{
		s->val[i] = s->val[i - 1];
		i--;
	}
	s->val[1] = tmp;
	return (1);
}

int	rrot_stack(t_stack *s)
{
	int	tmp;
	int	i;

	if (s->size < 2)
		return (1);
	tmp = s->val[s->size - 1];
	s->val[s->size - 1] = s->val[0];
	i = 0;
	while (i < s->size - 1)
	{
		s->val[i] = s->val[i + 1];
		i++;
	}
	s->val[s->size - 2] = tmp;
	return (1);
}

int	count_monotonic_sequences(const t_stack *s)
{
	int	i;
	int	count;

	if (!s || s->size == 0)
		return (0);
	count = 1;
	i = 1;
	while (i < s->size)
	{
		if (s->val[i] < s->val[i - 1])
			count++;
		i++;
	}
	return (count);
}

int	xpush_stack(t_stack *dst, t_stack *src)
{
	if (src->size < 1)
	{
		err("Source stack underflow\n");
		return (0);
	}
	if (dst->size == STACK_LEN)
	{
		err("Dest stack overflow\n");
		return (0);
	}
	dst->val[dst->size++] = pop_stack(src);
	return (1);
}
