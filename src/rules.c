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

void	sa(t_stack *a)
{
	int32_t temp;

	if(a->size > 1)
	{
		temp = a->stack[0];
		a->stack[0] = a->stack[1];
		a->stack[1] = temp;
	}
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	int32_t temp;

	if(b->size > 1)
	{
		temp = b->stack[0];
		b->stack[0] = b->stack[1];
		b->stack[1] = temp;
	}
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	int32_t temp;

	if(a->size > 1)
	{
		temp = a->stack[0];
		a->stack[0] = a->stack[1];
		a->stack[1] = temp;
	}
	if(b->size > 1)
	{
		temp = b->stack[0];
		b->stack[0] = b->stack[1];
		b->stack[1] = temp;
	}
	ft_printf("ss\n");
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->size != 0)
	{
		move_up(a);
		a->stack[0] = b->stack[0];
		a->size = a->size + 1;
		move_down(b);
		b->size = b->size - 1;
	}
	ft_printf("pa\n");
}

void	pb(t_stack *b, t_stack *a)
{
	if (a->size != 0)
	{
		move_up(b);
		b->stack[0] = a->stack[0];
		b->size = b->size + 1;
		move_down(a);
		a->size = a->size - 1;
	}
	ft_printf("pb\n");
}

void	ra(t_stack *a)
{
	int	temp;
	
	if (a->size != 0)
	{
		temp = a->stack[0];
		move_down(a);
		a->stack[a->size - 1] = temp;
	}
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	int	temp;
	
	if (b->size != 0)
	{
		temp = b->stack[0];
		move_down(b);
		b->stack[b->size - 1] = temp;
	}
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	int	temp;
	
	if (a->size != 0)
	{
		temp = a->stack[0];
		move_down(a);
		a->stack[a->size - 1] = temp;
	}
	if (b->size != 0)
	{
		temp = b->stack[0];
		move_down(b);
		b->stack[b->size - 1] = temp;
	}
	ft_printf("rr\n");
}

void	rra(t_stack *a)
{
	int	temp;
	
	if (a->size != 0)
	{
		temp = a->stack[a->size - 1];
		move_up(a);
		a->stack[0] = temp;
	}
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	int	temp;
	
	if (b->size != 0)
	{
		temp = b->stack[b->size - 1];
		move_up(b);
		b->stack[0] = temp;
	}
	ft_printf("rrb\n");
}

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
