/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvolikov <pvolikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:17:33 by pvolikov          #+#    #+#             */
/*   Updated: 2025/09/07 20:19:29 by pvolikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft/libft.h"
#include "push_swap.h"

void	init_stack(t_stack *s)
{
	s->size = 0;
}

void	print_stack(const t_stack *s)
{
	int	i;

	ft_putstr("Len=");
	ft_putnbr(s->size);
	ft_putchar(':');
	i = 0;
	while (i < s->size)
	{
		ft_putnbr(s->val[i]);
		if (i != s->size)
			ft_putchar(' ');
		i++;
	}
	ft_putstr(">\n");
}

int	size_stack(const t_stack *s)
{
	return(s->size);
};

int push_stack(t_stack *dst, int value)
{
	dst->val[dst->size++] = value;
	return (1);
}

int	copy_stack(t_stack *dst, const t_stack *src)
{
	int	i;

	i = 0; 
	while (i < src->size)
	{
		//ft_putnbr(src->val[i]);
		//ft_putchar(';');
		dst->val[i] = src->val[i];
		i++;
	}
	dst->size = src->size;
	return (i);
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

int	rrot_stack(t_stack *s)
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

int	zero_stack(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->size)
		s->val[i++] = 0;
	return (i);
}
