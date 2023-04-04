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
	ft_printf("--------------\n");
	print_stacks(a, b);
	if (ac == 3)
		two(a);
	if (ac == 4)
		three(a);
	if (ac == 5)
		//		four(a, b);
	if (ac == 6)
		//	five(a, b);
	ft_printf("--------------\n");
	print_stacks(a, b);
}

void	two(t_stack *a)
{
	if (a->stack[0] > a->stack[1])
		sa(a);
}

void	three(t_stack *a)
{
	check(a)
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
		exit (1);
	return (0);
}
//void	four(t_stack *a, t_stack *b)
//{
//}
//void	five(t_stack *a, t_stack *b)
//{
//}
