/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic2.c                                           :+:      :+:    :+:   */
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

/*
void	find_solution5(t_stackf *aa, t_stackf *bb)
//ironing approach
{
	int	i;
	int	j;
	int	num;

	dump_second_half(aa, bb);
	ft_d3("start score: ", wrongdir_rank(aa, bb), "\n");
	if (aa->stk->size > bb->stk->size)
		num = aa->stk->size - 1;
	else
		num = bb->stk->size - 1;
	j = 0;
	while (j < num / 2 && wrongdir_rank(aa, bb) != 0)
	{
		i = 2 * num - j;
		while (i > j + 1) //
		{
			if (i > num)
				rot2(aa, bb);
			else
				rrot2(aa, bb);
			if ((peek(aa) > peek2(aa)) & (peek(bb) < peek2(bb)))
				swap2(aa, bb);
			else if (peek(aa) > peek2(aa))
				swap(aa);
			else if (peek(bb) < peek2(bb))
				swap(bb);
			i--;
			ft_d("after a round\n");
			print_stk(aa);
			print_stk(bb);
		}
		j += 2;
		ft_d3("intermediate score: ", wrongdir_rank(aa, bb), "\n");
	}
	ft_d("testing goto_neareast \n");
	print_stk(aa);
	ft_d2("", dist_to_brk(aa));
	goto_nearest_brk(aa);
	print_stk(aa);
	goto_nearest_brk(bb);
	rsip_approach(bb, aa);
}
*/
