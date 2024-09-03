/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:15:22 by lalwafi           #+#    #+#             */
/*   Updated: 2024/09/03 15:54:16 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parsing_time(char **av)
{
	char	**numbers;
	int		*numarray;
	int		i;
	int		wc;

	numbers = NULL;
	wc = count_how_many(av);
	i = 0;
	while (av[++i])
	{
		if (check_for_spaces_empty(av[i]) == 1)
			(ft_printf("Error\n"), exit(EXIT_FAILURE));
		if (check_for_spaces_empty(av[i]) == 2)
			(ft_printf("Error\n"), exit(EXIT_FAILURE));
		if (any_letters(av[i]) == 2)
			(ft_printf("Error\n"), exit(EXIT_FAILURE));
		if (any_letters(av[i]) == 1)
			(ft_printf("Error\n"), exit(EXIT_FAILURE));
	}
	numbers = array_time(numbers, av, wc);
	numarray = char_to_int_array(numbers, wc);
	i = wc;
	if (duplicates_maybe(numarray, wc) == 1)
		(ft_printf("Error\n"), free(numarray), exit(EXIT_FAILURE));
	return (numarray);
}

char	**array_time(char **numbers, char **av, int a)
{
	char	**split;
	int		n;
	int		s;

	n = 0;
	s = 0;
	numbers = (char **)malloc(sizeof(char *) * (a + 1));
	if (!numbers)
		(ft_printf("Error\n"), exit(EXIT_FAILURE));
	a = 0;
	while (av[++a])
	{
		split = ft_split(av[a], ' ');
		if (split == NULL)
			(ft_printf("Error\n"), exit(EXIT_FAILURE));
		else
		{
			while (split[s])
				numbers[n++] = ft_strdup(split[s++]);
			free_double_array(split);
		}
		s = 0;
	}
	numbers[n] = NULL;
	return (numbers);
}

int	*char_to_int_array(char **numbers, int count)
{
	int	*result;
	int	i;
	int	valid;

	i = -1;
	valid = 1;
	result = (int *)malloc(sizeof(int) * (count + 1));
	if (!result)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	while (numbers[++i] && valid == 1)
		result[i] = ft_atoi_ps(numbers[i], &valid);
	free_double_array(numbers);
	if (valid == 0)
	{
		free(result);
		exit(EXIT_FAILURE);
	}
	return (result);
}

void	index_that_stack(t_ps_list **stack)
{
	int			i;
	t_ps_list	*temp;

	i = 0;
	temp = (*stack);
	while (temp)
	{
		temp->index = i;
		i++;
		temp = temp->next;
	}
}
