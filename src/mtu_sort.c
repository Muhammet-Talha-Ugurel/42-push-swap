/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtu_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:27:57 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/30 04:45:14 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mtu_sort(t_stack *a, t_stack *b, int ac)
{
	t_stack	*steps;

	steps = malloc(sizeof(t_stack));
	steps->size = 0;
	steps->stack = (int32_t *)malloc(((ac - 1) * sizeof(int32_t)));
	pb(b, a);
	pb(b, a);
	sorting_loop(a, b, steps);
	rotating_loop(b);
	push_all(a, b);
}

void	sorting_loop(t_stack *a, t_stack *b, t_stack *steps)
{
	while (true)
	{
		if (a->size == 0)
			break ;
		count_steps(steps, a, b);
		send_it(a, b, find_smallest(steps));
	}
}

void	rotating_loop(t_stack *b)
{
	while (true)
	{
		if (sorted_b(b))
			break ;
		if (b->size % 2 == 0)
		{
			if (find_biggest(b) <= (b->size / 2))
				rb(b);
			else if (find_biggest(b) > (b->size / 2))
				rrb(b);
		}
		else if (b->size % 2 == 1)
		{
			if (find_biggest(b) <= (b->size / 2))
				rb(b);
			else if (find_biggest(b) > (b->size / 2))
				rrb(b);
		}
	}
}

void	push_all(t_stack *a, t_stack *b)
{
	while (true)
	{
		if (sorted_a(a) && b->size == 0)
			exit(0);
		pa(a, b);
	}
}
