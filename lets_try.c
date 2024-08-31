/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_try.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 22:12:51 by lalwafi           #+#    #+#             */
/*   Updated: 2024/08/31 04:49:16 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_that_stack(t_ps_list **stack_a, t_ps_list **stack_b)
{
	(void)stack_b;
	if (ps_lstsize(*stack_a) == 3)
		return (sort_three(stack_a));
	else if (ps_lstsize(*stack_a) == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			swap_a(stack_a);
		return ;
	}
	// else
	// {
	// 	push_b(stack_a, stack_b);
	// 	push_b(stack_a, stack_b);
	// 	check_cost(stack_a, stack_b);
	// }
}

void	calculate_cost(t_ps_list **stack_a, t_ps_list **stack_b, int index)
{
	int			i;
	int			cost;
	// long		diff_min;
	long		diff_max;
	// int			index_min;
	int			index_max;
	t_ps_list	*temp;
	t_ps_list	*iter;

	i = index;
	temp = (*stack_a);
	iter = (*stack_b);
	cost = 0;
	while (temp->index != i)
		temp = temp->next;
	if (i >= ps_lstsize(*stack_a))
	{
		while (i++ < ps_lstsize(*stack_a))
			cost++;
	}
	else
	{
		while (i-- > 0)
			cost++;
	}
	// diff_min = LONG_MAX;
	diff_max = LONG_MAX;
	while (iter->next)
	{
		// if (iter->content > temp->content && diff_min > (iter->content - temp->content))
		// {
		// 	diff_min = iter->content - temp->content;
		// 	index_min = iter->index;
		// }
		if (iter->content < temp->content && diff_max > (temp->content - iter->content))
		{
			diff_max = temp->content - iter->content;
			index_max = iter->index;
		}
		iter = iter->next;
	}
	while (index_max-- > 0)
		cost++;
	ft_printf("cost = %d\n", cost);
}

void	check_cost(t_ps_list **stack_a, t_ps_list **stack_b)
{
	t_ps_list	*temp;
	// t_ps_list	*lowest;
	
	temp = (*stack_a);
	
	while (temp->next)
	{
		calculate_cost(stack_a, stack_b, temp->index);
	}
}

void	sort_three(t_ps_list **stack_a)
{
	if ((*stack_a)->content < (*stack_a)->next->content &&
		(*stack_a)->content < (*stack_a)->next->next->content)
	{
		reverse_rotate_a(stack_a);
		swap_a(stack_a);
	}
	else if ((*stack_a)->content > (*stack_a)->next->content &&
			(*stack_a)->content < (*stack_a)->next->next->content)
		swap_a(stack_a);
	else if ((*stack_a)->content < (*stack_a)->next->content &&
			(*stack_a)->content > (*stack_a)->next->next->content)
		reverse_rotate_a(stack_a);
	else if ((*stack_a)->content > (*stack_a)->next->content &&
			(*stack_a)->content > (*stack_a)->next->next->content &&
			(*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	else if ((*stack_a)->content > (*stack_a)->next->content &&
			(*stack_a)->content > (*stack_a)->next->next->content)
		rotate_a(stack_a);
}
