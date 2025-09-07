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

#include "libft/libft.h"
#include "push_swap.h"

void	print_stack(t_stack s)
{
	int	i;

	i = 0;
	while (i < s.size)
	{
		ft_putnbr(s.val[i]);
		if (i != s.size)
			ft_putchar(' ');
		i++;
	}
}

int	push(t_stack *s)
{
	return (1);
}

int	pop(t_stack *s)
{
	return (1);
}

int	rot(t_stack *s)
{
	return (1);
}

int	rrot(t_stack *s)
{
	return (1);
}
