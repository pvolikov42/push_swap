/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvolikov <pvolikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 20:17:33 by pvolikov          #+#    #+#             */
/*   Updated: 2025/12/04 15:32:22 by pvolikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# ifndef DEBUG
#  define DEBUG 0
//#  define DEBUG 1
# endif

void	debug(char *s);
void	ft_d(char *s);
void	ft_d2(char *s, int num);
void	ft_d3(char *s1, int num, char *s3);
void	err(char *s);
int		abs(int val);
int		sign(int value);

#endif
