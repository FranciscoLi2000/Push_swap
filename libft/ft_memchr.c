/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 20:57:25 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 20:57:28 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		value;

	p = (const unsigned char *)s;
	value = (unsigned char)c;
	while (n-- > 0)
	{
		if (*p == value)
			return ((void *)p);
		p++;
	}
	return (NULL);
}
