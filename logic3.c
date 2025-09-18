/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvolikov <pvolikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 20:17:33 by pvolikov          #+#    #+#             */
/*   Updated: 2025/08/04 20:19:29 by pvolikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft/libft.h"
#include "push_swap.h"

void	rsip_level(t_stackf *aa, t_stackf *bb, int thr)
// sips all elements increasing level/index until the threshold
{
	int	i;
	int	pos;

	i = 0;
	while (i < thr && aa->stk->size)
	{
		pos = find_value(i, aa->idx->val, aa->idx->size);
		if (pos == -1)
		{
			i++;
			continue ;
		}
		goto_el(aa, i);
		xpush(bb, aa);
	}
}

void	find_solution6(t_stackf *aa, t_stackf *bb)
// split the whole set in 4 parts and 
// restrict sip algorithm by threshold 
{
	int	thr;
	int	num;

	thr = (aa->stk->size - 1) / 2;
	dump_higher(aa, bb, thr);
	err("1\n");
	dump_higher(aa, bb, thr / 2);
	err("2\n");
	dump(aa, bb);
	ft_putendl("after dumps");
	print_stk(aa);
	print_stk(bb);
	rsip_level(bb, aa, thr);
	err("3\n");
	num = dump_lower(bb, aa, 3 * thr / 2);
	err("4\n");
	ndump(aa, bb, num);
	err("5\n");
	rsip_approach(bb, aa);
}

void	find_solution8(t_stackf *aa, t_stackf *bb)
// pie method
// splitting the whole set in _num_ chunks each with it's own range
// ranges are approximately equal and are not intersecting
{
	int	thr;
	int	num;
	int	i;

	num = 10;
	thr = (aa->stk->size - 1) / num;
	i = num - 1;
	while (i > 0)
	{
		dump_higher(aa, bb, i * thr);
		i--;
	}
	ft_putendl("after all dumps");
	print_stk(aa);
	print_stk(bb);
	sip_approach(aa, bb);
	rsip_approach(bb, aa);
}
