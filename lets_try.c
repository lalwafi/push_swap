/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_try.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 22:12:51 by lalwafi           #+#    #+#             */
/*   Updated: 2024/09/01 08:55:13 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_that_stack(t_ps_list **stack_a, t_ps_list **stack_b)
{
	t_cost	*cost_stuff;
	
	initialize_cost_stuff(stack_a, stack_b, &cost_stuff);
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
		ft_printf("-------stack_a-------\n");
		ps_lstprint(*stack_a);
		ft_printf("-------stack_b-------\n");
		ps_lstprint(*stack_b);
		cost_stuff = check_cost(stack_a, stack_b, cost_stuff);
	}
	// sort_it(stack_a, stack_b, cost_stuff);
}

t_cost	*check_cost(t_ps_list **stack_a, t_ps_list **stack_b, t_cost *cs)
{
	t_ps_list	*temp;
	// t_ps_list	*lowest;
	t_cost	*temp_cs;
	// int	index_lowest;
	
	temp = (*stack_a);
	cs = calculate_cost(stack_a, stack_b, temp->index);
	cs->target_a = temp;
	while (temp)
	{
		ft_printf("\n----------------------------target -------> %d --- index -----> %d\n", temp->content, temp->index);
		temp_cs = calculate_cost(stack_a, stack_b, temp->index);
		if (cs->cost > temp_cs->temp_cost)
		{
			cs = calculate_cost(stack_a, stack_b, temp->index);
			cs->target_a = temp;
		}
		temp = temp->next;
	}
	ft_printf("index_lowest = %d\n", cs->target_a->index);
	return (cs);
}

// void	sort_it(t_ps_list **stack_a, t_ps_list **stack_b, t_cost *cs)
// {
// 	// int	i;
// 	t_ps_list	*temp_a;

// 	// i = 0;
// 	(void)stack_b;
// 	temp_a = cs->target_a;
// 	if (temp_a->index >= (ps_lstsize(*stack_a) / 2))
// 	{
// 		while (temp_a->index != ps_lstsize(*stack_a))
// 			reverse_rotate_a(&temp_a);
// 	}
// 	else
// 	{
// 		while (temp_a->index != 0)
// 			rotate_a(&temp_a);
// 	}
	
// }

void	check_a_cost(t_ps_list **stack_a,  t_cost *cs)
{
	while ((*cs).temp_a->index != (*cs).i)
		(*cs).temp_a = (*cs).temp_a->next;
	ft_printf("--------------list size = %d\n", ps_lstsize(*stack_a));
	if ((*cs).i >= (ps_lstsize(*stack_a) / 2))
	{
		while ((*cs).i++ < ps_lstsize(*stack_a))
			(*cs).cost++;
	}
	else
	{
		while ((*cs).i-- > 0)
			(*cs).cost++;
	}
}

void	check_max_min_closest(t_cost *cs)
{
	while ((*cs).temp_b)
	{
		if ((*cs).temp_b->content > (*cs).temp_a->content &&
			(*cs).diff_max > ((*cs).temp_b->content - (*cs).temp_a->content))
		{
			(*cs).diff_max = (*cs).temp_b->content - (*cs).temp_a->content;
			(*cs).index_max = (*cs).temp_b->index;
		}
		if ((*cs).temp_b->content < (*cs).temp_a->content &&
			(*cs).diff_min > ((*cs).temp_a->content - (*cs).temp_b->content))
		{
			(*cs).diff_min = (*cs).temp_a->content - (*cs).temp_b->content;
			(*cs).index_min = (*cs).temp_b->index;
			ft_printf("diffmin = %d\n", (*cs).diff_min);
		}
		(*cs).temp_b = (*cs).temp_b->next;
	}
}

void	check_b_cost(t_cost *cs)
{
	if ((*cs).diff_max != LONG_MAX && (*cs).temp_a->content < (*cs).target_b_max->content)
	{
		while ((*cs).index_max-- != 0)
			(*cs).cost++;
		ft_printf("found index_max\n");
	}
	else
	{
		while ((*cs).index_min-- != 0)
			(*cs).cost++;
		ft_printf("found index_min\n");
	}
}

t_cost	*calculate_cost(t_ps_list **stack_a, t_ps_list **stack_b, int stack_index)
{
	t_cost	*cs;
	// t_ps_list	*target_b_min;

	initialize_cost_stuff(stack_a, stack_b, &cs);
	cs->i = stack_index;
	// cs->temp_a = (*stack_a);
	// cs->temp_b = (*stack_b);
	cs->cost = 0;
	check_a_cost(stack_a, cs);
	ft_printf("cost = %d\n", cs->cost);
	cs->diff_min = LONG_MAX;
	cs->diff_max = LONG_MAX;
	cs->index_max = -5;
	cs->index_min = -5;
	check_max_min_closest(cs);
	ft_printf("index_max = %d ---- index_min = %d\n", cs->index_max, cs->index_min);
	cs->target_b_max = what_element_is_index(stack_b, cs->index_max);
	// target_b_min = what_element_is_index(stack_b, index_min);
	check_b_cost(cs);
	cs->cost++;
	ft_printf("final cost = %d\n", cs->cost);
	return (cs);
}

void	initialize_cost_stuff(t_ps_list **stack_a, t_ps_list **stack_b, t_cost **cs)
{
	(*cs)->i = 0;
	(*cs)->cost = -5;
	(*cs)->diff_min = -5;
	(*cs)->diff_max = -5;
	(*cs)->index_min = -5;
	(*cs)->index_max = -5;
	(*cs)->temp_a = (*stack_a);
	(*cs)->temp_b = (*stack_b);
	(*cs)->target_b_max = (*stack_b);
	(*cs)->target_a = (*stack_a);
	(*cs)->temp_cost = -5;
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
