/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvolikov <pvolikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:17:33 by pvolikov          #+#    #+#             */
/*   Updated: 2025/09/07 20:19:29 by pvolikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"
#include "libft/libft.h"

void	bubble_sort(int* arr, int n)
{
	int	i;
	int	j;
	int swapped;
	int temp;

	i = 0;
	swapped = 1;
	while (i < n - 1 && swapped)
	{
		swapped = 0;
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				// Swap arr[j] and arr[j+1]
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
		i++;
	}
}

void	bubble_rsort(int* arr, int n)
{
	int	i;
	int	j;
	int swapped;
	int temp;

	i = 0;
	swapped = 1;
	while (i < n - 1 && swapped)
	{
		swapped = 0;
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] < arr[j + 1])
			{
				// Swap arr[j] and arr[j+1]
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
		i++;
	}
}

int	is_sorted(const int *arr, int n)
// check for ascending order
{
	int i;

	i = 0;
	while (i < n - 1)
	{
		if (arr[i] > arr[i+1]) return (0);
		i++;
	}
	return (1);
}

int	is_rev_sorted(const int *arr, int n)
// check for descending order
{
	int i;

	i = 0;
	while (i < n - 1)
	{
		if (arr[i] < arr[i+1]) return (0);
		i++;
	}
	return (1);
}

int	nonascention(const int *arr, int size)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < size - 1) 
	{
		if (arr[i] > arr[i + 1])
			count++;
		i++;
	}
	return (count);
}

int	nondescention(const int *arr, int size)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < size - 1) 
	{
		if (arr[i] < arr[i + 1])
			count++;
		i++;
	}
	return (count);
}

int find_value(int value, const int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value) return (i);
		i++;
	}
	// err("find_value: not found\n");
	return (-1);
}

int rfind_value(int value, const int *arr, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		if (arr[i] == value) return (i);
		i--;
	}
	err("rfind_value: not found");
	return (-1);
}

int	get_next_value(int start, const int *arr, int size)
// returns next existing value bigger than start
// if none found then returns start value
// there is room for optimization
{
	int	i;
	int m;

	m = max_el(arr, size);
	i = max(start + 1, min_el(arr, size));
	while (find_value(i, arr, size) == -1 && i <= m)
		i++;
	if (i > m)
		i = start;
	return (i);
}

void	print_arr(const int* arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(arr[i]);
		if (i != size) ft_putchar(' ');
		i++;
	}
}

int	min_el(const int *arr, int size)
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

int	min(int a, int b)
{
	if (a <= b) 
		return (a);
	else
		return (b);
}

int	max(int a, int b)
{
	if (a >= b) 
		return (a);
	else
		return (b);
}

