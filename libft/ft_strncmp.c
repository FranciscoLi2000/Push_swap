/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:06:55 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 21:06:59 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	if (n == 0)
		return (0);
	while (n-- > 0)
	{
		if (*str1 != *str2)
			return ((unsigned char)*str1 - (unsigned char)*str2);
		if (*str1 == '\0')
			return (0);
		str1++;
		str2++;
	}
	return (0);
}
