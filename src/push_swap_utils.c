/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:27:57 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/30 04:45:14 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_them_all(t_stack *a, char **av, int ac)
{
	int32_t	i;

	a->size = ac - 1;
	i = 0;
	while (ac - 1 > i)
	{
		a->stack[i] = ft_atoi(av[i + 1]);
		i++;
	}
}

void	move_up(t_stack *s)
{
	int32_t	i;

	i = 0;
	while (s->size >= i)
	{
		s->stack[s->size - i + 1] = s->stack[s->size - i];
		i++;
	}
}

void	move_down(t_stack *s)
{
	int32_t	i;

	i = 0;
	while (s->size > i)
	{
		s->stack[i] = s->stack[i + 1];
		i++;
	}
}

int	smallest(t_stack *a)
{
	int32_t	i;
	int32_t	index;
	int32_t	fornow;

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
	int32_t	i;
	int32_t	index;
	int32_t	fornow;

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
