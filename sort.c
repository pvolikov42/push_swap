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

void	bubble_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	swapped;
	int	temp;

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

void	bubble_rsort(int *arr, int n)
{
	int	i;
	int	j;
	int	swapped;
	int	temp;

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
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_rev_sorted(const int *arr, int n)
// check for descending order
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (arr[i] < arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
