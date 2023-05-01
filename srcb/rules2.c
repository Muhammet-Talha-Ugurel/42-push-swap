/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:27:57 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/30 04:45:14 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rrr(t_stack *a, t_stack *b)
{
	int	temp;

	if (a->size != 0)
	{
		temp = a->stack[a->size - 1];
		move_up(a);
		a->stack[0] = temp;
	}
	if (b->size != 0)
	{
		temp = b->stack[b->size - 1];
		move_up(b);
		b->stack[0] = temp;
	}
	ft_printf("rrr\n");
}
