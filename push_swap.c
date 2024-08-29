/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:40:51 by lalwafi           #+#    #+#             */
/*   Updated: 2024/08/29 22:46:59 by lalwafi          ###   ########.fr       */
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
	ft_printf("making stack??\n");
	while (++i < wc)
	{
		new = ps_lstnew(numarray[i], i);
		ft_printf("making stack i = %d\n", i);
		if (!new)
		{
			free(numarray);
			ps_lstclear(&stack_a);
			ft_printf("failed to make_stack stack_a\n");
			exit(EXIT_FAILURE);
		}
		ft_printf("before lstaddback\n");
		ps_lstadd_back(&stack_a, new);
		ft_printf("after lstaddback\n");
	}
	ft_printf("stack made\n");
	// i = 0;
	// new = stack_a;
	// while (new)
	// {
	// 	new->index = i;
	// 	new = new->next;
	// 	i++;
	// }
}

int	main(int ac, char **av)
{
	t_ps_list	stack_a;
	// t_ps_list	stack_b;
	int			*numarray;
	if (ac == 1)
		return (0);
	numarray = parsing_again(av);
	int i = count_how_many(av);
	while (--i >= 0)
		ft_printf("%d\n", numarray[i]);
	ft_printf("before making stack??\n");
	make_stack(&stack_a, numarray, count_how_many(av));
	ps_lstprint(&stack_a);
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