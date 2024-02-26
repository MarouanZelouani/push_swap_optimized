/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:58:24 by mzelouan          #+#    #+#             */
/*   Updated: 2024/02/03 02:22:16 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_target(t_stack *a, t_stack *b)
{
	long	target_index;
	t_stack	*current;

	while (b != NULL)
	{
		target_index = LONG_MAX;
		current = a;
		while (current != NULL)
		{
			if (current->data > b->data && current->data < target_index)
				target_index = current->data;
			current = current->next;
		}
		if (target_index == LONG_MAX)
			b->target = get_min_in_stack(a)->data;
		else
			b->target = target_index;
		b = b->next;
	}
}

int	calculate_price(t_stack *a, t_stack *b, t_stack *c, t_stack *t)
{
	int	total_price;

	total_price = price_for_rarb_a(t, c);
	if (total_price > price_for_rarrb_a(a, t, c))
		total_price = price_for_rarrb_a(b, t, c);
	if (total_price > price_for_rrarb_a(a, t, c))
		total_price = price_for_rrarb_a(a, t, c);
	if (total_price > price_for_rrarrb_a(a, b, t, c))
		total_price = price_for_rrarrb_a(a, b, t, c);
	return (total_price);
}

int	calculate_price_a(t_stack *a, t_stack *b, t_stack *c, t_stack *t)
{
	int	total_price;

	total_price = price_for_rarb(t, c);
	if (total_price > price_for_rarrb(a, t, c))
		total_price = price_for_rarrb(b, t, c);
	if (total_price > price_for_rrarb(a, t, c))
		total_price = price_for_rrarb(a, t, c);
	if (total_price > price_for_rrarrb(a, b, t, c))
		total_price = price_for_rrarrb(a, b, t, c);
	return (total_price);
}

void	set_node_to_push(t_stack *a, t_stack *b)
{
	t_stack	*chosen_node;
	t_stack	*head;

	head = b;
	chosen_node = NULL;
	while (b != NULL)
	{
		if (chosen_node == NULL
			|| calculate_price(a, head, b, get_node(a, b->target))
			< calculate_price(a, head, chosen_node,
				get_node(a, chosen_node->target)))
			chosen_node = b;
		b = b->next;
	}
	if (chosen_node != NULL)
		chosen_node->to_push = 1;
}
