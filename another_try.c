/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_try.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 04:11:32 by lalwafi           #+#    #+#             */
/*   Updated: 2024/09/02 04:46:08 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_that_stack_again(t_ps_list **stack_a, t_ps_list **stack_b)
{
	t_ps_list   *target_a;
	t_ps_list   *target_b;
	t_cost		costcal;
	// int         i;
    // int         flag;

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
		costcal = lowest_cost_each_target(stack_a, stack_b);
		target_a = costcal.target_a;
		target_b = costcal.target_b;
        // flag = find_flag_to_sort(target_a, target_a, stack_a, stack_b);
		// i = ps_lstsize(*stack_a);
        ft_printf("target_a = %d\n", target_a->content);
        ft_printf("target_b = %d\n", target_b->content);
		ft_printf("cost = %d\n", costcal.cost);
    }
}

// deal with if stack_a is null
int find_flag_to_sort(t_ps_list *target_a, t_ps_list *target_b, t_ps_list **stack_a, t_ps_list **stack_b)
{
    int flag;

    flag = 0;
    // if target_a and target_b need rotate                       flag = 0
    // if target_a and target_b need reverse rotate               flag = 1
    // if target_a needs rotate and target_b needs reverse rotate flag = 2
    // if target_a needs reverse rotate and target_b needs rotate flag = 3
    // if target_a doesnt exist                                   flag = 4
    if (stack_a && (*stack_a) && stack_b && (*stack_b))
    {
        if (target_a->index < ((ps_lstsize(*stack_a) / 2) - 1) && target_b->index < ((ps_lstsize(*stack_b) / 2) - 1))
            flag = 0;
        else if (target_a->index >= ((ps_lstsize(*stack_a) / 2) - 1) && target_b->index >= ((ps_lstsize(*stack_b) / 2) - 1))
            flag = 1;
        else if (target_a->index < ((ps_lstsize(*stack_a) / 2) - 1) && target_b->index >= ((ps_lstsize(*stack_b) / 2) - 1))
            flag = 2;
        else if (target_a->index >= ((ps_lstsize(*stack_a) / 2) - 1) && target_b->index < ((ps_lstsize(*stack_b) / 2) - 1))
            flag = 3;
    }
    else if (stack_b && (*stack_b))
        flag = 4;
    return (flag);
}