/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 02:04:20 by mzelouan          #+#    #+#             */
/*   Updated: 2024/02/03 02:11:23 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	send_min_node_to_top(t_stack **a)
{
	if (get_min_in_stack(*a)->index > ft_stack_size(*a) / 2)
	{
		while (get_min_in_stack(*a)->index != 0)
		{
			reverse_rotate_a(a, 1);
			set_index_to_node(*a);
		}
	}
	else
	{
		while (get_min_in_stack(*a)->index != 0)
		{
			rotate_a(a, 1);
			set_index_to_node(*a);
		}
	}
}

t_stack	*get_to_push_node(t_stack *s)
{
	t_stack	*to_push;

	to_push = NULL;
	while (s != NULL)
	{
		if (s->to_push == 1)
		{
			to_push = s;
			break ;
		}
		s = s->next;
	}
	return (to_push);
}

void	move_chosen_node_b(t_stack **a, t_stack **b)
{
	int		stack_a_size;
	int		stack_b_size;
	t_stack	*to_push;
	t_stack	*target;

	stack_a_size = ft_stack_size(*a);
	stack_b_size = ft_stack_size(*b);
	to_push = get_to_push_node(*a);
	target = get_node(*b, to_push->target);
	if (to_push->index > stack_a_size / 2
		&& target->index > stack_b_size / 2)
		case_1_a(to_push, target, a, b);
	else if (to_push->index > stack_a_size / 2
		&& target->index <= stack_b_size / 2)
		case_3_a(to_push, target, a, b);
	else if (to_push->index <= stack_a_size / 2
		&& target->index > stack_b_size / 2)
		case_2_a(to_push, target, a, b);
	else if (to_push->index <= stack_a_size / 2
		&& target->index <= stack_b_size / 2)
		case_4_a(to_push, target, a, b);
	push_b(a, b, 1);
}

void	change_target_zero(t_stack *s)
{
	while (s != NULL)
	{
		s->to_push = 0;
		s->target = 0;
		s = s->next;
	}
}
