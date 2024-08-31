/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:40:51 by lalwafi           #+#    #+#             */
/*   Updated: 2024/08/31 00:37:18 by lalwafi          ###   ########.fr       */
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
	new = stack_a;
	while (new)
	{
		new->index = i;
		new = new->next;
		i++;
	}
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
		ft_printf("not sorted\n");
		sort_that_stack(&stack_a, &stack_b);
		// if (is_it_sorted(stack_a) == 1)
		// swap_a(&stack_a);
		// push_b(&stack_a, &stack_b);
		// rotate_a(&stack_a);
		// reverse_rotate_a(&stack_a);
		// reverse_rotate_b(&stack_b);
		ft_printf("-------stack_a-------\n");
		ps_lstprint(stack_a);
		ft_printf("-------stack_b-------\n");
		ps_lstprint(stack_b);
	}
	else
		ft_printf("SORTED!!!\n");
	free(numarray);
	ps_lstclear(&stack_a);
	ps_lstclear(&stack_b);
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