/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pro.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:57:00 by mzelouan          #+#    #+#             */
/*   Updated: 2024/02/05 09:01:57 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/get_next_line.h"

char	**get_args(int ac, char **args)
{
	int		i;
	char	*str;
	char	**av;

	i = 1;
	str = NULL;
	av = NULL;
	while (i < ac)
	{
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, args[i]);
		i++;
	}
	av = ft_split(str, ' ');
	free(str);
	if (!is_all_digits(av) || !exist_duplicates(av))
	{
		ft_putstr_fd("Error\n", 2);
		free_vector(av);
		exit(-1);
	}
	return (av);
}

int	main(int ac, char **args)
{
	char	**av;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2 || args[1][0] == '\0')
		return (-1);
	av = get_args(ac, args);
	init_stack(&stack_a, av);
	free_vector(av);
	if (!dup_checker (stack_a))
	{
		ft_putstr_fd("Error\n", 2);
		free_stack (stack_a);
		return (-1);
	}
	execute_instructions(&stack_a, &stack_b);
	if (is_sorted(stack_a) && stack_b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack (stack_a);
}
