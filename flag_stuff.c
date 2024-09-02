/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:51:39 by lalwafi           #+#    #+#             */
/*   Updated: 2024/09/02 20:37:58 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_flag_to_sort(t_ps_list *target_a, t_ps_list *target_b,
	t_ps_list **stack_a, t_ps_list **stack_b)
{
	int	flag;

	flag = 5;
	if (stack_a && (*stack_a) && stack_b && (*stack_b))
	{
		if (target_a->index == 0 && target_b->index == 0)
			push_b(stack_a, stack_b);
		else if (target_a->index <= ((ps_lstsize(*stack_a) / 2) - 1)
			&& target_b->index <= ((ps_lstsize(*stack_b) / 2) - 1))
			flag = 0;
		else if (target_a->index > ((ps_lstsize(*stack_a) / 2) - 1)
			&& target_b->index > ((ps_lstsize(*stack_b) / 2) - 1))
			flag = 1;
		else if (target_a->index <= ((ps_lstsize(*stack_a) / 2) - 1)
			&& target_b->index > ((ps_lstsize(*stack_b) / 2) - 1))
			flag = 2;
		else if (target_a->index > ((ps_lstsize(*stack_a) / 2) - 1)
			&& target_b->index <= ((ps_lstsize(*stack_b) / 2) - 1))
			flag = 3;
	}
	else if (stack_b && (*stack_b))
		flag = 4;
	return (flag);
}

void	if_flag_zero(t_ps_list *target_a, t_ps_list *target_b,
	t_ps_list **stack_a, t_ps_list **stack_b)
{
	int	i;

	i = 0;
	i = target_b->index;
	if (target_a->index > target_b->index)
		i = target_a->index;
	while (i-- > 0)
	{
		if (target_a->index > 0 && target_b->index > 0)
			rotate_both(stack_a, stack_b);
		else if (target_a->index > 0)
			rotate_a(stack_a);
		else if (target_b->index > 0)
			rotate_b(stack_b);
	}
	push_b(stack_a, stack_b);
}

void	if_flag_one(t_ps_list *target_a, t_ps_list *target_b,
	t_ps_list **stack_a, t_ps_list **stack_b)
{
	int	i;
	int	size;

	i = target_b->index;
	if (target_a->index < target_b->index)
		i = target_a->index;
	size = ps_lstsize(*stack_a);
	if (ps_lstsize(*stack_a) < ps_lstsize(*stack_b))
		size = ps_lstsize(*stack_b);
	while (i++ < size)
	{
		if (target_a->index > 0 && target_b->index > 0)
			reverse_rotate_both(stack_a, stack_b);
		else if (target_a->index > 0)
			reverse_rotate_a(stack_a);
		else if (target_b->index > 0)
			reverse_rotate_b(stack_b);
	}
	push_b(stack_a, stack_b);
}

void	if_flag_two(t_ps_list *target_a, t_ps_list *target_b,
	t_ps_list **stack_a, t_ps_list **stack_b)
{
	int	i;
	int	size;

	i = target_a->index;
	while (i-- > 0)
	{
		if (target_a->index > 0)
			rotate_a(stack_a);
	}
	size = ps_lstsize(*stack_b);
	i = target_b->index;
	while (i++ < size)
	{
		if (target_b->index > 0)
			reverse_rotate_b(stack_b);
	}
	push_b(stack_a, stack_b);
}

void	if_flag_three(t_ps_list *target_a, t_ps_list *target_b,
	t_ps_list **stack_a, t_ps_list **stack_b)
{
	int	i;
	int	size;

	i = target_b->index;
	while (i-- > 0)
	{
		if (target_b->index > 0)
			rotate_b(stack_b);
	}
	size = ps_lstsize(*stack_a);
	i = target_a->index;
	while (i++ < size)
	{
		if (target_a->index > 0)
			reverse_rotate_a(stack_a);
	}
	push_b(stack_a, stack_b);
}
