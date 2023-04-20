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
#include <stdbool.h>
#include "get_next_line.h"
#include "ft_printf.h"
#include "libft.h"

#define STACK_SIZE ((ac - 1) * sizeof(int32_t))

typedef struct t_stack
{
	int32_t	*stack;
	int32_t	size;
}			t_stack;

typedef struct t_moves
{
	int32_t	ar;
	int32_t	arr;
	int32_t	br;
	int32_t	brr;
}			t_moves;

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
int		sorted_a(t_stack *a);
int		sorted_b(t_stack *b);
void	aec_alg(t_stack *a, t_stack *b, int ac);
void	count_steps(t_stack *steps, t_stack *a, t_stack *b);
int		count_steps_one_item(t_stack *a, t_stack *b, int i);
int		steps_to_move_top(t_stack *a, int i);
int		find_the_spot(t_stack *b, int a);
int		find_smallest(t_stack *b);
int		find_biggest(t_stack *b);
void	send_it(t_stack *a, t_stack *b, int o);
void	make_the_opt_moves(t_stack *a, t_stack *b, t_moves *moves);
void	moves_init(t_moves *moves);
int		positive(int num);

#endif
