/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:27:57 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/30 04:45:14 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	moves_init(t_moves *moves)
{
	moves->ar = 0;
	moves->arr = 0;
	moves->br = 0;
	moves->brr = 0;
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
