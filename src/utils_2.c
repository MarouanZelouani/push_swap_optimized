/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 02:11:08 by mzelouan          #+#    #+#             */
/*   Updated: 2024/02/03 02:11:33 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_back_to_stack_a(t_stack **a, t_stack **b)
{
	while (*b)
	{
		set_up_nodes(*a, *b);
		move_chosen_node(a, b);
	}
}

void	move_chosen_node(t_stack **a, t_stack **b)
{
	int		stack_a_size;
	int		stack_b_size;
	t_stack	*to_push;
	t_stack	*target;

	stack_a_size = ft_stack_size(*a);
	stack_b_size = ft_stack_size(*b);
	to_push = get_to_push_node(*b);
	target = get_node(*a, to_push->target);
	if (to_push->index > stack_b_size / 2
		&& target->index > stack_a_size / 2)
		case_1(to_push, target, a, b);
	else if (to_push->index > stack_b_size / 2
		&& target->index <= stack_a_size / 2)
		case_2(to_push, target, a, b);
	else if (to_push->index <= stack_b_size / 2
		&& target->index > stack_a_size / 2)
		case_3(to_push, target, a, b);
	else
		case_4(to_push, target, a, b);
	push_a(a, b, 1);
}

void	set_index_to_node(t_stack *s)
{
	int	i;

	i = 0;
	while (s != NULL)
	{
		s->index = i;
		i++;
		s = s->next;
	}
}

t_stack	*get_max_in_stack(t_stack *s)
{
	t_stack	*max;

	max = s;
	s = s->next;
	while (s != NULL)
	{
		if (s->data > max->data)
			max = s;
		s = s->next;
	}
	return (max);
}
