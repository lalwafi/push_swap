/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 03:24:07 by lalwafi           #+#    #+#             */
/*   Updated: 2024/09/03 17:41:27 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cost	lowest_cost_each_target(t_ps_list **stack_a, t_ps_list **stack_b)
{
	t_cost		costcal;
	t_ps_list	*temp_a;
	t_ps_list	*temp_b;
	long		cost;

	costcal.target_a = (*stack_a);
	costcal.target_b = (*stack_b);
	costcal.cost = INT64_MAX;
	temp_a = *stack_a;
	temp_b = *stack_b;
	while (temp_a)
	{
		cost = 0;
		cost += lemme_try_sorting_cost(stack_a, temp_a);
		temp_b = find_target_b(stack_b, temp_a);
		cost += lemme_try_sorting_cost(stack_b, temp_b) + 1;
		if ((cost < costcal.cost))
		{
			costcal.target_a = temp_a;
			costcal.target_b = temp_b;
			costcal.cost = cost;
		}
		temp_a = temp_a->next;
	}
	return (costcal);
}

long	lemme_try_sorting_cost(t_ps_list **stack, t_ps_list *target)
{
	long	cost;
	long	index;

	cost = 0;
	if (target->index == 0)
		return (cost);
	if (target->index >= (ps_lstsize(*stack) / 2) - 1)
	{
		index = target->index;
		while (index != (ps_lstsize(*stack) - 1))
		{
			index++;
			cost++;
		}
	}
	else
	{
		index = target->index;
		while (index != 0)
		{
			index--;
			cost++;
		}
	}
	return (cost);
}

t_ps_list	*find_target_b_cost(t_ps_list **stack_b, t_ps_list *target_a)
{
	t_ps_list	*target_b;
	int			flag;

	flag = 1;
	target_b = *stack_b;
	flag = find_flag_for_target_b_cost(stack_b, flag, target_a);
	if (flag == 0)
		return (find_maximum_cost(stack_b, target_b));
	else if (flag == 1)
		return (find_minimum_cost(stack_b, target_b));
	else if (flag == 2)
		return (find_closest_minimum_cost(stack_b, target_a));
	return (target_b);
}

int	find_flag_for_target_b_cost(t_ps_list **stack_b, int flag,
	t_ps_list *target_a)
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
