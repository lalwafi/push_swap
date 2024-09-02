/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_try.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 04:11:32 by lalwafi           #+#    #+#             */
/*   Updated: 2024/09/02 18:59:21 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_that_stack_again(t_ps_list **stack_a, t_ps_list **stack_b)
{
	t_ps_list   *target_a;
	t_ps_list   *target_b;
	t_cost		costcal;
	int         i;
	int         flag;

  	// ft_printf("list size = %d\n", ps_lstsize(*stack_a));
	flag = 0;
	if (ps_lstsize(*stack_a) == 3)
		return (sort_three(stack_a));
	else if (ps_lstsize(*stack_a) == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			swap_a(stack_a);
		return ;
	}
	else if(ps_lstsize(*stack_a) == 4)
	{
		sort_four(stack_a, stack_b);
	}
	else if(ps_lstsize(*stack_a) == 5)
	{
		sort_five(stack_a, stack_b);
	}
	else
	{
		push_b(stack_a, stack_b);
		push_b(stack_a, stack_b);
		costcal = lowest_cost_each_target(stack_a, stack_b);
		target_a = costcal.target_a;
		target_b = costcal.target_b;
		// flag = find_flag_to_sort(target_a, target_a, stack_a, stack_b);
		// i = ps_lstsize(*stack_a);
		// ft_printf("target_a = %d\n", target_a->content);
		// ft_printf("target_b = %d\n", target_b->content);
		// ft_printf("cost = %d\n", costcal.cost);
		i = ps_lstsize(*stack_a);
		while (i-- > 0)
		{
			// ft_printf("---------------------------------------------------------- i = %d\n", i);
			costcal = lowest_cost_each_target(stack_a, stack_b);
			target_a = costcal.target_a;
			target_b = costcal.target_b;
			// ft_printf("target_a = %d  index = %d\n", target_a->content, target_a->index);
			// ft_printf("target_b = %d  index = %d\n", target_b->content, target_b->index);
			// ft_printf("-------stack_a-------\n");
			// ps_lstprint(*stack_a);
			// ft_printf("-------stack_b-------\n");
			// ps_lstprint(*stack_b);
			// ft_printf("cost = %d\n", costcal.cost);
			flag = find_flag_to_sort(target_a, target_b, stack_a, stack_b);
			// printf("flag = %d\n", flag);
			sort_it_now_pls_thx(target_a, target_b, stack_a, stack_b, flag);
			// ft_printf("---------------------------------------------------------- i = %d\n", i);
		}
		target_b = where_is_maximum(stack_b);
		// target_b = *stack_b;
		// target_b = find_maximum(stack_b, target_b);
		// ft_printf("target_b for sorting b %d\n", target_b->content);
		if (target_b->index > (ps_lstsize(*stack_b) / 2))
		{
			while (target_b->index != 0)
				reverse_rotate_b(stack_b);
		}
		else
		{
			while (target_b->index != 0)
				rotate_b(stack_b);
		}
		while (*stack_b)
			push_a(stack_a, stack_b);
	}
}

t_ps_list    *find_true_minimum(t_ps_list **stack, t_ps_list *target)
{
	t_ps_list   *temp;

	// minimum
	temp = *stack;
	while (temp)
	{
		// ft_printf("man\n");
		if (temp->next && temp->content > temp->next->content && temp->next->content < target->content)
			target = temp->next;
		temp = temp->next;
	}
	// ft_printf("target in find minimum = %d\n", target->content);
	return (target);
}

void	sort_four(t_ps_list **stack_a, t_ps_list **stack_b)
{
	t_ps_list	*temp;
	
	temp = *stack_a;
	temp = find_true_minimum(stack_a, temp);
	// ft_printf("temp = %d    index = %d\n", temp->content, temp->index);
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
		// ft_printf("biggest so far in where_is_maximum = %d\n", biggest->content);
		if (temp->content > biggest->content)
			biggest = temp;
		temp = temp->next;
	}
	return (biggest);
}

void	if_flag_zero(t_ps_list *target_a, t_ps_list *target_b, t_ps_list **stack_a, t_ps_list **stack_b)
{
	int	i;

	i = 0;
	i = target_b->index;
	if (target_a->index > target_b->index)
		i = target_a->index;
	while (i-- > 0)
	{
		// ft_printf("#####################should rotate a and b\n");
		if (target_a->index > 0 && target_b->index > 0)
			rotate_both(stack_a, stack_b);
		else if (target_a->index > 0)
			rotate_a(stack_a);
		else if (target_b->index > 0)
			rotate_b(stack_b);
	}
	push_b(stack_a, stack_b);
}

void	if_flag_one(t_ps_list *target_a, t_ps_list *target_b, t_ps_list **stack_a, t_ps_list **stack_b)
{
	int i;
	int size;

	// ft_printf("#####################if_flag_one cus flag = 1\n");
	i = target_b->index;
	if (target_a->index < target_b->index)
		i = target_a->index;
	size = ps_lstsize(*stack_a);
	if (ps_lstsize(*stack_a) < ps_lstsize(*stack_b))
		size = ps_lstsize(*stack_b);
	while (i++ < size)
	{
		// ft_printf("#####################should reverse rotate a and b\n");
		if (target_a->index > 0 && 
			target_b->index > 0)
			reverse_rotate_both(stack_a, stack_b);
		else if (target_a->index > 0)
			reverse_rotate_a(stack_a);
		else if (target_b->index > 0)
			reverse_rotate_b(stack_b);
	}
	push_b(stack_a, stack_b);
}


void	if_flag_two(t_ps_list *target_a, t_ps_list *target_b, t_ps_list **stack_a, t_ps_list **stack_b)
{
	int	i;
	int	size;

	// rotate a reverse rotate b
	i = target_a->index;
	// ft_printf("#####################if_flag_two cus flag = 2\n");
	while (i-- > 0)
	{
		if (target_a->index > 0)
			rotate_a(stack_a);
		// ft_printf("#####################should rotate a\n");
	}
	size = ps_lstsize(*stack_b);
	i = target_b->index;
	while (i++ < size)
	{
		if (target_b->index > 0)
			reverse_rotate_b(stack_b);
		// ft_printf("####################should reverse rotate b\n");
	}
	push_b(stack_a, stack_b);
}

void	if_flag_three(t_ps_list *target_a, t_ps_list *target_b, t_ps_list **stack_a, t_ps_list **stack_b)
{
	int	i;
	int	size;
	// target_a reverse rotate and target_b rotate
	i = target_b->index;
	// ft_printf("#####################if_flag_three cus flag = 3        i = %d\n", i);
	while (i-- > 0)
	{
		// ft_printf("##################### should rotate b\n");
		if (target_b->index > 0)
			rotate_b(stack_b);
	}
	size = ps_lstsize(*stack_a);
	i = target_a->index;
	while (i++ < size)
	{
		// ft_printf("##################### should reverse rotate a\n");
		if (target_a->index > 0)
			reverse_rotate_a(stack_a);
	}
	push_b(stack_a, stack_b);
}

void    sort_it_now_pls_thx(t_ps_list *target_a, t_ps_list *target_b, t_ps_list **stack_a, t_ps_list **stack_b, int flag)
{
	if (flag == 0)
		if_flag_zero(target_a, target_b, stack_a, stack_b);
	else if (flag == 1)
		if_flag_one(target_a, target_b, stack_a, stack_b);
	else if (flag == 2)
		if_flag_two(target_a, target_b, stack_a, stack_b);
	else if (flag == 3)
		if_flag_three(target_a, target_b, stack_a, stack_b);
	else if (flag == 4)
	{
		// no clue
		return ;
	}
}

// deal with if stack_a is null
int find_flag_to_sort(t_ps_list *target_a, t_ps_list *target_b, t_ps_list **stack_a, t_ps_list **stack_b)
{
	int flag;

	flag = 5;
	// if target_a and target_b need rotate                       flag = 0
	// if target_a and target_b need reverse rotate               flag = 1
	// if target_a needs rotate and target_b needs reverse rotate flag = 2
	// if target_a needs reverse rotate and target_b needs rotate flag = 3
	// if target_a doesnt exist                                   flag = 4
	if (stack_a && (*stack_a) && stack_b && (*stack_b))
	{
		if (target_a->index == 0 && target_b->index == 0)
			push_b(stack_a, stack_b);
		else if (target_a->index <= ((ps_lstsize(*stack_a) / 2) - 1) && target_b->index <= ((ps_lstsize(*stack_b) / 2) - 1))
			flag = 0;
		else if (target_a->index > ((ps_lstsize(*stack_a) / 2) - 1) && target_b->index > ((ps_lstsize(*stack_b) / 2) - 1))
			flag = 1;
		else if (target_a->index <= ((ps_lstsize(*stack_a) / 2) - 1) && target_b->index > ((ps_lstsize(*stack_b) / 2) - 1))
			flag = 2;
		else if (target_a->index > ((ps_lstsize(*stack_a) / 2) - 1) && target_b->index <= ((ps_lstsize(*stack_b) / 2) - 1))
			flag = 3;
	}
	else if (stack_b && (*stack_b))
		flag = 4;
	return (flag);
}
