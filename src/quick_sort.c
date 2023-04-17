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

void	quick_sort(t_stack *a, t_stack *b, int ac)
{
	int		pivot;
	t_stack *sorted;
	
	pivot = 0;
	sorted = malloc(sizeof(t_stack));
	sorted->size = 0;
	sorted->stack = (int32_t *)malloc(STACK_SIZE);
	while (true)
	{
		if (sorted_a(a) && b->size == 0)
			exit(0);
		push_a_stack(a, b, sorted, pivot);
		push_b_stack(a, b, sorted, pivot);
	}
}

void	push_a_stack(t_stack *a, t_stack *b, t_stack *sorted, int pivot)
{
	int 	get_it_back;
	bool	is_pivot_last;

	get_it_back = 0;
	while (a->size != 0)
	{
		if (sorted_a(a))
			break ;
		pivot = chose_pivot_a(a, sorted);
		if (pivot == a->stack[a->size - 1])
			is_pivot_last = true;
		else
			is_pivot_last = false;
		while (a->stack[0] != pivot)
		{
			if (is_pivot_last)
			{
				if (a->stack[0] < pivot)
					pb(b, a);
				else if (a->stack[0] > pivot)
					ra(a);
			}
			else if (!is_pivot_last)
			{
				if (a->stack[0] < pivot)
					pb(b, a);
				else if (a->stack[0] > pivot)
				{
					ra(a);
					get_it_back++;
				}
			}
		}
		sorted->stack[sorted->size] = pivot;
		sorted->size++;
		pb(b, a);
		if (!is_pivot_last)
		{
			while (get_it_back != 0)
			{
				rra(a);
				get_it_back--;
			}
		}
	}
}

void	push_b_stack(t_stack *a, t_stack *b, t_stack *sorted, int pivot)
{
	int get_it_back;
	bool	is_pivot_last;

	get_it_back = 0;
	while (b->size != 0)
	{
		if (!sorted_a(a) && sorted_b(b))
			break ;
		pivot = chose_pivot_b(b, sorted);
		if (pivot == b->stack[b->size - 1])
			is_pivot_last = true;
		else
			is_pivot_last = false;
		while (b->stack[0] != pivot)
		{
			if (is_pivot_last)
			{
				if (b->stack[0] < pivot)
					rb(b);
				else if (b->stack[0] > pivot)
					pa(a, b);
			}
			else if (!is_pivot_last)
			{
				if (b->stack[0] < pivot)
				{
					rb(b);
					get_it_back++;
				}
				else if (b->stack[0] > pivot)
					pa(a, b);
			}
		}
		sorted->stack[sorted->size] = pivot;
		sorted->size++;
		pa(a, b);
		if (!is_pivot_last)
		{
			while (get_it_back != 0)
			{
				rrb(b);
				get_it_back--;
			}
		}
	}
}

int	distance(int num)
{
	if (num < 0)
		num = num * -1;
	return (num);
}

int	find_mid(t_stack *a)
{
	int	i;
	int	j;
	int	mid;
	int	mid_diff;
	int	small;
	int	big;

	i = 0;
	j = 0;
	mid = 0;
	mid_diff = 2147483647;
	while (a->size > i)
	{
		big = 0;
		small = 0; 
		while (a->size > j)
		{
			if (a->stack[j] < a->stack[i])
				small++;
			else if (a->stack[j] > a->stack[i])
				big++;
			j++;
		}
		if (distance(small - big) < mid_diff)
		{
			mid = i;
			mid_diff = distance(small - big);
		}
		j = 0;
		i++;
	}
	return (mid);
}

int	chose_pivot_a(t_stack *a, t_stack *sorted)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (!is_it_sorted(a->stack[i], sorted))
			if (is_it_sorted(a->stack[i + 1], sorted))
				return (a->stack[i]);
		i++;
	}
	return (a->stack[a->size - 1]);
}

int	chose_pivot_b(t_stack *b, t_stack *sorted)
{
	int	i;

	i = 0;
	while (i < b->size - 1)
	{
		if (!is_it_sorted(b->stack[i], sorted))
			if (is_it_sorted(b->stack[i + 1], sorted))
				return (b->stack[i]);
		i++;
	}
	return (b->stack[b->size - 1]);
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
	while (b->size - 2 >= i)
	{
		if (b->stack[i] < b->stack[i + 1])
			flag = 1;
		i++;
	}
	if (flag == 1)
		return (0);
	return (1);
}
