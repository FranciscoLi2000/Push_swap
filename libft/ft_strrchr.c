/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:07:30 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 21:12:07 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char		ch;
	const char	*last;

	ch = (char)c;
	last = NULL;
	while (*str)
	{
		if (*str == ch)
			last = str;
		str++;
	}
	if (ch == '\0')
		return ((char *)str);
	return ((char *)last);
}
