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

int	find_the_spot(t_stack *b, int a)
{
	int	i;
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
