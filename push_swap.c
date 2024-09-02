/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:40:51 by lalwafi           #+#    #+#             */
/*   Updated: 2024/09/02 18:58:22 by lalwafi          ###   ########.fr       */
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
			ft_printf("failed to make_stack stack_a\n");
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
	numarray = parsing_again(av);
	stack_a = make_stack(stack_a, numarray, count_how_many(av));
	if (is_it_sorted(stack_a) == 1)
	{
		// ft_printf("not sorted\n");
		// push_b(&stack_a, &stack_b);
		// push_b(&stack_a, &stack_b);
		// ft_printf("-------stack_a-------\n");
		// ps_lstprint(stack_a);
		// ft_printf("-------stack_b-------\n");
		// ps_lstprint(stack_b);
		sort_that_stack_again(&stack_a, &stack_b);
		// sort_that_stack(&stack_a, &stack_b);
		// if (is_it_sorted(stack_a) == 1)
		// swap_a(&stack_a);
		// push_b(&stack_a, &stack_b);
		// rotate_a(&stack_a);
		// reverse_rotate_a(&stack_a);
		// reverse_rotate_b(&stack_b);
		// ft_printf("done sorting??????\n");
		// ft_printf("-------stack_a-------\n");
		// ps_lstprint(stack_a);
		// ft_printf("-------stack_b-------\n");
		// ps_lstprint(stack_b);
	}
	if (is_it_sorted(stack_a) == 0)
		ft_printf("SORTED!!!\n");
	if (is_it_sorted(stack_a) == 1)
		ft_printf("not sorted\n");
	free(numarray);
	ps_lstclear(&stack_a);
	ps_lstclear(&stack_b);
}
