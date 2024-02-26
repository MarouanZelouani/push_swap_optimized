/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:57:57 by mzelouan          #+#    #+#             */
/*   Updated: 2024/02/03 02:04:13 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	case_4(t_stack *to_push, t_stack *target, t_stack **a, t_stack **b)
{
	while (to_push->index != 0 && target->index != 0)
	{
		rotate_ab(a, b, 1);
		set_index_to_node(*a);
		set_index_to_node(*b);
	}
	while (target->index != 0)
	{
		rotate_a(a, 1);
		set_index_to_node(*a);
	}
	while (to_push->index != 0)
	{
		rotate_b(b, 1);
		set_index_to_node(*b);
	}
}

void	case_3(t_stack *to_push, t_stack *target, t_stack **a, t_stack **b)
{
	while (to_push->index != 0)
	{
		rotate_b(b, 1);
		set_index_to_node(*b);
	}
	while (target->index != 0)
	{
		reverse_rotate_a(a, 1);
		set_index_to_node(*a);
	}
}

void	case_2(t_stack *to_push, t_stack *target, t_stack **a, t_stack **b)
{
	while (to_push->index != 0)
	{
		reverse_rotate_b(b, 1);
		set_index_to_node(*b);
	}
	while (target->index != 0)
	{
		rotate_a(a, 1);
		set_index_to_node(*a);
	}
}

void	case_1(t_stack *to_push, t_stack *target, t_stack **a, t_stack **b)
{
	while (to_push->index != 0 && target->index != 0)
	{
		reverse_rotate_ab(a, b, 1);
		set_index_to_node(*a);
		set_index_to_node(*b);
	}
	while (target->index != 0)
	{
		reverse_rotate_a(a, 1);
		set_index_to_node(*a);
	}
	while (to_push->index != 0)
	{
		reverse_rotate_b(b, 1);
		set_index_to_node(*b);
	}
}
