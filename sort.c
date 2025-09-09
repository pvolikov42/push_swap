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


int	is_sorted(int *arr, int n)
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

int find_value(int value, int *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (arr[i] == value) return (i);
		i++;
	}
	return (-1);
}

void	print_arr(int* arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putnbr(arr[i]);
		if (i != n) ft_putchar(' ');
		i++;
	}
}
