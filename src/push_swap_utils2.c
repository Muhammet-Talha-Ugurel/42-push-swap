/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:27:57 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/30 04:45:14 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_stack *b)
{
	int32_t	i;
	int32_t	small;

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
	int32_t	i;
	int32_t	bigg;

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
