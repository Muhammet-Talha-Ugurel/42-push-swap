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

void	quick_sort(t_stack *a, t_stack *b)
{
	int		pivot;
	static t_stack *sorted;
	
	sorted = malloc(sizeof(t_stack));
	sorted->size = 0;
	sorted->stack = (int32_t *)malloc(STACK_SIZE);
	while (true)
	{
		if (check(a) && b->size == 0)
			exit(0);
		pivot = chose_pivot_a(a, sorted);
		push_a_stack();
		pivot = chose_pivot_b(b, sorted);
		push_b_stack();
	}
}

void	push_a_stack(t_stack *a, t_stack *b, t_stack *sorted, int pivot)
{
	while (a->size < 1 && sorted)
	{
	}
}

void	push_b_stack(t_stack *a, t_stack *b, t_stack *sorted, int pivot)
{
}

int	chose_pivot_a(t_stack *a, t_stack *sorted)
{
	int	i;

	i = 0;
	if (sorted->size == 0)
		return (a->size);
	while (i < a->size - 1)
	{
		if (!is_it_sorted(a->stack[i]))
			if (is_it_sorted(a->stack[i + 1]))
				return (i);
		i++;
	}
}

int	chose_pivot_b(t_stack *b, t_stack *sorted)
{
	int	i;

	i = 0;
	if (sorted->size == 0)
		return (b->size);
	while (i < b->size - 1)
	{
		if (!is_it_sorted(b->stack[i], sorted))
			if (is_it_sorted(b->stack[i + 1], sorted))
				return (i);
		i++;
	}
}

int	is_it_sorted(int n, t_stack *sorted)
{
	int i;

	i = 0;
	while (sorted->size > i)
	{
		if (n == sorted->stack[i])
			return (1);
		i++;
	}
	return (0);
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

int	sorted_b(t_stack *b)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (b->size - 2 <= i)
	{
		if (b->stack[i] > b->stack[i + 1])
			flag = 1;
		i++;
	}
	if (flag == 1)
		return (0);
	return (1);
}
