/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvolikov <pvolikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:17:33 by pvolikov          #+#    #+#             */
/*   Updated: 2025/09/08 20:19:29 by pvolikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "utils.h"
#include "libft/libft.h"

void	debug(char *s)
{
	printf("DEBUG: %s", s);
	//ft_putstr_fd(s, 2);
}

void	ft_d(char *s)
{
	if (DEBUG == 0) 
		return ;
	ft_putstr(s);
}

void	ft_d2(char *s, int num)
{
	if (DEBUG == 0) 
		return ;
	ft_putstr(s);
	ft_putnbr(num);
}


void	ft_d3(char *s1, int num, char *s3)
{
	if (DEBUG == 0) 
		return ;
	ft_putstr(s1);
	ft_putnbr(num);
	ft_putstr(s3);
}

void	err(char *s)
{
	ft_putstr_fd(s, 2);
}

int	abs(int value)
{
	if (value < 0) 
		return (-value);
	else
		return (value);
}

int	sign(int value)
{
	if (value < 0)
		return (-1);
	else	
		return (1);
}
