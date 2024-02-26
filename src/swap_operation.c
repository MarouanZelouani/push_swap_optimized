/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:58:32 by mzelouan          #+#    #+#             */
/*   Updated: 2024/02/04 20:52:28 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **s)
{
	t_stack	*tmp;

	if (ft_stack_size(*s) < 2)
		return ;
	tmp = *s;
	*s = (*s)->next;
	tmp->next = (*s)->next;
	(*s)->next = tmp;
}

void	swap_a(t_stack **a, int true)
{
	swap(a);
	if (true)
		ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_stack **b, int true)
{
	swap(b);
	if (true)
		ft_putstr_fd("sb\n", 1);
}

void	swap_ab(t_stack **a, t_stack **b, int true)
{
	swap(a);
	swap(b);
	if (true)
		ft_putstr_fd("ss\n", 1);
}
