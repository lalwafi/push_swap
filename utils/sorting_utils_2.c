/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:53:53 by lalwafi           #+#    #+#             */
/*   Updated: 2024/08/31 19:23:39 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    rotate_a(t_ps_list **stack_a)
{
	t_ps_list	*temp;
	t_ps_list	*first;

	first = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	temp = (*stack_a);
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	first->next = NULL;
	index_that_stack(stack_a);
	ft_printf("ra\n");
}

void    rotate_b(t_ps_list **stack_b)
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
	ft_printf("rb\n");
}

void	reverse_rotate_a(t_ps_list **stack_a)
{
	t_ps_list	*temp;
	t_ps_list	*man;
	
	if (!stack_a || !(*stack_a))
		return ;
	temp = (*stack_a);
	man = ps_lstlast(*stack_a);
	ps_lstadd_front(stack_a, man);
	while (temp->next != man)
		temp = temp->next;
	temp->next = NULL;
	index_that_stack(stack_a);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_ps_list **stack_b)
{
	t_ps_list	*temp;
	t_ps_list	*man;
	
	if (!stack_b || !(*stack_b))
		return ;
	temp = (*stack_b);
	man = ps_lstlast(*stack_b);
	ps_lstadd_front(stack_b, man);
	while (temp->next != man)
		temp = temp->next;
	temp->next = NULL;
	index_that_stack(stack_b);
	ft_printf("rrb\n");
}