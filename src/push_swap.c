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
	t_stack *a;
	t_stack	*b;

	if (ac == 1)
		return (0);
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	a->size = 0;
	b->size = 0;
	a->stack = (int32_t *)malloc(STACK_SIZE);
	b->stack = (int32_t *)malloc(STACK_SIZE);
	get_them_all(a, av, ac);
	if (ac == 3)
		two(a);
	if (ac == 4)
		three(a);
	if (ac == 5)
		four(a, b);
	if (ac == 6)
		five(a, b);
}

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

int	smallest(t_stack *a)
{
	int		i;
	int		index;
	int		fornow;

	i = 1;
	index = 0;
	fornow = a->stack[0];
	while (a->size - 1 >= i)
	{
		if (fornow > a->stack[i])
		{
			fornow = a->stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	biggest(t_stack *a)
{
	int		i;
	int		index;
	int		fornow;

	i = 1;
	index = a->size - 1;
	fornow = a->stack[0];
	while (a->size - 1 >= i)
	{
		if (fornow < a->stack[i])
		{
			fornow = a->stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	check(t_stack *a)
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
	exit (1);
}
