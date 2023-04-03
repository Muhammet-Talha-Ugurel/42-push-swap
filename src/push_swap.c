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

#define STACK_SIZE ((ac - 1) * sizeof(int32_t))

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
	int ia;
	int ib;

	ia = 0;
	ib = 0;
	while (ia < a->size)
	{
		ft_printf("%d\n", a->stack[ia]);
		ia++;
	}
	while (ib < b->size)
	{
		ft_printf("%d\n", b->stack[ib]);
		ib++;
	}
	//fix tish this not right
}

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack	*b;

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	a->stack = (int32_t *)malloc(STACK_SIZE);
	b->stack = (int32_t *)malloc(STACK_SIZE);
	get_them_all(a, av, ac);
	print_stack(a);
	sa(a);
	print_stack(a);
}
