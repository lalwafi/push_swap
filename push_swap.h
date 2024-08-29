/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:41:18 by lalwafi           #+#    #+#             */
/*   Updated: 2024/08/29 22:40:08 by lalwafi          ###   ########.fr       */
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
	struct s_ps_list	*next;
}	t_ps_list;

// typedef struct s_parsing
// {
// 	int				count;
// };	t_parsing;


// push_swap functions

void		free_double_array(char **array);
int			check_for_spaces_empty(char *str);
int			count_how_many(char **av);
int			any_letters(char *str);
char		**array_time(char **numbers, char **av, int a);
int			duplicates_maybe(int *numbers, int count);
int			*char_to_int_array(char **numbers, int count);
int			*parsing_again(char **av);

// utils

int			handle_overflow(const char *str, int sign);
int			ft_atoi_ps(const char *str);

// list stuff

t_ps_list	*ps_lstnew(int content, int index);
void		ps_lstadd_back(t_ps_list **lst, t_ps_list *new);
void		ps_lstclear(t_ps_list **lst);
void		ps_lstdelone(t_ps_list *lst, void (*del)(void *));
t_ps_list	*ps_lstlast(t_ps_list *lst);
int			ps_lstsize(t_ps_list *lst);
void		ps_lstprint(t_ps_list *lst);

#endif