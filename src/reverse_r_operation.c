/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_r_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:58:07 by mzelouan          #+#    #+#             */
/*   Updated: 2024/02/04 20:51:56 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_stack **s)
{
	t_stack	*second_last;
	t_stack	*last;

	if (ft_stack_size(*s) < 2)
		return ;
	last = *s;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *s;
	*s = last;
}

void	reverse_rotate_a(t_stack **a, int true)
{
	reverse_rotate(a);
	if (true)
		ft_putstr_fd("rra\n", 1);
}

void	reverse_rotate_b(t_stack **b, int true)
{
	reverse_rotate(b);
	if (true)
		ft_putstr_fd("rrb\n", 1);
}

void	reverse_rotate_ab(t_stack **a, t_stack **b, int true)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (true)
		ft_putstr_fd("rrr\n", 1);
}
