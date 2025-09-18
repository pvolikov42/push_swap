/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   histacks4.c                                        :+:      :+:    :+:   */
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
