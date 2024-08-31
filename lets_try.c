/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_try.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 22:12:51 by lalwafi           #+#    #+#             */
/*   Updated: 2024/08/31 22:55:22 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_that_stack(t_ps_list **stack_a, t_ps_list **stack_b)
{
	(void)stack_b;
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
		check_cost(stack_a, stack_b);
	}
}

int	calculate_cost(t_ps_list **stack_a, t_ps_list **stack_b, int stack_index)
{
	int			i;
	int			cost;
	long		diff_min;
	long		diff_max;
	int			index_min;
	int			index_max;
	t_ps_list	*temp_a;
	t_ps_list	*temp_b;
	t_ps_list	*target_b_min;
	t_ps_list	*target_b_max;

	i = stack_index;
	temp_a = (*stack_a);
	temp_b = (*stack_b);
	cost = 0;
	while (temp_a->index != i)
		temp_a = temp_a->next;
	ft_printf("--------------list size = %d\n", ps_lstsize(*stack_a));
	if (i >= (ps_lstsize(*stack_a) / 2))
	{
		while (i++ < ps_lstsize(*stack_a))
			cost++;
	}
	else
	{
		while (i-- > 0)
			cost++;
	}
	ft_printf("cost = %d\n", cost);
	diff_min = LONG_MAX;
	diff_max = LONG_MAX;
	index_max = -5;
	index_min = -5;
	while (temp_b)
	{
		if (temp_b->content > temp_a->content && diff_max > (temp_b->content - temp_a->content))
		{
			diff_max = temp_b->content - temp_a->content;
			index_max = temp_b->index;
		}
		if (temp_b->content < temp_a->content && diff_min > (temp_a->content - temp_b->content))
		{
			diff_min = temp_a->content - temp_b->content;
			index_min = temp_b->index;
			ft_printf("diffmin = %d\n", diff_min);
		}
		temp_b = temp_b->next;
	}
	ft_printf("index_max = %d ---- index_min = %d\n", index_max, index_min);
	target_b_max = what_element_is_index(stack_b, index_max);
	target_b_min = what_element_is_index(stack_b, index_min);
	if (diff_max != LONG_MAX && temp_a->content < target_b_max->content)
	{
		while (index_max-- != 0)
			cost++;
		ft_printf("found index_max\n");
	}
	else
	{
		while (index_min-- != 0)
			cost++;
		ft_printf("found index_min\n");
	}
	cost++;
	ft_printf("final cost = %d\n", cost);
	return (cost);
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

void	check_cost(t_ps_list **stack_a, t_ps_list **stack_b)
{
	t_ps_list	*temp;
	// t_ps_list	*lowest;
	int	index_lowest;
	int	cost;
	
	temp = (*stack_a);
	cost = calculate_cost(stack_a, stack_b, temp->index);
	index_lowest = temp->index;
	while (temp)
	{
		ft_printf("\n----------------------------target -------> %d --- index -----> %d\n", temp->content, temp->index);
		if (cost > calculate_cost(stack_a, stack_b, temp->index))
		{
			cost = calculate_cost(stack_a, stack_b, temp->index);
			index_lowest = temp->index;
		}
		temp = temp->next;
	}
	
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
