/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:40:51 by lalwafi           #+#    #+#             */
/*   Updated: 2024/08/28 07:47:24 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_double_array(char **array)
{
	int i;

	i = 0;
	if (array != NULL)
	{
		while (array[i])
			free(array[i++]);
		free(array);
	}
}

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
		// ft_printf("splitting...\n");
		idk = ft_split(av[i], ' ');
		// ft_printf("split\n");
		if (idk == NULL)
			count++;
		else
		{
			// ft_printf("else time\n");
			while (idk[j++])
				count++;
			// ft_printf("freeing idk\n");
			free_double_array(idk);
			// ft_printf("idk freed\n");
		}
		// ft_printf("setting j = 0\n");
		j = 0;
	}
	return (count);
}

int	any_letters(char *str)
{
	// int	flag;
	int	i;

	i = -1;
	// flag = 0;
	while (str[++i])
	{
		if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]) == 0 && str[i + 1] != ' ')
			return (2);
		else if (ft_isdigit(str[i]) == 0 && str[i] != ' ' && str[i] != '+' && str[i] != '-')
			return (1);
	}
	return (0);
}

char	**array_time(char **numbers, char **av, int a)
{
	char **split = NULL;
	int		n;
	int		s;
	
	n = 0;
	s = 0;
	numbers = (char **)malloc(sizeof(char *) * (a + 1));
	if (!numbers)
		(ft_printf("malloc fail\n"), exit(EXIT_FAILURE));
	a = 0;
	while (av[++a])
	{
		split = ft_split(av[a], ' ');
		if (split == NULL)
			ft_printf("---------null------\n");
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

int	*char_to_int_array(char **numbers, int count)
{
	int	*result;
	int	i;
	
	i = -1;	
	result = (int *)malloc(sizeof(int) * (count + 1));
	if (!result)
	{
		ft_printf("int malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (numbers[++i])
		result[i] = ft_atoi_ps(numbers[i]);
	return (result);
}

void	parsing_again(char **av)
{
	char **numbers = NULL;
	int		*numarray;
	int	i;
	int	wc;
	wc = count_how_many(av);
	ft_printf("wc = %d\n", wc);
	i = 0;
	while (av[++i])
	{
		if (check_for_spaces_empty(av[i]) == 1)
			(ft_printf("found spaces only :(\n"), exit(EXIT_FAILURE));
		if (check_for_spaces_empty(av[i]) == 2)
			(ft_printf("empty string found\n"), exit(EXIT_FAILURE));
		if (any_letters(av[i]) == 2)
			(ft_printf("sign without number? or non-number after sign\n"), exit(EXIT_FAILURE));
		if (any_letters(av[i]) == 1)
			(ft_printf("only numbers pls\n"), exit(EXIT_FAILURE));
	}
	numbers = array_time(numbers, av, wc);
	i = 0;
	while (numbers[i])
		ft_printf("%s\n", numbers[i++]);
	numarray = char_to_int_array(numbers, wc);
	i = wc;
	while (i > 0)
		ft_printf("%d\n", numarray[--i]);
	if (duplicates_maybe(numarray, wc) == 1)
		ft_printf("found duplicate\n");
	free_double_array(numbers);
	free(numarray);
}
int	main(int ac, char **av)
{
	// t_ps_list	stack_a;
	// t_ps_list	stack_b;
	if (ac == 1)
		return (0);
	// int i = 0;
	// int j = 0;
	// char **a = NULL;
	// while (av[++i])
	// {
	// 	a = ft_split(av[i], ' ');
	// 	if (a != NULL)
	// 		ft_printf("yea %d\n", i);
	// 	else
	// 		ft_printf("nah %d\n", i); 
	// 	if (a)
	// 	{
	// 		while (a[j])
	// 		free(a[j++]);
	// 		free(a);
	// 	}
	// }
	parsing_again(av);
	// parsing_time(av);
	// check_arguments_thing(ac, av);
}

// int main(void)
// {
// 	char *a = "7";
// 	char **b = ft_split(a, ' ');
// 	if (!b)
// 	{
// 		ft_printf("nuh uh\n");
// 		return (0);
// 	}
// 	int i = 0;
// 	while (b[i] != NULL)
// 		ft_printf("%s\n", b[i++]);
// 	return (0);
// }