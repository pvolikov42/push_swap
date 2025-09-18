/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks1.c                                          :+:      :+:    :+:   */
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

int	push_stack(t_stack *dst, int value)
{
	dst->val[dst->size++] = value;
	return (1);
}

int	pop_stack(t_stack *s)
{
	if (s->size < 1)
	{
		err("pop_stack: Stack underflow\n");
		return (0);
	}
	return (s->val[--(s->size)]);
}

int	peek_stack(t_stack *s)
{
	if (s->size < 1)
	{
		err("peek_stack: Stack underflow\n");
		return (0);
	}
	return (s->val[s->size - 1]);
}

int	peek2_stack(t_stack *s)
// peek the value just under the top one
// equiv to elem=pop(s) ; res=peek(s) ; push(elem, s); return(res)
{
	if (s->size < 2)
	{
		err("peek2_stack: Stack underflow\n");
		return (0);
	}
	return (s->val[s->size - 2]);
}
