/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:27:57 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/30 04:45:14 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_stack *a)
{
	int32_t	temp;

	if (a->size > 1)
	{
		temp = a->stack[0];
		a->stack[0] = a->stack[1];
		a->stack[1] = temp;
	}
}

void	sb(t_stack *b)
{
	int32_t	temp;

	if (b->size > 1)
	{
		temp = b->stack[0];
		b->stack[0] = b->stack[1];
		b->stack[1] = temp;
	}
}

void	ss(t_stack *a, t_stack *b)
{
	int32_t	temp;

	if (a->size > 1)
	{
		temp = a->stack[0];
		a->stack[0] = a->stack[1];
		a->stack[1] = temp;
	}
	if (b->size > 1)
	{
		temp = b->stack[0];
		b->stack[0] = b->stack[1];
		b->stack[1] = temp;
	}
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->size != 0)
	{
		move_up(a);
		a->stack[0] = b->stack[0];
		a->size = a->size + 1;
		move_down(b);
		b->size = b->size - 1;
	}
}

void	pb(t_stack *b, t_stack *a)
{
	if (a->size != 0)
	{
		move_up(b);
		b->stack[0] = a->stack[0];
		b->size = b->size + 1;
		move_down(a);
		a->size = a->size - 1;
	}
}
