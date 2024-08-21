/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:40:51 by lalwafi           #+#    #+#             */
/*   Updated: 2024/08/21 22:31:57 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_arguments_thing(int ac, char **av)
{
	int	i;
	int j;
	int count;
	int	flag;

	flag = 0;
	count = 0;
	i = 0;
	j = 0;
	while (av[++i])
	{
		while (av[i][j] && flag == 0)
		{
			if (av[i][j] == ' ')
			{
				// ft_printf("found space\n");
				count++;
				flag = 1;
			}
			j++;
		}
		// if (flag == 0)
		// 	count++;
		flag = 0;
		j = 0;
	}
	ft_printf("count = %d\nac = %d\n", count, (ac - 1));
	// count if needs to be split, then count how many there would be
	// and then do the split and allocate to a double pointer with only the numbers 
}

// void	parsing_time(int ac, char **av)
// {
// 	char	**numbers;
// 	int		i;
	
// 	check
	
// }

int	main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	// int i = 0;
	// while (av[++i])
	// {
	// 	if (ft_split(av[i], ' ') != NULL)
	// 		ft_printf("yea %d\n", i);
	// 	else
	// 		ft_printf("nah %d\n", i); 
	// }
	// parsing_time(ac, av);
	check_arguments_thing(ac, av);
}
