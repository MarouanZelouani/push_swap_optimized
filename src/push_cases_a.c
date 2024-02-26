/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cases_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 00:52:40 by mzelouan          #+#    #+#             */
/*   Updated: 2024/02/03 02:26:06 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	case_1_a(t_stack *push, t_stack *tar, t_stack **a, t_stack **b)
{
	while (push->index != 0 && tar->index != 0)
	{
		reverse_rotate_ab(a, b, 1);
		set_index_to_node(*a);
		set_index_to_node(*b);
	}
	while (tar->index != 0)
	{
		reverse_rotate_b(b, 1);
		set_index_to_node(*b);
	}
	while (push->index != 0)
	{
		reverse_rotate_a(a, 1);
		set_index_to_node(*a);
	}
}

void	case_4_a(t_stack *push, t_stack *tar, t_stack **a, t_stack **b)
{
	while (push->index != 0 && tar->index != 0)
	{
		rotate_ab(a, b, 1);
		set_index_to_node(*a);
		set_index_to_node(*b);
	}
	while (tar->index != 0)
	{
		rotate_b(b, 1);
		set_index_to_node(*b);
	}
	while (push->index != 0)
	{
		rotate_a(a, 1);
		set_index_to_node(*a);
	}
}

void	case_2_a(t_stack *push, t_stack *tar, t_stack **a, t_stack **b)
{
	while (push->index != 0)
	{
		rotate_a(a, 1);
		set_index_to_node(*a);
	}
	while (tar->index != 0)
	{
		reverse_rotate_b(b, 1);
		set_index_to_node(*b);
	}
}

void	case_3_a(t_stack *push, t_stack *tar, t_stack **a, t_stack **b)
{
	while (push->index != 0)
	{
		reverse_rotate_a(a, 1);
		set_index_to_node(*a);
	}
	while (tar->index != 0)
	{
		rotate_b(b, 1);
		set_index_to_node(*b);
	}
}
