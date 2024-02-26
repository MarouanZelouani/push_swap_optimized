/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:58:02 by mzelouan          #+#    #+#             */
/*   Updated: 2024/02/04 20:56:28 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack **s, t_stack *top)
{
	top->next = *s;
	*s = top;
}

t_stack	*pop(t_stack **s)
{
	t_stack	*tmp;

	if (s == NULL || *s == NULL)
		return (NULL);
	tmp = *s;
	*s = (*s)->next;
	return (tmp);
}

void	push_a(t_stack **a, t_stack **b, int true)
{
	t_stack	*top;

	top = pop(b);
	if (top == NULL)
		return ;
	push(a, top);
	if (true)
		ft_putstr_fd("pa\n", 1);
}

void	push_b(t_stack **a, t_stack **b, int true)
{
	t_stack	*top;

	top = pop(a);
	if (top == NULL)
		return ;
	push(b, top);
	if (true)
		ft_putstr_fd("pb\n", 1);
}
