/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:25:54 by mzelouan          #+#    #+#             */
/*   Updated: 2024/02/03 02:22:53 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	price_for_rarb(t_stack *target, t_stack *to_push)
{
	int	price;

	price = target->index;
	if (price < to_push->index)
		price = to_push->index;
	return (price);
}

int	price_for_rrarrb(t_stack *a, t_stack *b, t_stack *tar, t_stack *push)
{
	int	price;

	price = 0;
	if (tar->index)
		price = ft_stack_size(b) - tar->index;
	if (price < (ft_stack_size(a) - push->index) && push->index)
		price = ft_stack_size(a) - push->index;
	return (price);
}

int	price_for_rrarb(t_stack *a, t_stack *target, t_stack *to_push)
{
	int	price;

	price = 0;
	if (to_push->index)
		price = ft_stack_size(a) - to_push->index;
	price += target->index;
	return (price);
}

int	price_for_rarrb(t_stack *b, t_stack *target, t_stack *to_push)
{
	int	price;

	price = 0;
	if (target->index)
		price = ft_stack_size(b) - target->index;
	price += to_push->index;
	return (price);
}
