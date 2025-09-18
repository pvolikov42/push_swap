/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvolikov <pvolikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:17:33 by pvolikov          #+#    #+#             */
/*   Updated: 2025/09/18 20:19:29 by pvolikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	find_value(int value, const int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	rfind_value(int value, const int *arr, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		if (arr[i] == value)
			return (i);
		i--;
	}
	return (-1);
}
