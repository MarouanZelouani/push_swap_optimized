/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:58:15 by mzelouan          #+#    #+#             */
/*   Updated: 2024/02/03 02:06:22 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_the_greater(t_stack *s, t_stack *to_test)
{
	while (s != NULL)
	{
		if (s->data > to_test->data)
			return (0);
		s = s->next;
	}
	return (1);
}

void	sort_three(t_stack **a)
{
	if (is_the_greater(*a, *a))
		rotate_a(a, 1);
	else if (is_the_greater(*a, (*a)->next))
		reverse_rotate_a(a, 1);
	if ((*a)->data > ((*a)->next)->data)
		swap_a(a, 1);
}
