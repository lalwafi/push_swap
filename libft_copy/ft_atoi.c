/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:33:14 by lalwafi           #+#    #+#             */
/*   Updated: 2024/08/27 10:12:45 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	handle_overflow(const char *str, int sign)
{
	long	n;

	n = 0;
	if (*str >= '0' && *str <= '9')
	{
		while ((*str >= '0') && (*str <= '9'))
		{
			n = n * 10 + (*str - '0');
			str++;
		}
	}
	return (sign * n);
}

int	ft_atoi(const char *str)
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

int main(void)
{
	char *a = "217";
	int	b;
	b = ft_atoi(a);
	printf("%d\n", b);
}