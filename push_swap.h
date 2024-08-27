/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:41:18 by lalwafi           #+#    #+#             */
/*   Updated: 2024/08/27 04:33:45 by lalwafi          ###   ########.fr       */
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
	int				content;
	int				num;
	struct s_list	*next;
}	t_ps_list;

// typedef struct s_parsing
// {
// 	int				count;
// };	t_parsing;

void	free_double_array(char **array);
int		check_for_spaces_empty(char *str);
int		count_how_many(char **av);
int		any_letters(char *str);
char	**array_time(char **numbers, char **av, int a);
void	duplicates_maybe(int *numbers, int count);
int		*char_to_int_array(char **numbers, int count);
void	parsing_again(char **av);

#endif