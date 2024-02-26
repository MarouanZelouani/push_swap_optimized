/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:58:11 by mzelouan          #+#    #+#             */
/*   Updated: 2024/02/04 20:51:41 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack **s)
{
	t_stack	*first;
	t_stack	*secound;
	t_stack	*current;

	if (ft_stack_size(*s) < 2)
		return ;
	first = *s;
	secound = (*s)->next;
	current = secound;
	while (current->next != NULL)
		current = current->next;
	first->next = NULL;
	current->next = first;
	*s = secound;
}

void	rotate_a(t_stack **a, int true)
{
	rotate(a);
	if (true)
		ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_stack **b, int true)
{
	rotate(b);
	if (true)
		ft_putstr_fd("rb\n", 1);
}

void	rotate_ab(t_stack **a, t_stack **b, int true)
{
	rotate(a);
	rotate(b);
	if (true)
		ft_putstr_fd("rr\n", 1);
}
