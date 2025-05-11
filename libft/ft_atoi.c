/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 20:56:20 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 21:16:27 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	short	parity;
	int		number;

	parity = 0;
	number = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		++str;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			parity++;
		++str;
	}
	while (*str >= 48 && *str <= 57)
	{
		number *= 10;
		number += *str - 48;
		++str;
	}
	if (parity % 2 == 0)
		return (number);
	return (-number);
}
