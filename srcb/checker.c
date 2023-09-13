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

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (ac == 1)
		return (0);
	alocate_stack(a, b, av, ac);
	ac = get_them_all(a, av, ac);
	while (true)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		compare(str, a, b);
	}
	if (sorted_a(a) && b->size == 0)
		ft_printf("Success\n");
	else
		ft_printf("Fail\n");
	free_all(a, b);
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

int	count_args(char **av, int ac)
{
	int32_t	i;
	char	*str;
	char	**split;

	str = ft_strdup("");
	i = 0;
	while (ac - 1 > i)
	{
		str = ft_strjoin(str, av[i + 1]);
		str = ft_strjoin(str, " ");
		i++;
	}
	split = ft_split(str, ' ');
	i = 0;
	while (split[i])
	{
		i++;
	}
	return (i);
}

void	free_all(t_stack *a, t_stack *b)
{
	free(a->stack);
	free(b->stack);
	free(a);
	free(b);
}

void	compare(char *str, t_stack *a, t_stack *b)
{
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
	else
		handle_error("Fail\n");
	free(str);
}
