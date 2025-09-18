/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
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

void	print_arr(const int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(arr[i]);
		if (i != size)
			ft_putchar(' ');
		i++;
	}
}

int	min_el(const int *arr, int size)
// if size == 0 return result is undefined
{
	int	res;
	int	i;

	if (size < 1)
		err("min_el: null array");
	res = arr[0];
	i = 0;
	while (i < size)
	{
		if (arr[i] < res)
			res = arr[i];
		i++;
	}
	return (res);
}

int	max_el(const int *arr, int size)
// if size == 0 return result is undefined
{
	int	res;
	int	i;

	if (size < 1)
		err("max_el: null array");
	res = arr[0];
	i = 0;
	while (i < size)
	{
		if (arr[i] > res)
			res = arr[i];
		i++;
	}
	return (res);
}

int	get_next_value(int start, const int *arr, int size)
// returns next existing value bigger than start
// if none found then returns start value
// there is room for optimization
{
	int	i;
	int	m;

	m = max_el(arr, size);
	i = max(start + 1, min_el(arr, size));
	while (find_value(i, arr, size) == -1 && i <= m)
		i++;
	if (i > m)
		i = start;
	return (i);
}
