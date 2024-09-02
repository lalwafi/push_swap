/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:41:18 by lalwafi           #+#    #+#             */
/*   Updated: 2024/09/02 08:06:16 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft_copy/libft.h"
# include "ft_printf_copy/ft_printf.h"

typedef struct s_ps_list
{
	int					content;
	int					index;
	int					cost;
	struct s_ps_list	*next;
}	t_ps_list;

typedef struct s_cost
{
	t_ps_list	*target_a;
	t_ps_list	*target_b;
	int			cost;
}	t_cost;


// push_swap functions

void		free_double_array(char **array);
int			check_for_spaces_empty(char *str);
int			count_how_many(char **av);
int			any_letters(char *str);
char		**array_time(char **numbers, char **av, int a);
int			duplicates_maybe(int *numbers, int count);
int			*char_to_int_array(char **numbers, int count);
int			*parsing_again(char **av);
void		index_that_stack(t_ps_list **stack);

t_ps_list	*make_stack(t_ps_list *stack_a, int *numarray, int wc);
int			is_it_sorted(t_ps_list *stack_a);

void		sort_that_stack(t_ps_list **stack_a, t_ps_list **stack_b);
void		sort_three(t_ps_list **stack_a);

// lets see if this sorting works

// t_cost		*check_cost(t_ps_list **stack_a, t_ps_list **stack_b, t_cost *cs);
// t_cost		*calculate_cost(t_ps_list **stack_a, t_ps_list **stack_b, int stack_index);
t_ps_list	*what_element_is_index(t_ps_list **stack, int whatindex);
// void		sort_it(t_ps_list **stack_a, t_ps_list **stack_b, t_cost *cs);
// void		initialize_cost_stuff(t_ps_list **stack_a, t_ps_list **stack_b, t_cost **cs);





// try again

void		lemme_try_sorting_b(t_ps_list **stack_a, t_ps_list **stack_b, t_ps_list *target_a, t_ps_list *target_b);
t_ps_list   *find_target_b(t_ps_list **stack_b, t_ps_list *target_a);
t_ps_list	*find_closest_minimum(t_ps_list **stack, t_ps_list *target);
t_ps_list   *find_maximum(t_ps_list **stack, t_ps_list *target);
t_ps_list    *find_minimum(t_ps_list **stack, t_ps_list *target);
int find_flag_for_target_b(t_ps_list **stack_b, int flag, t_ps_list *target_a);


// cost stuff

int	lemme_try_sorting_cost(t_ps_list **stack, t_ps_list *target);
t_cost	lowest_cost_each_target(t_ps_list **stack_a, t_ps_list **stack_b);
t_ps_list   *find_target_b_cost(t_ps_list **stack_b, t_ps_list *target_a);
int find_flag_for_target_b_cost(t_ps_list **stack_b, int flag, t_ps_list *target_a);
t_ps_list    *find_minimum_cost(t_ps_list **stack, t_ps_list *target);
t_ps_list    *find_maximum_cost(t_ps_list **stack, t_ps_list *target);
t_ps_list    *find_closest_minimum_cost(t_ps_list **stack, t_ps_list *target);

void sort_that_stack_again(t_ps_list **stack_a, t_ps_list **stack_b);
int find_flag_to_sort(t_ps_list *target_a, t_ps_list *target_b, t_ps_list **stack_a, t_ps_list **stack_b);


// utils

int			handle_overflow(const char *str, int sign);
int			ft_atoi_ps(const char *str);

// list stuff

t_ps_list	*ps_lstnew(int content);
void		ps_lstadd_back(t_ps_list **lst, t_ps_list *new);
void		ps_lstclear(t_ps_list **lst);
void		ps_lstdelone(t_ps_list *lst, void (*del)(void *));
t_ps_list	*ps_lstlast(t_ps_list *lst);
int			ps_lstsize(t_ps_list *lst);
void		ps_lstprint(t_ps_list *lst);
void		ps_lstadd_front(t_ps_list **lst, t_ps_list *new);

// push_swap utils

void    swap_a(t_ps_list   **stack_a);
void    swap_b(t_ps_list **stack_b);
void    push_a(t_ps_list **stack_a, t_ps_list **stack_b);
void    push_b(t_ps_list **stack_a, t_ps_list **stack_b);
void    rotate_a(t_ps_list **stack_a);
void    rotate_b(t_ps_list **stack_b);
void	reverse_rotate_a(t_ps_list **stack_a);
void	reverse_rotate_b(t_ps_list **stack_b);
void    rotate_b_for_rotate_both(t_ps_list **stack_b);
void    rotate_both(t_ps_list **stack_a, t_ps_list **stack_b);
void    reverse_rotate_both(t_ps_list **stack_a, t_ps_list **stack_b);

#endif