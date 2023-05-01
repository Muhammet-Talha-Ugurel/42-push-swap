/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:27:57 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/30 04:45:14 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*str;

	if (ac == 1)
		return (0);
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	a->size = 0;
	b->size = 0;
	a->stack = (int32_t *)malloc(((ac - 1) * sizeof(int32_t)));
	b->stack = (int32_t *)malloc(((ac - 1) * sizeof(int32_t)));
	ac = get_them_all(a, av, ac);
	while (true)
	{
		str = get_next_line(0);
		if (str == NULL)
		{
			ft_printf("Fail\n");
			exit(0);
		}
		if (!ft_strncmp("sa", str, 2))
			sa(a);
		else if (!ft_strncmp("sb", str, 2))
			sb(b);
		else if (!ft_strncmp("ss", str, 2))
			ss(a, b);
		else if (!ft_strncmp("pa", str, 2))
			pa(a, b);
		else if (!ft_strncmp("pb", str, 2))
			pb(b, a);
		else if (!ft_strncmp("rra", str, 3))
			rra(a);
		else if (!ft_strncmp("rrb", str, 3))
			rrb(b);
		else if (!ft_strncmp("rrr", str, 3))
			rrr(a, b);
		else if (!ft_strncmp("ra", str, 2))
			ra(a);
		else if (!ft_strncmp("rb", str, 2))
			rb(b);
		else if (!ft_strncmp("rr", str, 2))
			rr(a, b);
		free(str);
		if (sorted_a(a) && b->size == 0)
		{
			ft_printf("Succses\n");
			exit(0);
		}
	}
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
