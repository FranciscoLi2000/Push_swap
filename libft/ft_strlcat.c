/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:06:06 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 21:06:29 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dst, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	i;
	unsigned int	j;

	src_len = ft_strlen(src);
	i = 0;
	j = 0;
	while (++i < size && *dst)
		dst++;
	if (i < size)
		return (i + src_len);
	while (src[j])
	{
		if (j < size - i - 1)
			*dst++ = src[j];
		j++;
	}
	*dst = '\0';
	return (i + j);
}
