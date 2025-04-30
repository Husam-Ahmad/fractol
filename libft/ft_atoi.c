/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huahmad <huahmad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:15:29 by huahmad           #+#    #+#             */
/*   Updated: 2025/03/07 17:45:41 by huahmad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

double	ft_atoi(char *str)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*str >= 9 && *str <= 13) || 32 == *str)
		++str;
	while ('+' == *str || '-' == *str)
		if ('-' == *str++)
			sign = -sign;
	while (*str != '.' && *str)
		integer_part = (integer_part * 10) + (*str++ - 48);
	if ('.' == *str)
		++str;
	while (*str)
	{
		pow /= 10;
		fractional_part = fractional_part + (*str++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}
// int main(void)
// {
// 	char *s = "-0.4";

// 	printf("ft_atoi(\"%s\") = %f\n", s, ft_atoi(s));
// 	return (0);
// }
