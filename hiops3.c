/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hiops3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvolikov <pvolikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:17:33 by pvolikov          #+#    #+#             */
/*   Updated: 2025/09/18 20:19:29 by pvolikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"
#include "libft/libft.h"

int	is_sip_2step_optimizable(t_stackf *s, int idx)
{
	int	dist1;
	int	dist2;

	dist1 = dist_to_elem(s, idx);
	dist2 = dist_2ndstep(s, idx, -1);
	ft_d3("_dist1=", dist1, " ");
	ft_d3(" dist2=", dist2, "\n");
	return (abs(dist1 + dist2) + 1 + sign(dist2) < abs(dist1));
}

int	is_rsip_2step_optimizable(t_stackf *s, int idx)
{
	int	dist1;
	int	dist2;

	dist1 = dist_to_elem(s, idx);
	dist2 = dist_2ndstep(s, idx, +1);
	ft_d3("_dist1=", dist1, " ");
	ft_d3(" dist2=", dist2, "\n");
	return (abs(dist1 + dist2) + 1 + sign(dist2) < abs(dist1));
}
