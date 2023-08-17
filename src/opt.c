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

void	two(t_stack *a)
{
	if (a->stack[0] > a->stack[1])
		sa(a);
}

void	three(t_stack *a)
{
	check(a);
	if (a->stack[0] < a->stack[1])
	{
		if (a->stack[0] > a->stack[2])
			rra(a);
		else
		{
			rra(a);
			sa(a);
		}
	}
	else
	{
		if (a->stack[0] < a->stack[2])
			sa(a);
		else if (a->stack[1] < a->stack[2])
			ra(a);
		else
		{
			sa(a);
			rra(a);
		}
	}
}

void	four(t_stack *a, t_stack *b)
{
	check(a);
	if (smallest(a) == 1)
	{
		ra(a);
		check(a);
	}
	else if (smallest(a) == 2)
	{
		rra(a);
		rra(a);
		check(a);
	}
	else if (smallest(a) == 3)
	{
		rra(a);
		check(a);
	}
	pb(b, a);
	three(a);
	pa(a, b);
}

void	five(t_stack *a, t_stack *b)
{
	five_up_smallest(a);
	pb(b, a);
	four(a, b);
	pa(a, b);
}

void	five_up_smallest(t_stack *a)
{
	check(a);
	if (smallest(a) == 1)
	{
		ra(a);
		check(a);
	}
	else if (smallest(a) == 2)
	{
		ra(a);
		ra(a);
		check(a);
	}
	else if (smallest(a) == 3)
	{
		rra(a);
		rra(a);
		check(a);
	}
	else if (smallest(a) == 4)
	{
		rra(a);
		check(a);
	}
}
