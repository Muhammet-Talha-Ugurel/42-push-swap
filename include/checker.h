/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:48:10 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/30 04:45:23 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdint.h>
# include <stdbool.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"

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
int		get_them_all(t_stack *a, char **av, int ac);
void	move_up(t_stack *s);
void	move_down(t_stack *s);
void	check_args(char **av, int ac);
void	handle_error(char *str);
void	check_dup(t_stack *a, int32_t num);
int		sorted_a(t_stack *a);

#endif
