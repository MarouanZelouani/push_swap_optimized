/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:58:19 by mzelouan          #+#    #+#             */
/*   Updated: 2024/02/26 01:17:42 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_up_nodes(t_stack *a, t_stack *b)
{
	set_index_to_node(a);
	set_index_to_node(b);
	set_target(a, b);
	set_node_to_push(a, b);
}

void	set_up_nodes_for_a(t_stack *a, t_stack *b)
{
	set_index_to_node(a);
	set_index_to_node(b);
	b_set_target(a, b);
	a_set_node_to_push(a, b);
}

void	push_to_stack_b(t_stack **a, t_stack **b)
{
	if (ft_stack_size(*a) > 3 && !is_sorted(*a))
		push_b(a, b, 1);
	if (ft_stack_size(*a) > 3 && !is_sorted(*a))
		push_b(a, b, 1);
	if (ft_stack_size(*a) > 3 && !is_sorted(*a))
	{
		while (ft_stack_size(*a) > 3 && !is_sorted(*a))
		{
			set_up_nodes_for_a (*a, *b);
			move_chosen_node_b(a, b);
		}
	}
	if (!is_sorted(*a))
		sort_three(a);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	if (ft_stack_size(*a) == 2)
		swap_a(a, 1);
	else if (ft_stack_size(*a) == 3)
		sort_three(a);
	else if (ft_stack_size(*a))
	{
		// push_to_stack_b(a, b);
		// change_target_zero(*a);
		// change_target_zero(*b);
		// push_back_to_stack_a(a, b);
		// set_index_to_node(*a);
		// send_min_node_to_top(a);

		// testing
		sort_UwU (a, b);
	}
}
