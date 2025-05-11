/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 20:57:48 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 21:21:13 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	value;
	void			*original;

	ptr = (unsigned char *)s;
	value = (unsigned char)c;
	original = s;
	while (n-- > 0)
		*ptr++ = value;
	return (original);
}
