/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:18:31 by lalwafi           #+#    #+#             */
/*   Updated: 2024/09/02 20:33:53 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_list	*find_minimum_cost(t_ps_list **stack, t_ps_list *target)
{
	t_ps_list	*temp;

	temp = *stack;
	while (temp)
	{
		if (temp->next && temp->content < temp->next->content && \
			temp->next->content > target->content)
			target = temp->next;
		temp = temp->next;
	}
	return (target);
}

t_ps_list	*find_maximum_cost(t_ps_list **stack, t_ps_list *target)
{
	t_ps_list	*temp;

	temp = *stack;
	while (temp)
	{
		if (temp->next && temp->content < temp->next->content
			&& temp->next->content > target->content)
			target = temp->next;
		temp = temp->next;
	}
	return (target);
}

t_ps_list	*find_closest_minimum_cost(t_ps_list **stack, t_ps_list *target)
{
	int			i;
	t_ps_list	*temp;
	t_ps_list	*result;

	i = INT_MAX;
	temp = *stack;
	while (temp)
	{
		if (temp->content < target->content
			&& i > (target->content - temp->content))
		{
			i = target->content - temp->content;
			result = temp;
		}
		temp = temp->next;
	}
	return (result);
}
