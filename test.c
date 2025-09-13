/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvolikov <pvolikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:17:33 by pvolikov          #+#    #+#             */
/*   Updated: 2025/09/07 20:19:29 by pvolikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_test(int	res)
{
	if (res) ft_putstr("OK");
	else ft_putstr("NOK");
}

void	test_nonascention()
{
	int	a0[]={0, 1, 4, 5, 8};
	int	a1[]={1, 5, 4, 8, 0};
	int	a2[]={0, 1, 4, 8, 5};
	int	a3[]={10, 1, 4, 8, 5};
	int	a4[]={0, 1, 4, 4, 8, 8};


	ft_putendl("Testing nonascention()...");
	ft_putstr("1:");
	ft_test(nonascention(a0, 5) == 0);
	ft_putstr(" 2:");
	ft_test(nonascention(a1, 5) == 2);
	ft_putstr(" 3:");
	ft_test(nonascention(a2, 5) == 1);
	ft_putstr(" 4:");
	ft_test(nonascention(a3, 5) == 2);
	ft_putstr(" 5:");
	ft_test(nonascention(a4, 6) == 0);
	ft_putendl("");
}

void	test_nondescention()
{
	int	a0[]={0, 1, 4, 5, 8};
	int	a1[]={1, 5, 4, 8, 0};
	int	a2[]={0, 1, 4, 8, 5};
	int	a3[]={10, 1, 4, 8, 5};
	int	a4[]={10, 10, 4, 4, 2, 0};


	ft_putendl("Testing nondescention()...");
	ft_putstr("1:");
	ft_test(nondescention(a0, 5) == 4);
	ft_putstr(" 2:");
	ft_test(nondescention(a1, 5) == 2);
	ft_putstr(" 3:");
	ft_test(nondescention(a2, 5) == 3);
	ft_putstr(" 4:");
	ft_test(nondescention(a3, 5) == 2);
	ft_putstr(" 5:");
	ft_test(nondescention(a4, 6) == 0);
	ft_putendl("");
}

int	main()
{
	int	a0[]={0, 1, 4, 5, 8};
	int	a1[]={1, 5, 4, 8, 0};
	int	a2[]={0, 1, 4, 8, 5};
	int	a3[]={10, 1, 4, 8, 5};
	
	ft_putendl("Testing is_sorted()...");
	//print_arr(a0, 5);
	//ft_putchar('\n');
	ft_putstr("1:");
	ft_test(is_sorted(a0, 5) == 1);

	//print_arr(a1, 5);
	//ft_putchar('\n');
	ft_putstr(" 2:");
	ft_test(is_sorted(a1, 5) == 0);

	//print_arr(a2, 5);
	//ft_putchar('\n');
	ft_putstr(" 3:");
	ft_test(is_sorted(a2, 5) == 0);
		
	ft_putstr(" 4:");
	ft_test(is_sorted(a3, 5) == 0);

	ft_putendl("");

	ft_putendl("Testing bubble_sort()...");
	//print_arr(a0, 5);
	//ft_putchar('\n');
	ft_putstr("1:");
	bubble_sort(a3, 5);
	ft_test(is_sorted(a3, 5) == 1);
	
	ft_putendl("");
	
	test_nonascention();
	ft_putendl("");
	
	test_nondescention();
}
