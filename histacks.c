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

#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"
#include "utils.h"

t_stackf	*create_stk(void)
{
	t_stackf	*s;

	s = (t_stackf *)malloc(sizeof(t_stackf));
	s->stk = (t_stack *)malloc(sizeof(t_stack));
	s->idx = (t_stack *)malloc(sizeof(t_stack));
	if (s->stk == NULL || s->idx == NULL)
		return ((t_stackf *) NULL);
	return (s);
}

/*void	init_stk(t_stackf *s, t_stack *stk, t_stack *idx, char id)
{
	init_stack(stk);
	s->stk = stk;
	init_stack(idx);
	s->idx = idx;
	s->id = id;
}*/

void	init_stk(t_stackf *s, char id)
{
	init_stack(s->stk);
	init_stack(s->idx);
	s->id = id;
}

void	release_stk(t_stackf *s)
{
	free((void *)s->stk);
	free((void *)s->idx);
	free((void *)s);
}

void	print_stk(const t_stackf *s)
{
	if (DEBUG == 0)
		return ;
	ft_putchar(s->id);
	ft_putstr(":stk:");
	print_stack(s->stk);
	ft_putchar(s->id);
	ft_putstr(":idx:");
	print_stack(s->idx);
}

t_stackf	*dup_stk(const t_stackf *src)
{
	t_stackf	*new;

	new = create_stk();
	copy_stack(new->stk, src->stk);
	copy_stack(new->idx, src->idx);
	new->id = src->id;
	return (new);
}
