/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 03:24:07 by lalwafi           #+#    #+#             */
/*   Updated: 2024/09/02 08:51:53 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// itterate stack_a and find the target_b for it, and calculate the cost for 
// both to be brought up plus push b
// first see cost to bring target_a to index 0 then find its target_b and see
// the cost to bring target_b to index 0 then add one more cost for pb 

t_cost	lowest_cost_each_target(t_ps_list **stack_a, t_ps_list **stack_b)
{
	t_cost 		costcal;
	t_ps_list	*temp_a;
	t_ps_list	*temp_b;
	int			cost;
	// int     	i;

	if (!stack_a || !*stack_a || !stack_b ||!*stack_b)
	{
		costcal.target_a = (*stack_a);
		costcal.target_b = (*stack_b);
		costcal.cost     = INT_MAX;
	}
	temp_a = *stack_a;
	temp_b = *stack_b;
	while (temp_a)
	{
		cost = 0;
		ft_printf("reset cost\n");
		ft_printf("temp_a = %d\n", temp_a->content);
		cost += lemme_try_sorting_cost(stack_a, temp_a);
		ft_printf("inside cost calculator a = %d\n", cost);
		temp_b = find_target_b(stack_b, temp_a);
		// ft_printf("temp_b after find_target_b = %d\n", temp_b->content);
		cost += lemme_try_sorting_cost(stack_b, temp_b);
		ft_printf("inside cost calculator b = %d\n", cost);
		// for push_b
		cost += 1;
		ft_printf("inside cost calculator final = %d\n", cost);
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

int	lemme_try_sorting_cost(t_ps_list **stack, t_ps_list *target)
{
	int cost;
	int	index;

	cost = 0;
	// ft_printf("in lemme_sort_cost target = %d\n", target->content);
	if (target->index == 0)
		return (cost);
	if (target->index >= (ps_lstsize(*stack) / 2) - 1)
	{
		index = target->index;
		// reverse rotate
		ft_printf("lemme try sorting cost target = %d   index = %d   list size = %d\n", target->content, target->index, (ps_lstsize(*stack) - 1));
		while (index != (ps_lstsize(*stack) - 1))
		{
			ft_printf("hi\n");
			index++;
			cost++;
		}
	}
	else
	{
		index = target->index;
		ft_printf("lemme try sorting cost target = %d   index = %d\n", target->content, target->index);
		while (index != 0)
		{
			ft_printf("hi\n");
			index--;
			cost++;
		}
	}
	return (cost);
}

t_ps_list   *find_target_b_cost(t_ps_list **stack_b, t_ps_list *target_a)
{
	t_ps_list   *target_b;
	int         flag;
	
	flag = 1;
	target_b = *stack_b;
	flag = find_flag_for_target_b_cost(stack_b, flag, target_a);
	if (flag == 0)
		return (find_maximum_cost(stack_b, target_b));
	else if (flag == 1)
		return (find_minimum_cost(stack_b, target_b));
	else if (flag == 2)
		return(find_closest_minimum_cost(stack_b, target_a));
	return (target_b);
}

int find_flag_for_target_b_cost(t_ps_list **stack_b, int flag, t_ps_list *target_a)
{
	t_ps_list   *temp;

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

t_ps_list    *find_minimum_cost(t_ps_list **stack, t_ps_list *target)
{
	t_ps_list   *temp;

	// minimum
	temp = *stack;
	while (temp)
	{
		// ft_printf("man\n");
		if (temp->next && temp->content < temp->next->content && temp->next->content > target->content)
			target = temp->next;
		temp = temp->next;
	}
	// ft_printf("target in find minimum = %d\n", target->content);
	return (target);
}

t_ps_list    *find_maximum_cost(t_ps_list **stack, t_ps_list *target)
{
	t_ps_list   *temp;
	
	// maximum
	// ft_printf("hi\n");
	temp = *stack;
	while (temp)
	{
		if (temp->next && temp->content < temp->next->content && temp->next->content > target->content)
			target = temp->next;
		temp = temp->next;
	}
	// ft_printf("target should be maximum = %d\n", target->content);
	return (target);
}

t_ps_list    *find_closest_minimum_cost(t_ps_list **stack, t_ps_list *target)
{
	int          i;
	t_ps_list   *temp;
	t_ps_list   *result;
	// closest maximum wrong
	// should be closest mibnimum
	i = INT_MAX;
	temp = *stack;
	while (temp)
	{
		if (temp->content < target->content && i > (target->content - temp->content))
		{
			i = target->content - temp->content;
			result = temp;
		}
		temp = temp->next;
	}
	return (result);
}

