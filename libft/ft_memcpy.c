/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 20:57:36 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 21:20:20 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	void				*original;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	original = dst;
	while (n-- > 0)
		*d++ = *s++;
	return (original);
}
