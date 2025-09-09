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

typedef struct s_stackf
// stack with additional features (sorting index of elements)
// idx.size should be ignored
{
	t_stack	*stk;
	t_stack	*idx;
}	t_stackf;

void	init_stack(t_stack *s);
void	print_stack(const t_stack *s);
int		copy_stack(t_stack *dst, const t_stack *src);
int		xpush_stack(t_stack *dst, t_stack *src);
int		pop_stack(t_stack *s);
int		rot_stack(t_stack *s);
int		rrot_stack(t_stack *s);
void	init(t_stackf *s, t_stack *stk, t_stack *idx);
int		xpush(t_stackf *dst, t_stackf *src);
int		pop(t_stackf *s);
int		rot(t_stackf *s);
int		rrot(t_stackf *s);

int		is_sorted(int* arr, int n);
void	bubble_sort(int* arr, int n);
void	bubble_rsort(int* arr, int n);
void	print_arr(int* arr, int n);
int		find_value(int value, int *arr, int n);

void	debug(char *s);
void	err(char *s);

//void	sip_approach(t_stack *a, t_stack *b, t_stack *ai);

#endif
