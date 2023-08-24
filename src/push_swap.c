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

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		return (0);
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	a->size = 0;
	b->size = 0;
	a->stack = (int32_t *)malloc(((count_args(av, ac)) * sizeof(int32_t)));
	b->stack = (int32_t *)malloc(((count_args(av, ac)) * sizeof(int32_t)));
	ac = get_them_all(a, av, ac);
	if (ac == 2)
		two(a);
	if (ac == 3)
		three(a);
	if (ac == 4)
		four(a, b);
	if (ac == 5)
		five(a, b);
	if (ac >= 6)
		mtu_sort(a, b, ac);
	free_all(a, b);
}
