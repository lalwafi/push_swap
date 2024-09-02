/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   im_gonna_keep_these.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:00:57 by lalwafi           #+#    #+#             */
/*   Updated: 2024/09/02 14:39:07 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
