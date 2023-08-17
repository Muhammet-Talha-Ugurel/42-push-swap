/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:27:57 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/30 04:45:14 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		return (0);
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	a->size = 0;
	b->size = 0;
	a->stack = (int32_t *)malloc(((ac - 1) * sizeof(int32_t)));
	b->stack = (int32_t *)malloc(((ac - 1) * sizeof(int32_t)));
	ac = get_them_all(a, av, ac);
	if (ac == 2)
		two(a);
	if (ac == 3)
		three(a);
	if (ac == 4)
		four(a, b);
	if (ac == 5)
		five(a, b);
	if (ac >= 6)
		mtu_sort(a, b, ac);
	free(a->stack);
	free(b->stack);
	free(a);
	free(b);
	return (0);
}
