/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:12:53 by lalwafi           #+#    #+#             */
/*   Updated: 2024/08/28 16:14:28 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_spaces_empty(char *str)
{
	int	flag;
	int	i;

	if (!str[0])
		return (2);
	i = -1;
	flag = 0;
	while (str[++i])
	{
		if (str[i] != ' ')
			flag = 1;
	}
	if (flag == 1)
		return (0);
	return (1);
}

int	count_how_many(char **av)
{
	int count;
	int i;
	int j;
	char **idk;
	
	count = 0;
	j = 0;
	i = 0;
	while (av[++i])
	{
		idk = ft_split(av[i], ' ');
		if (idk == NULL)
			count++;
		else
		{
			while (idk[j++])
				count++;
			free_double_array(idk);
		}
		j = 0;
	}
	return (count);
}

int	any_letters(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]) == 0 && str[i + 1] != ' ')
			return (2);
		else if (ft_isdigit(str[i]) == 0 && str[i] != ' ' && str[i] != '+' && str[i] != '-')
			return (1);
	}
	return (0);
}

int	duplicates_maybe(int *numbers, int count)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < count)
	{
		while (++j < count)
		{
			if (numbers[i] == numbers[j] && i != j)
				return (1);
		}
		j = -1;
	}
	return (0);
}
