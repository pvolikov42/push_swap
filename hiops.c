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

#include "push_swap.h"

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
