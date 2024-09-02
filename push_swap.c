/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:40:51 by lalwafi           #+#    #+#             */
/*   Updated: 2024/09/02 20:43:32 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_double_array(char **array)
{
	int	i;

	i = 0;
	if (array != NULL)
	{
		while (array[i])
			free(array[i++]);
		free(array);
	}
}

t_ps_list	*make_stack(t_ps_list *stack_a, int *numarray, int wc)
{
	int			i;
	t_ps_list	*new;

	i = -1;
	while (++i < wc)
	{
		new = ps_lstnew(numarray[i]);
		if (!new)
		{
			free(numarray);
			ps_lstclear(&stack_a);
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		ps_lstadd_back(&stack_a, new);
	}
	i = 0;
	index_that_stack(&stack_a);
	return (stack_a);
}

int	main(int ac, char **av)
{
	t_ps_list	*stack_a;
	t_ps_list	*stack_b;
	int			*numarray;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	numarray = parsing_time(av);
	stack_a = make_stack(stack_a, numarray, count_how_many(av));
	if (is_it_sorted(stack_a) == 1)
		sort_that_stack_again(&stack_a, &stack_b);
	if (is_it_sorted(stack_a) == 0)
		ft_printf("SORTED!!!\n");
	if (is_it_sorted(stack_a) == 1)
		ft_printf("not sorted\n");
	free(numarray);
	ps_lstclear(&stack_a);
	ps_lstclear(&stack_b);
}
