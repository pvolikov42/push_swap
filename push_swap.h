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
# define OPTIMUM 30

// below is MIN_INT
# define ERR_STACKF -2147483648

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
	char	id;
}	t_stackf;

void		init_stack(t_stack *s);
void		print_stack(const t_stack *s);
int			size_stack(const t_stack *s);
int			copy_stack(t_stack *dst, const t_stack *src);
int			push_stack(t_stack *dst, int value);
int			xpush_stack(t_stack *dst, t_stack *src);
int			pop_stack(t_stack *s);
int			peek_stack(t_stack *s);
int			peek2_stack(t_stack *s);
int			rot_stack(t_stack *s);
int			rrot_stack(t_stack *s);
int			swap_stack(t_stack *s);
int			zero_stack(t_stack *s);
int			count_monotonic_sequences(const t_stack *s);
int			findval_stack(int val, const t_stack *s);

t_stackf	*create_stk(void);
t_stackf	*dup_stk(const t_stackf *src);
//void		init_stk(t_stackf *s, t_stack *stk, t_stack *idx, char id);
void		init_stk(t_stackf *s, char id);
void		release_stk(t_stackf *s);
void		print_stk(const t_stackf *s);
int			size_stk(const t_stackf *s);
void		mkidx(t_stackf *s);
int			push(t_stackf *dst, int value);
int			xpush(t_stackf *dst, t_stackf *src);
int			pop(t_stackf *s);
int			peek(const t_stackf *s);
int			peek2(const t_stackf *s);
int			peekidx(const t_stackf *s);
int			rot(t_stackf *s);
int			rrot(t_stackf *s);
int			swap(t_stackf *s);
int			mrot(t_stackf *s, int ops);
int			mrrot(t_stackf *s, int ops);
int			rot2(t_stackf *s1, t_stackf *s2);
int			rrot2(t_stackf *s1, t_stackf *s2);
int			swap2(t_stackf *s1, t_stackf *s2);
int			dump(t_stackf *src, t_stackf *dst);
int			ndump(t_stackf *src, t_stackf *dst, int num);

int			dump_second_half(t_stackf *src, t_stackf *dst);
int			dump_higher(t_stackf *src, t_stackf *dst, int threshold);
int			dump_lower(t_stackf *src, t_stackf *dst, int threshold);
int			ndump_higher(t_stackf *src, t_stackf *dst, int threshold, int n);
int			ndump_lower(t_stackf *src, t_stackf *dst, int threshold, int n);
int			wrongdir_rank(t_stackf *aa, t_stackf *bb);
int			dist_to_brk(const t_stackf *s);
int			goto_nearest_brk(t_stackf *s);
int			sortedness_score_for_a(const t_stackf *s);
int			range_len(t_stackf *s, int min, int max);
int			dist_to_elem(const t_stackf *s, int idx);
int			dist_to_next(const t_stackf *s, int idx, int max);
//int			dist_to_2nd_next(const t_stackf *s, int i, int max);
int			dist_2ndstep(const t_stackf *s, int i, int delta);
int			goto_el(t_stackf *s, int idx);
int			adjust_stk(t_stackf *s, int dist);
int			is_sip_2step_optimizable(t_stackf *s, int idx);
int			is_rsip_2step_optimizable(t_stackf *s, int idx);

int			is_sorted(const int *arr, int n);
int			is_seq_sorted(const int *arr, int n, int start);
int			is_rev_sorted(const int *arr, int n);
int			nonascention(const int *arr, int n);
int			nondescention(const int *arr, int n);
void		bubble_sort(int *arr, int n);
void		bubble_rsort(int *arr, int n);
void		print_arr(const int *arr, int n);
int			find_value(int value, const int *arr, int n);
int			rfind_value(int value, const int *arr, int n);
int			get_next_value(int start, const int *arr, int size);
int			min_el(const int *arr, int size);
int			max_el(const int *arr, int size);
int			min(int a, int b);
int			max(int a, int b);

void		sip_approach(t_stackf *aa, t_stackf *bb);
void		rsip_approach(t_stackf *aa, t_stackf *bb);
int			divide_n_sip_cl(t_stackf *aa, t_stackf *bb, int min, int max);
int			divide_n_sip_cr(t_stackf *aa, t_stackf *bb, int min, int max);
int			sip_range(t_stackf *aa, t_stackf *bb, int min, int max);
int			rsip_range(t_stackf *aa, t_stackf *bb, int min, int max);
int			sip_range_optm(t_stackf *aa, t_stackf *bb, int min, int max);
int			rsip_range_optm(t_stackf *aa, t_stackf *bb, int min, int max);
//void		sip_approach(t_stack *a, t_stack *b, t_stack *ai);
void		find_solution9(t_stackf *aa, t_stackf *bb);

#endif
