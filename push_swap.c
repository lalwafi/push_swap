/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:40:51 by lalwafi           #+#    #+#             */
/*   Updated: 2024/08/28 18:06:08 by lalwafi          ###   ########.fr       */
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

void	make_stack(t_ps_list *stack_a, int *numarray, int wc)
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
			ps_lstclear(&stack_a, free);
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
}

int	main(int ac, char **av)
{
	t_ps_list	stack_a;
	// t_ps_list	stack_b;
	int			*numarray;
	if (ac == 1)
		return (0);
	numarray = parsing_again(av);
	make_stack(&stack_a, numarray, count_how_many(av));
	free(numarray);
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