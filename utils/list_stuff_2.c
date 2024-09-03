/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_stuff_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:11:16 by lalwafi           #+#    #+#             */
/*   Updated: 2024/09/03 17:11:34 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ps_lstsize(t_ps_list *lst)
{
	t_ps_list	*current;
	int			count;

	count = 0;
	if (!lst)
		return (0);
	current = lst;
	while (current != NULL)
	{
		current = current -> next;
		count++;
	}
	return (count);
}

void	ps_lstprint(t_ps_list *lst)
{
	while (lst)
	{
		ft_printf("%d) %d\n", lst->index, lst->content);
		lst = lst -> next;
	}
}

void	ps_lstadd_front(t_ps_list **lst, t_ps_list *new)
{
	new -> next = *lst;
	*lst = new;
}
