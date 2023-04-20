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
	while (true)
	{
		if (sorted_a(a) && b->size == 0)
			exit(0);
		pa(a, b);
	}
}

void	moves_init(t_moves *moves)
{
	moves->ar = 0;
	moves->arr = 0;
	moves->br = 0;
	moves->brr = 0;
}

void	send_it(t_stack *a, t_stack *b, int o)
{
	t_moves	*moves;
	int			ai;
	int			bi;
	int			the_number;

	moves = malloc(sizeof(t_moves));
	moves_init(moves);
	the_number = a->stack[o];
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
	make_the_opt_moves(a, b, moves);
	pb(b, a);
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

int	sorted_a(t_stack *a)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (a->size - 2 >= i)
	{
		if (a->stack[i] > a->stack[i + 1])
			flag = 1;
		i++;
	}
	if (flag == 1)
		return (0);
	return (1);
}

int	sorted_b(t_stack *b)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (b->size - 2 >= i)
	{
		if (b->stack[i] < b->stack[i + 1])
			flag = 1;
		i++;
	}
	if (flag == 1)
		return (0);
	return (1);
}

int	positive(int num)
{
	if (num < 0)
		num = num * -1;
	return (num);
}
