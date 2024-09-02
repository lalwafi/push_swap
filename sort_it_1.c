/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_it_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 04:11:32 by lalwafi           #+#    #+#             */
/*   Updated: 2024/09/02 21:43:29 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_that_stack_again(t_ps_list **stack_a, t_ps_list **stack_b)
{
	if (ps_lstsize(*stack_a) == 3)
		return (sort_three(stack_a));
	else if (ps_lstsize(*stack_a) == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			swap_a(stack_a);
		return ;
	}
	else if (ps_lstsize(*stack_a) == 4)
	{
		sort_four(stack_a, stack_b);
	}
	else if (ps_lstsize(*stack_a) == 5)
	{
		sort_five(stack_a, stack_b);
	}
	else
	{
		sorting_time(stack_a, stack_b);
		sort_and_push_b(stack_a, stack_b);
	}
}

void	sort_and_push_b(t_ps_list **stack_a, t_ps_list **stack_b)
{
	t_ps_list	*target_b;

	target_b = where_is_maximum(stack_b);
	if (target_b->index > (ps_lstsize(*stack_b) / 2))
		while (target_b->index != 0)
			reverse_rotate_b(stack_b);
	else
		while (target_b->index != 0)
			rotate_b(stack_b);
	while (*stack_b)
		push_a(stack_a, stack_b);
}

void	sorting_time(t_ps_list **stack_a, t_ps_list **stack_b)
{
	t_ps_list	*target_a;
	t_ps_list	*target_b;
	t_cost		costcal;
	int			i;

	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	costcal = lowest_cost_each_target(stack_a, stack_b);
	target_a = costcal.target_a;
	target_b = costcal.target_b;
	i = ps_lstsize(*stack_a);
	while (i-- > 0)
	{
		costcal = lowest_cost_each_target(stack_a, stack_b);
		target_a = costcal.target_a;
		target_b = costcal.target_b;
		sort_it_now_pls_thx(target_a, target_b, stack_a, stack_b);
	}
}

void	sort_it_now_pls_thx(t_ps_list *target_a, t_ps_list *target_b,
	t_ps_list **stack_a, t_ps_list **stack_b)
{
	int	flag;

	flag = find_flag_to_sort(target_a, target_b, stack_a, stack_b);
	if (flag == 0)
		if_flag_zero(target_a, target_b, stack_a, stack_b);
	else if (flag == 1)
		if_flag_one(target_a, target_b, stack_a, stack_b);
	else if (flag == 2)
		if_flag_two(target_a, target_b, stack_a, stack_b);
	else if (flag == 3)
		if_flag_three(target_a, target_b, stack_a, stack_b);
	else if (flag == 4)
		return ;
}
