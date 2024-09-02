/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_it_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:50:23 by lalwafi           #+#    #+#             */
/*   Updated: 2024/09/02 21:44:07 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_list	*find_true_minimum(t_ps_list **stack, t_ps_list *target)
{
	t_ps_list	*temp;

	temp = *stack;
	while (temp)
	{
		if (temp->next && temp->content > temp->next->content
			&& temp->next->content < target->content)
			target = temp->next;
		temp = temp->next;
	}
	return (target);
}

void	sort_four(t_ps_list **stack_a, t_ps_list **stack_b)
{
	t_ps_list	*temp;

	temp = *stack_a;
	temp = find_true_minimum(stack_a, temp);
	while (temp->index > 0)
		rotate_a(stack_a);
	push_b(stack_a, stack_b);
	sort_three(stack_a);
	push_a(stack_a, stack_b);
}

void	sort_five(t_ps_list **stack_a, t_ps_list **stack_b)
{
	t_ps_list	*temp;

	temp = *stack_a;
	temp = find_true_minimum(stack_a, temp);
	if (temp->index > ps_lstsize(*stack_a) / 2)
		while (temp->index > 0)
			reverse_rotate_a(stack_a);
	else
		while (temp->index > 0)
			rotate_a(stack_a);
	push_b(stack_a, stack_b);
	temp = *stack_a;
	temp = find_true_minimum(stack_a, temp);
	if (temp->index > ps_lstsize(*stack_a) / 2)
		while (temp->index > 0)
			reverse_rotate_a(stack_a);
	else
		while (temp->index > 0)
			rotate_a(stack_a);
	push_b(stack_a, stack_b);
	if ((*stack_b)->content < (*stack_b)->next->content)
		swap_b(stack_b);
	sort_three(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

t_ps_list	*where_is_maximum(t_ps_list	**stack_b)
{
	t_ps_list	*temp;
	t_ps_list	*biggest;

	temp = *stack_b;
	biggest = *stack_b;
	while (temp)
	{
		if (temp->content > biggest->content)
			biggest = temp;
		temp = temp->next;
	}
	return (biggest);
}
