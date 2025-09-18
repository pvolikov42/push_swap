/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic4.c                                           :+:      :+:    :+:   */
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

static void	report_divsip_params(char *label, int min, int max)
{
	ft_d("_divsip ");
	ft_d(label);
	ft_d2(": nonopt: min=", min);
	ft_d3(" max=", max, "\n");
}

static void	report_divsip_nonopt(char *label, int num, int work, int thr)
{
	ft_d("_divsip ");
	ft_d(label);
	ft_d2(": nonopt: num=", num);
	ft_d2(" work done/left=", work);
	ft_d3(" thr=", thr, "\n");
}

static void	conditional_backtrack(t_stackf *s, int slider, int static_volume)
{
	if (slider < static_volume)
		mrrot(s, slider);
	else
		mrot(s, static_volume);
}

int	divide_n_sip_cr(t_stackf *aa, t_stackf *bb, int min, int max)
// aa is sorted
// bb is unsorted but the upper chunk contains all values
// above min and below max
{
	long int	chunk;
	int			thr;
	int			num;
	int			workleft;

	report_divsip_params("cr", min, max);
	print_stk(aa);
	print_stk(bb);
	chunk = max - min + 1;
	if (chunk <= OPTIMUM)
	{
		ft_d("_cr: OPTIMUM branch\n");
		rsip_range_optm(bb, aa, min, max);
	}
	if (chunk > OPTIMUM)
	{
		thr = min + chunk / 2;
		num = range_len(bb, min, max); //chunk volume
		workleft = size_stk(bb) - num; //unsorted volume
		report_divsip_nonopt("cr", num, workleft, thr);
		num = num - ndump_lower(bb, aa, thr + 1, num); //remaining volume
		divide_n_sip_cl(aa, bb, min, thr);
		conditional_backtrack(aa, num, workleft);
		divide_n_sip_cr(aa, bb, thr + 1, max);
	}
	return (1);
}

int	divide_n_sip_cl(t_stackf *aa, t_stackf *bb, int min, int max)
// aa is sorted until min and has a chunk of unsorted
// from min to max
// bb is unsorted but all above max
{
	long int	chunk;
	int			thr;
	int			num;
	int			workdone;

	report_divsip_params("cl", min, max);
	print_stk(aa);
	print_stk(bb);
	chunk = max - min + 1;
	if (chunk <= OPTIMUM)
	{
		num = sip_range_optm(aa, bb, min, max);
		ndump(bb, aa, num);
	}
	if (chunk > OPTIMUM)
	{
		thr = min + chunk / 2;
		num = range_len(aa, min, max); //chunk volume
		workdone = size_stk(aa) - num; //sorted volume
		report_divsip_nonopt("cl", num, workdone, thr);
		num = num - ndump_higher(aa, bb, thr, num); //remaining volume
		conditional_backtrack(aa, num, workdone);
		divide_n_sip_cl(aa, bb, min, thr);
		divide_n_sip_cr(aa, bb, thr + 1, max);
	}
	return (1);
}
