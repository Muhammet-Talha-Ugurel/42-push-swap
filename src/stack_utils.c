/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
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
	int	i;
	
	a->size = ac - 1;
	i = 0;
	while (ac - 1 > i)
	{
		a->stack[i] = ft_atoi(av[i + 1]);
		i++;
	}
}

void	print_stack(t_stack *a)
{
	int i;

	i = 0;
	while (i < a->size)
	{
		ft_printf("%d\n", a->stack[i]);
		i++;
	}
}

void	print_stacks(t_stack *a, t_stack *b)
{
	int i;

	i = 0;
	ft_printf("a-----b\n");
	while (i < a->size || i < b->size)
	{
		if (i < a->size && i < b->size)
			ft_printf("%d-----%d\n", a->stack[i], b->stack[i]);
		if (i < a->size && i >= b->size)
			ft_printf("%d----- \n", a->stack[i]);
		if (i >= a->size && i < b->size)
			ft_printf(" -----%d\n", b->stack[i]);
		i++;
	}
}

void	move_up(t_stack *s)
{
	int	i;

	i = 0;
	while (s->size >= i)
	{
		s->stack[s->size - i + 1] = s->stack[s->size - i]; 
		i++;
	}
}

void	move_down(t_stack *s)
{
	int	i;

	i = 0;
	while (s->size > i)
	{
		s->stack[i] = s->stack[i + 1];
		i++;
	}
}
