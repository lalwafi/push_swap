/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_try_again.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 09:14:04 by lalwafi           #+#    #+#             */
/*   Updated: 2024/09/01 13:46:52 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_that_stack(t_ps_list **stack_a, t_ps_list **stack_b)
{
    t_ps_list   *target_a;
    t_ps_list   *target_b;
    int         i;

	if (ps_lstsize(*stack_a) == 3)
		return (sort_three(stack_a));
	else if (ps_lstsize(*stack_a) == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			swap_a(stack_a);
		return ;
	}
	else
	{
		// ft_printf("-------stack_a-------\n");
		// ps_lstprint(*stack_a);
		// ft_printf("-------stack_b-------\n");
		// ps_lstprint(*stack_b);
        target_a = *stack_a;
        i = ps_lstsize(*stack_a);
        // ft_printf("list size of stack_a = %d\n", i);
        while (i-- > 0)
        {
            target_b = find_target_b(stack_b, target_a);
		    lemme_try_sorting_solo(stack_a, stack_b, target_a, target_b);
            // ft_printf("-------stack_a-------\n");
	    	// ps_lstprint(*stack_a);
	    	// ft_printf("-------stack_b-------\n");
	    	// ps_lstprint(*stack_b);
            if (i > 0)
                target_a = what_element_is_index(stack_a, 0);
        }
        target_b = find_maximum(stack_b, target_b);
        if (target_b->index >= (ps_lstsize(*stack_b) / 2) - 1)
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
	// sort_it(stack_a, stack_b, cost_stuff);
}

t_ps_list   *find_target_b(t_ps_list **stack_b, t_ps_list *target_a)
{
    t_ps_list   *target_b;
    int         flag;
    
    flag = 1;
    target_b = *stack_b;
    flag = find_flag_for_target_b(stack_b, flag, target_a);
    if (flag == 0)
        return (find_maximum(stack_b, target_b));
    else if (flag == 1)
        return (find_minimum(stack_b, target_b));
    else if (flag == 2)
        return(find_closest_minimum(stack_b, target_a));
    return (target_b);
}

int find_flag_for_target_b(t_ps_list **stack_b, int flag, t_ps_list *target_a)
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

t_ps_list    *find_minimum(t_ps_list **stack, t_ps_list *target)
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

t_ps_list    *find_maximum(t_ps_list **stack, t_ps_list *target)
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

t_ps_list    *find_closest_minimum(t_ps_list **stack, t_ps_list *target)
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

void	lemme_try_sorting_solo(t_ps_list **stack_a, t_ps_list **stack_b, t_ps_list *target_a, t_ps_list *target_b)
{
	// int i;

    (void)target_a;
	if (target_b->index >= (ps_lstsize(*stack_b) / 2) - 1)
	{
        // ft_printf("if b in sort solo\n");
        // i = target_b->index - 1;
        // ft_printf("list size = %d\n", ps_lstsize(*stack_b));
		while (target_b->index != 0){
            // ft_printf("target_b->index = %d\n", target_b->index);
			reverse_rotate_b(stack_b);
        }
	}
	else
	{
        // ft_printf("else b in sort solo\n");
        // i = target_b->index + 1;
        // ft_printf("list size = %d\n", ps_lstsize(*stack_b));
		while (target_b->index != 0){
            // ft_printf("target_b->index = %d\ni = %d\n", target_b->index, i);
			rotate_b(stack_b);
        }
	}
	push_b(stack_a, stack_b);
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
