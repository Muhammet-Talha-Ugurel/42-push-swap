/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:48:10 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/30 04:45:23 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdint.h>
#include "get_next_line.h"
#include "ft_printf.h"
#include "libft.h"

#define STACK_SIZE ((ac - 1) * sizeof(int32_t))

typedef struct t_stack
{
	int32_t	*stack;
	int32_t	size;
}			t_stack;

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *b, t_stack *a);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	get_them_all(t_stack *a, char **av, int ac);
void	print_stack(t_stack *a);
void	print_stacks(t_stack *a, t_stack *b);
void	move_up(t_stack *s);
void	move_down(t_stack *s);
void	two(t_stack *a);
void	three(t_stack *a);
void	four(t_stack *a, t_stack *b);
void	five(t_stack *a, t_stack *b);
void	five_up_smallest(t_stack *a);
int		check(t_stack *a);
int		smallest(t_stack *a);
int		biggest(t_stack *a);

#endif
