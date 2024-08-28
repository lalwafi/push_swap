/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 07:28:37 by lalwafi           #+#    #+#             */
/*   Updated: 2024/08/28 07:43:30 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_overflow(const char *str, int sign)
{
	long	n;
    long    temp;
	n = 0;
	while ((*str >= '0') && (*str <= '9'))
    {
        temp = n;
        n = n * 10 + (*str - '0');
        if (temp > n)
            (write(1, "overflow\n", 9), exit(EXIT_FAILURE));
        str++;
    }
	if (n < INT_MIN || n > INT_MAX)
		(write(1, "overflow\n", 9), exit(EXIT_FAILURE));
	return (sign * n);
}

int	ft_atoi_ps(const char *str)
{
	int	sign;

	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	return (handle_overflow(str, sign));
}
