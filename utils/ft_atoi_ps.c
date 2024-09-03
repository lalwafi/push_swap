/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 07:28:37 by lalwafi           #+#    #+#             */
/*   Updated: 2024/09/03 15:52:33 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	handle_overflow(const char *str, int sign)
{
	long	n;
	long	temp;

	n = 0;
	while ((*str >= '0') && (*str <= '9'))
	{
		temp = n;
		n = n * 10 + (*str - '0');
		if (temp > n)
			(write(1, "Error\n", 6), exit(EXIT_FAILURE));
		str++;
	}
	if (n < INT_MIN || n > INT_MAX)
		(write(1, "Error\n", 6), exit(EXIT_FAILURE));
	return (sign * n);
}

int	ft_atoi_ps(const char *str, int *valid)
{
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	if (ft_strncmp(str, "-2147483648", 12) == 0)
		return (-2147483648);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]) == 0)
	{
		write(1, "Error\n", 6);
		*valid = 0;
		return (0);
	}
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	return (handle_overflow(str, sign));
}
