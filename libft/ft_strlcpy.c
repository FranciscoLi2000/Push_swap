/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:06:34 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 21:06:37 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dst, char *src, unsigned int size)
{
	int	len;

	len = 0;
	while (*(src + len) && --size)
		*dst++ = *(src + len++);
	*dst = '\0';
	while (*(src + len))
		++len;
	return (len);
}
