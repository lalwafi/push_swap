/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 00:21:29 by lalwafi           #+#    #+#             */
/*   Updated: 2024/08/30 04:00:08 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_it_sorted(t_ps_list *stack_a)
{
	t_ps_list	*idk;
	if (!stack_a)
		return (0);
	idk = stack_a;
	while (idk->next != NULL)
	{
		if (idk->content < idk->next->content)
			idk = idk->next;
		else
			return (1);
	}
	return (0);
}

void    swap_a(t_ps_list **stack_a)
{
	int temp;

	if (stack_a)
	{
		temp = (*stack_a)->content;
		(*stack_a)->content = (*stack_a)->next->content;
		(*stack_a)->next->content = temp; 
	}
}

void    swap_b(t_ps_list **stack_b)
{
	int temp;

	if (stack_b)
	{
		temp = (*stack_b)->content;
		(*stack_b)->content = (*stack_b)->next->content;
		(*stack_b)->next->content = temp; 
	}
}

void    push_a(t_ps_list **stack_a, t_ps_list **stack_b)
{
	t_ps_list   *temp;
	
	if (stack_b)
	{
		temp = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		ps_lstadd_front(stack_a, ps_lstnew(temp->content));
		free(temp);
	}
}

void    push_b(t_ps_list **stack_a, t_ps_list **stack_b)
{
	t_ps_list   *temp;
	
	if (*stack_a)
	{
		temp = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		ps_lstadd_front(stack_b, ps_lstnew(temp->content));
		free(temp);
	}
}

void    rotate_a(t_ps_list **stack_a)
{
	t_ps_list	temp;
	t_ps_list
}
