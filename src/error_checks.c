/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:57:50 by mzelouan          #+#    #+#             */
/*   Updated: 2024/02/05 04:16:26 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_all_digits(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		if (av[i][0] == '-' || av[i][0] == '+')
		{
			if (!av[i][1])
				return (0);
			else
				j++;
		}
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	exist_duplicates(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_strlen(av[i]) == ft_strlen(av[j]))
				if (ft_strncmp(av[i], av[j], ft_strlen(av[i])) == 0)
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_sorted(t_stack *s)
{
	t_stack	*current_node;

	if (s == NULL)
		return (0);
	current_node = s;
	if (s->next == NULL)
		return (1);
	while (current_node->next != NULL)
	{
		if (current_node->data > (current_node->next)->data)
			return (0);
		current_node = current_node->next;
	}
	return (1);
}

int	dup_checker(t_stack *s)
{
	t_stack	*tmp;

	while (s)
	{
		tmp = s->next;
		while (tmp)
		{
			if (tmp->data == s->data)
				return (0);
			tmp = tmp->next;
		}
		s = s->next;
	}
	return (1);
}
