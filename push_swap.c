/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvolikov <pvolikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 20:17:33 by pvolikov          #+#    #+#             */
/*   Updated: 2025/08/04 20:19:29 by pvolikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "utils.h"
#include "libft/libft.h"
#include "push_swap.h"

int	input_vals(char **argv, t_stack *s)
{
	t_stack	tmp;
	char	*str;
	int		val;

	init_stack(&tmp);
	while (*argv)
	{
		val = ft_atoi(*argv);
		str = ft_itoa(val);
		if (ft_strncmp(str, *argv, ft_strlen(*argv)) != 0)
		{
			err("Error\n");
			return (free((void *)str), 0);
		}
		free((void *)str);
		push_stack(&tmp, val);
		argv++;
	}
	while (size_stack(&tmp))
		xpush_stack(s, &tmp);
	return (size_stack(s));
}

int	main(int argc, char **argv)
{
//	t_stack	a;
//	t_stack	b;
//	t_stack	ai;
//	t_stack	bi;
	t_stackf	*aa;
	t_stackf	*bb;

	if (argc < 2)
		return (ft_putstr("Error\n"), 1);
//	init_stack(&a);
//	init_stack(&b);
	aa = create_stk();
	bb = create_stk();
	init_stk(aa, 'a');
	init_stk(bb, 'b');
	if (! input_vals(++argv, aa->stk))
		return (ft_putstr("Error\n"), 2);
	mkidx(aa);
	ft_d("Start a:\n");
	print_stk(aa);
	ft_d("Start b:\n");
	print_stk(bb);
//	find_solution(&a, &b);
//	find_solution2(&aa, &bb);
	find_solution9(aa, bb);
/*    mkidx(&aa);
	print_stk(&aa);
	print_stk(&bb);
	rrot(&aa);
	xpush(&bb, &aa);
	xpush(&bb, &aa);
	rot(&aa);
	print_stk(&aa);
	rot(&aa); */
	ft_d("Finish \n");
	print_stk(aa);
	//ft_putendl("Finish b: ");
	print_stk(bb);
	ft_d3("finish score: ", wrongdir_rank(aa, bb), "\n");
	return (release_stk(aa), release_stk(bb), 0);
}
