/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvolikov <pvolikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 20:17:33 by pvolikov          #+#    #+#             */
/*   Updated: 2025/09/18 20:19:29 by pvolikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft/libft.h"
#include "push_swap.h"

static void	optimized_2_1_fetch(t_stackf *s1, t_stackf *s2, int index, int dir)
{
	ft_d("_optimizing..\n");
	goto_el(s1, index + dir);
	xpush(s2, s1);
	goto_el(s1, index);
	xpush(s2, s1);
	swap(s2);
}

static void	fetch_el(t_stackf *s1, t_stackf *s2, int index)
{
	ft_d("_default action\n");
	goto_el(s1, index);
	xpush(s2, s1);
}

int	sip_range_optm(t_stackf *s1, t_stackf *s2, int min, int max)
// as sip_range but optimized to look one step ahead
// returns the number of sipped (xpushed) elements
{
	int	i;
	int	counter;

	counter = 0;
	i = max;
	while (i >= min)
	{
		if (find_value(i, s1->idx->val, s1->idx->size) == -1)
		{
			i--;
			continue ;
		}
		ft_d3("_sip_opt_round. index=", i, "\n");
		if (i - min > 1 && is_sip_2step_optimizable(s1, i))
		{
			optimized_2_1_fetch(s1, s2, i, -1);
			counter += 2;
		}
		else
		{
			fetch_el(s1, s2, i);
			counter++;
		}
	}
	return (counter);
}

int	rsip_range_optm(t_stackf *s1, t_stackf *s2, int min, int max)
// same as rsip_range but optimized to look one step ahead
// returns the number of sipped (xpushed) elements
{
	int	i;
	int	counter;

	counter = 0;
	i = min;
	while (i <= max)
	{
		if (find_value(i, s1->idx->val, s1->idx->size) == -1)
		{
			i++;
			continue ;
		}
		ft_d3("_rsip_opt_round. index=", i, "\n");
		if (max - i > 1 && is_rsip_2step_optimizable(s1, i))
		{
			optimized_2_1_fetch(s1, s2, i, 1);
			counter += 2;
		}
		else
		{
			fetch_el(s1, s2, i);
			counter++;
		}
	}
	return (counter);
}
