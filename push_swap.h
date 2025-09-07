/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvolikov <pvolikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 20:17:33 by pvolikov          #+#    #+#             */
/*   Updated: 2025/09/06 20:19:29 by pvolikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define STACK_LEN 1000

typedef struct s_stack
//an array where the first element is the bottom of the stack
{
	int	val[STACK_LEN];
	// int top;
	int	size;
}	t_stack;


void	print_stack(t_stack s); 
int push(t_stack *s); 
int	pop(t_stack *s);
int	rot(t_stack *s);
int	rrot(t_stack *s);

#endif
