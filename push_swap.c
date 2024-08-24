/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:40:51 by lalwafi           #+#    #+#             */
/*   Updated: 2024/08/24 15:47:32 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	check_arguments_thing(int ac, char **av)
// {
// 	int	i;
// 	int	j;
// 	int	count;
// 	int	flag;

// 	flag = 0;
// 	count = 0;
// 	i = 0;
// 	j = 0;
// 	while (av[++i])
// 	{
// 		while (av[i][j] && flag == 0)
// 		{
// 			if (av[i][j] == ' ')
// 			{
// 				// ft_printf("found space\n");
// 				count++;
// 				flag = 1;
// 			}
// 			j++;
// 		}
// 		// if (flag == 0)
// 		// 	count++;
// 		flag = 0;
// 		j = 0;
// 	}
// 	ft_printf("count = %d\nac = %d\n", count, (ac - 1));
// 	// count if needs to be split, then count how many there would be
// 	// and then do the split and allocate to a double pointer with only the numbers 
// }

// void	parsing_time(char **av)
// {
// 	char	**numbers;
// 	int		i;
// 	int		j;
// 	int		k;
// 	int		wordcount;
	
// 	i = 0;
// 	j = 0;
// 	k = 0;
// 	wordcount = 0;
// 	while (av[++i])
// 	{
// 		numbers = ft_split(av[i], ' ');
// 		if (numbers[k])
// 		{
// 			while (numbers[k])
// 			{
// 				while (numbers[k][j])
// 				{
// 					if (ft_isdigit(numbers[k][j]) == 0)
// 					{
// 						wordcount = -5;
// 						break ;
// 					}
// 					j++;
// 				}
// 				k++;
// 			}
// 		}
// 		else
// 			wordcount++;
// 		j = -1;
// 		k = 0;
// 		while (numbers[++j])
// 			free(numbers[j]);
// 		free(numbers);
// 		j = 0;
// 	}
// 	if (wordcount == -5)
// 		(ft_printf("nuh uh\n"), exit (EXIT_FAILURE));
// }

void	free_double_array(char **array)
{
	int i;

	i = -1;
	if (array)
	{
		while (array[++i])
			free(array[i]);
		free(array);
	}
}

int	check_for_spaces(char *str)
{
	int	flag;
	int	i;

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
			while (idk[j++] != NULL)
				count++;
			free_double_array(idk);
		}
		j = 0;
	}
	return (count);
}

int	any_letters(char *str)
{
	int	flag;
	int	i;

	i = -1;
	flag = 0;
	while (str[++i])
	{
		if (ft_isdigit(str[i]) == 0 && str[i] != ' ')
			flag = 1;
	}
	if (flag == 1)
		return (1);
	return (0);
}

char	**array_time(char **numbers, char **av, int a)
{
	char **split = NULL;
	int		n;
	int		s;
	
	n = 0;
	s = 0;
	numbers = (char **)malloc(sizeof(char **) * (a + 1));
	if (!numbers)
		(ft_printf("malloc fail\n"), exit(EXIT_FAILURE));
	a = 0;
	while (av[++a])
	{
		split = ft_split(av[a], ' ');
		if (split == NULL)
			numbers[n++] = av[a];
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

void	parsing_again(char **av)
{
	char **numbers = NULL;
	int	i;
	int	wc;
	wc = count_how_many(av);
	ft_printf("wc = %d\n", wc);
	i = 0;
	while (av[++i])
	{
		if (check_for_spaces(av[i]) == 1)
			(ft_printf("found spaces only :(\n"), exit(EXIT_FAILURE));
		if (any_letters(av[i]) == 1)
			(ft_printf("only numbers pls\n"), exit(EXIT_FAILURE));
	}
	numbers = array_time(numbers, av, wc);
	i = 0;
	while (numbers[i])
		ft_printf("%s\n", numbers[i++]);
		
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