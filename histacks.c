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

#include "libft/libft.h"
#include "push_swap.h"


int	push(t_stack *dst, t_stack *idst, t_stack *src, t_stack *isrc)
{
	xpush_stack(dst, src);
	xpush_stack(idst, isrc);
	return (1);
}

int	pop(t_stack *s)
{
	if (s->size < 1)
	{
		err("Stack underflow\n");
		return (0);
	}
	return (s->val[--s->size]);
}

int	rot(t_stack *s)
{
	int	tmp;
	int i;

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

int	rrot(t_stack *s)
{
	int	tmp;
	int i;

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
	s->val[0] = tmp;
	return (1);
}
