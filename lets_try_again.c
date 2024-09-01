/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_try_again.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 09:14:04 by lalwafi           #+#    #+#             */
/*   Updated: 2024/09/01 10:41:23 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_that_stack(t_ps_list **stack_a, t_ps_list **stack_b)
{
    t_ps_list   *target_a;
    t_ps_list   *target_b;

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
		push_b(stack_a, stack_b);
		push_b(stack_a, stack_b);
		ft_printf("-------stack_a-------\n");
		ps_lstprint(*stack_a);
		ft_printf("-------stack_b-------\n");
		ps_lstprint(*stack_b);
        target_a = *stack_a;
        while (target_a)
        {
            target_b = find_target_b(stack_b, target_a);
		    lemme_try_sorting_solo(stack_a, stack_b, target_a, target_b);
            ft_printf("-------stack_a-------\n");
	    	ps_lstprint(*stack_a);
	    	ft_printf("-------stack_b-------\n");
	    	ps_lstprint(*stack_b);
            target_a = what_element_is_index(stack_a, 0);
        }
	}
	// sort_it(stack_a, stack_b, cost_stuff);
}

t_ps_list   *find_target_b(t_ps_list **stack_b, t_ps_list *target_a)
{
    t_ps_list   *target_b;
    t_ps_list   *temp;
    int         flag;
    
    flag = 0;
    target_b = *stack_b;
    temp = *stack_b;
    while (temp)
    {
        if (temp->content > target_a->content)
            flag = 1;
        temp = temp->next;
        // ft_printf("\nhi\n");
    }
    if (flag == 1)
    {
        while (temp)
        {
            if (temp->content < target_a->content)
                flag = 0;
            temp = temp->next;
        }
    }
    // checks if theres any bigger in b than target_a, if not it looks for maximum flag 1
    // if number is lowest than everything in b theres no check flag 2
    // ft_printf("hello\n");
    if (flag == 1)
    {
        // closest maximum
        // ft_printf("hi\n");
        temp = *stack_b;
        while (temp)
        {
            if (temp->next && temp->content < temp->next->content && temp->next->content > target_b->content)
                target_b = temp->next;
            temp = temp->next;
        }
        // ft_printf("hi\n");
        return (target_b);
    }
    else if (flag == 0)
    {
        // closest minimum
        temp = *stack_b;
        while (temp)
        {
            // ft_printf("man\n");
            if (temp->next && temp->content < temp->next->content && temp->next->content < target_b->content)
                target_b = temp->next;
            temp = temp->next;
        }
    }
    return (target_b);
}

void	lemme_try_sorting_solo(t_ps_list **stack_a, t_ps_list **stack_b, t_ps_list *target_a, t_ps_list *target_b)
{
	int i;

    if (target_a->index >= (ps_lstsize(*stack_a) / 2))
	{
        ft_printf("if1 in sort solo\n");
        i = target_a->index;
		while (i++ != ps_lstsize(*stack_a))
			reverse_rotate_a(&target_a);
	}
	else
	{
        ft_printf("else1 in sort solo\n");
        i = target_a->index;
		while (i-- != 0)
			rotate_a(&target_a);
	}
	if (target_b->index >= (ps_lstsize(*stack_b) / 2))
	{
        ft_printf("if2 in sort solo\n");
        i = target_b->index;
		while (i++ != ps_lstsize(*stack_b)){
			reverse_rotate_a(&target_b);
            ft_printf("target_b->index = %d\n", target_b->index);
        }
	}
	else
	{
        ft_printf("else2 in sort solo\n");
        i = target_b->index;
		while (i-- != 0)
			rotate_a(&target_b);
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
