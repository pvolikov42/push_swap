/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks3.c                                          :+:      :+:    :+:   */
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

int	findval_stack(int val, const t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->size)
	{
		if (val == s->val[i])
			return (i);
		i++;
	}
	return (-1);
}
