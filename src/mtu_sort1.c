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

void	send_it(t_stack *a, t_stack *b, int o)
{
	t_moves	*moves;
	int32_t	the_number;

	moves = malloc(sizeof(t_moves));
	moves_init(moves);
	the_number = a->stack[o];
	send_it_a(a, moves, o);
	send_it_b(b, moves, o, the_number);
	make_the_opt_moves(a, b, moves);
	pb(b, a);
}

void	send_it_a(t_stack *a, t_moves *moves, int32_t o)
{
	int32_t	ai;

	ai = steps_to_move_top(a, o);
	while (ai != 0)
	{
		if (a->size % 2 == 0)
		{
			if (o <= (a->size / 2))
				moves->ar++;
			else if (o > (a->size / 2))
				moves->arr++;
		}
		else if (a->size % 2 == 1)
		{
			if (o <= (a->size / 2))
				moves->ar++;
			else if (o > (a->size / 2))
				moves->arr++;
		}
		ai--;
	}
}

void	send_it_b(t_stack *b, t_moves *moves, int32_t o, int32_t the_number)
{
	int32_t	bi;

	bi = steps_to_move_top(b, find_the_spot(b, the_number));
	o = find_the_spot(b, the_number);
	while (bi != 0)
	{
		if (b->size % 2 == 0)
		{
			if (o <= (b->size / 2))
				moves->br++;
			else if (o > (b->size / 2))
				moves->brr++;
		}
		else if (b->size % 2 == 1)
		{
			if (o <= (b->size / 2))
				moves->br++;
			else if (o > (b->size / 2))
				moves->brr++;
		}
		bi--;
	}
}

int	steps_to_move_top(t_stack *a, int i)
{
	if (a->size % 2 == 0)
	{
		if (i <= (a->size / 2))
			return (i);
		else if (i > (a->size / 2))
			return (a->size - i);
	}
	else if (a->size % 2 == 1)
	{
		if (i <= (a->size / 2))
			return (i);
		else if (i > (a->size / 2))
			return (a->size - i);
	}
	return (0);
}

void	make_the_opt_moves(t_stack *a, t_stack *b, t_moves *moves)
{
	while (moves->ar > 0 && moves->br > 0)
	{
		rr(a, b);
		moves->ar--;
		moves->br--;
	}
	while (moves->arr > 0 && moves->brr > 0)
	{
		rrr(a, b);
		moves->arr--;
		moves->brr--;
	}
	while (moves->ar-- > 0)
		ra(a);
	while (moves->arr-- > 0)
		rra(a);
	while (moves->br-- > 0)
		rb(b);
	while (moves->brr-- > 0)
		rrb(b);
}
