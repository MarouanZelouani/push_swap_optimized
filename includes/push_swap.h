/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:57:31 by mzelouan          #+#    #+#             */
/*   Updated: 2024/02/26 00:56:40 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../lib/libft/libft.h"

typedef struct stack
{
	int				data;
	int				index;
	int				to_push;
	int				target;
	struct stack	*next;
}	t_stack;

void	b_set_target(t_stack *a, t_stack *b);
void	a_set_node_to_push(t_stack *a, t_stack *b);
int		calculate_price_a(t_stack *a, t_stack *b, t_stack *c, t_stack *t);
int		calculate_price(t_stack *a, t_stack *b, t_stack *c, t_stack *t);
void	init_stack(t_stack **stack_a, char **av);
int		is_all_digits(char **av);
int		exist_duplicates(char **av);
int		is_sorted(t_stack *s);
int		ft_stack_size(t_stack *s);
t_stack	*get_min_in_stack(t_stack *s);
t_stack	*get_max_in_stack(t_stack *s);
void	send_min_node_to_top(t_stack **a);
t_stack	*get_to_push_node(t_stack *s);
void	change_target_zero(t_stack *s);
void	push_back_to_stack_a(t_stack **a, t_stack **b);
void	set_index_to_node(t_stack *s);
void	set_node_to_push(t_stack *a, t_stack *b);
t_stack	*get_node(t_stack *s, int data);
void	set_target(t_stack *a, t_stack *b);
void	set_up_nodes(t_stack *a, t_stack *b);
void	set_up_nodes_for_a(t_stack *a, t_stack *b);
void	case_1(t_stack *to_push, t_stack *target, t_stack **a, t_stack **b);
void	case_2(t_stack *to_push, t_stack *target, t_stack **a, t_stack **b);
void	case_3(t_stack *to_push, t_stack *target, t_stack **a, t_stack **b);
void	case_4(t_stack *to_push, t_stack *target, t_stack **a, t_stack **b);
void	case_1_a(t_stack *to_push, t_stack *target, t_stack **a, t_stack **b);
void	case_2_a(t_stack *to_push, t_stack *target, t_stack **a, t_stack **b);
void	case_3_a(t_stack *to_push, t_stack *target, t_stack **a, t_stack **b);
void	case_4_a(t_stack *to_push, t_stack *target, t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	sort_stack(t_stack **a, t_stack **b);
void	sort_stack(t_stack **a, t_stack **b);
void	move_chosen_node(t_stack **a, t_stack **b);
void	move_chosen_node_b(t_stack **a, t_stack **b);
int		price_for_rarb(t_stack *target, t_stack *to_push);
int		price_for_rrarrb(t_stack *a, t_stack *b, t_stack *tar, t_stack *push);
int		price_for_rrarb(t_stack *a, t_stack *target, t_stack *to_push);
int		price_for_rarrb(t_stack *b, t_stack *target, t_stack *to_push);
int		price_for_rarb_a(t_stack *target, t_stack *to_push);
int		price_for_rrarrb_a(t_stack *a, t_stack *b, t_stack *tar, t_stack *push);
int		price_for_rrarb_a(t_stack *a, t_stack *target, t_stack *to_push);
int		price_for_rarrb_a(t_stack *b, t_stack *target, t_stack *to_push);
void	swap(t_stack **s);
void	swap_a(t_stack **a, int true);
void	swap_b(t_stack **b, int true);
void	swap_ab(t_stack **a, t_stack **b, int true);
void	push(t_stack **s, t_stack *top);
t_stack	*pop(t_stack **s);
void	push_a(t_stack **a, t_stack **b, int true);
void	push_b(t_stack **a, t_stack **b, int true);
void	rotate(t_stack **s);
void	rotate_a(t_stack **a, int true);
void	rotate_b(t_stack **b, int true);
void	rotate_ab(t_stack **a, t_stack **b, int true);
void	reverse_rotate(t_stack **s);
void	reverse_rotate_a(t_stack **a, int true);
void	reverse_rotate_b(t_stack **b, int true);
void	reverse_rotate_ab(t_stack **a, t_stack **b, int true);
void	execute_instructions(t_stack **a, t_stack **b);
void	free_vector(char **av);
void	free_stack(t_stack *head);
int		dup_checker(t_stack *s);

void sort_UwU (t_stack **a, t_stack **b);

#endif
