/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_it_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:00:57 by lalwafi           #+#    #+#             */
/*   Updated: 2024/09/04 03:55:57 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_ps_list **stack_a)
{
	if (is_it_sorted(*stack_a) == 0)
		return ;
	if ((*stack_a)->content < (*stack_a)->next->content
		&& (*stack_a)->content < (*stack_a)->next->next->content)
	{
		reverse_rotate_a(stack_a);
		swap_a(stack_a);
	}
	else if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content < (*stack_a)->next->next->content)
		swap_a(stack_a);
	else if ((*stack_a)->content < (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content)
		reverse_rotate_a(stack_a);
	else if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	else if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content)
		rotate_a(stack_a);
}

t_ps_list	*what_element_is_index(t_ps_list **stack, int whatindex)
{
	t_ps_list	*temp;

	if (whatindex == -5)
		return (NULL);
	temp = (*stack);
	while (temp->index != whatindex)
		temp = temp->next;
	return (temp);
}

t_ps_list	*find_target_b(t_ps_list **stack_b, t_ps_list *target_a)
{
	t_ps_list	*target_b;
	int			flag;

	flag = 1;
	target_b = *stack_b;
	flag = find_flag_for_target_b(stack_b, flag, target_a);
	if (flag == 0)
		return (find_maximum(stack_b, target_b));
	else if (flag == 1)
		return (find_minimum(stack_b, target_b));
	else if (flag == 2)
		return (find_closest_minimum(stack_b, target_a));
	return (target_b);
}

int	find_flag_for_target_b(t_ps_list **stack_b, int flag, t_ps_list *target_a)
{
	t_ps_list	*temp;

	flag = 1;
	temp = *stack_b;
	while (temp)
	{
		if (temp->content > target_a->content)
			flag = 0;
		temp = temp->next;
	}
	temp = *stack_b;
	if (flag == 0)
	{
		while (temp)
		{
			if (temp->content < target_a->content)
				flag = 2;
			temp = temp->next;
		}
	}
	return (flag);
}
