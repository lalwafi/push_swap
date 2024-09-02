/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 04:22:10 by lalwafi           #+#    #+#             */
/*   Updated: 2024/09/02 16:53:15 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    rotate_b_for_rotate_both(t_ps_list **stack_b)
{
	t_ps_list	*temp;
	t_ps_list	*first;

	first = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	temp = (*stack_b);
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	first->next = NULL;
	index_that_stack(stack_b);
}

void    rotate_both(t_ps_list **stack_a, t_ps_list **stack_b)
{
	t_ps_list	*temp;
	t_ps_list	*first;

	if (stack_a && (*stack_a))
	{
		first = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		temp = (*stack_a);
		while (temp->next)
			temp = temp->next;
		temp->next = first;
		first->next = NULL;
		index_that_stack(stack_a);
	}
	if (stack_b && (*stack_b))
		rotate_b_for_rotate_both(stack_b);
	ft_printf("rr\n");
}

void    reverse_rotate_both(t_ps_list **stack_a, t_ps_list **stack_b)
{
	t_ps_list	*temp;
	t_ps_list	*man;
	
	if (stack_a && (*stack_a))
	{
		temp = (*stack_a);
		man = ps_lstlast(*stack_a);
		ps_lstadd_front(stack_a, man);
		while (temp->next != man)
			temp = temp->next;
		temp->next = NULL;
		index_that_stack(stack_a);
	}
	if (stack_b && (*stack_b))
	{
		temp = (*stack_b);
		man = ps_lstlast(*stack_b);
		ps_lstadd_front(stack_b, man);
		while (temp->next != man)
			temp = temp->next;
		temp->next = NULL;
		index_that_stack(stack_b);
	}
	ft_printf("rrr\n");
}
