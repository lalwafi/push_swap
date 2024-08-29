/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:11:21 by lalwafi           #+#    #+#             */
/*   Updated: 2024/08/29 22:40:11 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_ps_list	*ps_lstnew(int content, int index)
{
	t_ps_list	*a;

	a = (t_ps_list *)malloc(sizeof(t_ps_list));
	if (!a)
		return (NULL);
	a -> content = content;
	a -> index = index;
	a -> next = NULL;
	return (a);
}

void	ps_lstadd_back(t_ps_list **lst, t_ps_list *new)
{
	t_ps_list	*last;

	ft_printf("before lstlast??\n");
	last = ps_lstlast(*lst);
	if (*lst)
		last -> next = new;
	else
		*lst = new;
}

void	ps_lstclear(t_ps_list **lst)
{
	t_ps_list	*a;

	while (*lst)
	{
		a = (*lst)->next;
		free(*lst);
		*lst = a;
	}
	*lst = NULL;
}

t_ps_list	*ps_lstlast(t_ps_list *lst)
{
	int	i;

	if (!lst)
		return (NULL);
	ft_printf("before lstsize??\n");
	i = ps_lstsize(lst);
	while (i > 1)
	{
		lst = lst -> next;
		i--;
	}
	return (lst);
}

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
		ft_printf("inside lstsize count = %d\n", count);
	}
	return (count);
}

void	ps_lstprint(t_ps_list *lst)
{
	while (lst)
	{
		ft_printf("%d\n", lst -> content);
		lst = lst -> next;
	}
}