/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aec_alg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:27:57 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/30 04:45:14 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	aec_alg(t_stack *a, t_stack *b, int ac)
{
	t_stack *steps;
	
	steps = malloc(sizeof(t_stack));
	steps->size = 0;
	steps->stack = (int32_t *)malloc(STACK_SIZE);
	pb(b, a);
	pb(b, a);
	while (true)
	{
		if (a->size == 0)
			break ;
		count_steps(steps, a, b);
		send_it(a, b, find_smallest(steps));
	}
	while (true)
	{
		if (sorted_b(b))
			break ;
		rb(b);
	}
	while (true)
	{
		if (sorted_a(a) && b->size == 0)
			exit(0);
		pa(a, b);
	}
}

void	send_it(t_stack *a, t_stack *b, int o)
{
	int	ai;
	int	bi;
	int	the_number;

	the_number = a->stack[o];
	ai = steps_to_move_top(a, o);
	while (ai != 0)
	{
		if (a->size % 2 == 0)
		{
			if (o <= (a->size / 2))
				ra(a);
			else if (o > (a->size / 2))
				rra(a);
		}
		else if (a->size % 2 == 1)
		{
			if (o <= (a->size / 2))
				ra(a);
			else if (o > (a->size / 2))
				rra(a);
		}
		ai--;
	}
	bi = steps_to_move_top(b, find_the_spot(b, the_number));
	o = find_the_spot(b, the_number);
	while (bi != 0)
	{
		if (b->size % 2 == 0)
		{
			if (o <= (b->size / 2))
				rb(b);
			else if (o > (b->size / 2))
				rrb(b);
		}
		else if (b->size % 2 == 1)
		{
			if (o <= (b->size / 2))
				rb(b);
			else if (o > (b->size / 2))
				rrb(b);
		}
		bi--;
	}
	pb(b, a);
}

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
	int	steps;

	steps = 0;
	steps += steps_to_move_top(a, i);
	steps += steps_to_move_top(b, find_the_spot(b, a->stack[i]));
	steps++;
	return (steps);
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

int	find_smallest(t_stack *b)
{
	int i;
	int	small;

	i = 0;
	small = 0;
	while (b->size > i)
	{
		if (b->stack[i] < b->stack[small])
			small = i;
		i++;
	}
	return (small);
}

int	find_biggest(t_stack *b)
{
	int i;
	int	bigg;

	i = 0;
	bigg = 0;
	while (b->size > i)
	{
		if (b->stack[i] > b->stack[bigg])
			bigg = i;
		i++;
	}
	return (bigg);
}

int	find_the_spot(t_stack *b, int a)
{
	int i;
	int	biggest_small;

	i = 0;
	biggest_small = find_smallest(b);
	while (b->size > i)
	{
		if (b->stack[i] < a)
		{
			if (b->stack[i] >= b->stack[biggest_small])
				biggest_small = i;
		}
		i++;
	}
	if (a < b->stack[find_smallest(b)])
	{
		return (find_biggest(b));
	}
	return (biggest_small);
}
