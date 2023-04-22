/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:27:57 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/30 04:45:14 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_steps(t_stack *steps, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	steps->size = a->size;
	while (i < a->size)
	{
		steps->stack[i] = count_steps_one_item(a, b, i);
		i++;
	}
}

int	count_steps_one_item(t_stack *a, t_stack *b, int i)
{
	t_moves	*moves;
	int32_t	steps;
	int32_t	j;

	j = 0;
	moves = malloc(sizeof(t_moves));
	moves_init(moves);
	steps = 0;
	steps_to_move_top_a(a, i, moves);
	steps_to_move_top_b(b, find_the_spot(b, a->stack[i]), moves);
	steps += calc_steps(moves, j);
	steps++;
	return (steps);
}

int	calc_steps(t_moves *moves, int32_t i)
{
	while (moves->ar > 0 && moves->br > 0)
	{
		moves->ar--;
		moves->br--;
		i++;
	}
	while (moves->arr > 0 && moves->brr > 0)
	{
		moves->arr--;
		moves->brr--;
		i++;
	}
	while (moves->ar-- > 0)
		i++;
	while (moves->arr-- > 0)
		i++;
	while (moves->br-- > 0)
		i++;
	while (moves->brr-- > 0)
		i++;
	return (i);
}

void	steps_to_move_top_b(t_stack *a, int32_t i, t_moves *moves)
{
	if (a->size % 2 == 0)
	{
		if (i <= (a->size / 2))
			moves->br = i;
		else if (i > (a->size / 2))
			moves->brr = a->size - i;
	}
	else if (a->size % 2 == 1)
	{
		if (i <= (a->size / 2))
			moves->br = i;
		else if (i > (a->size / 2))
			moves->brr = a->size - i;
	}
}

void	steps_to_move_top_a(t_stack *a, int32_t i, t_moves *moves)
{
	if (a->size % 2 == 0)
	{
		if (i <= (a->size / 2))
			moves->ar = i;
		else if (i > (a->size / 2))
			moves->arr = a->size - i;
	}
	else if (a->size % 2 == 1)
	{
		if (i <= (a->size / 2))
			moves->ar = i;
		else if (i > (a->size / 2))
			moves->arr = a->size - i;
	}
}
