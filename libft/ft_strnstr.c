/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 21:07:07 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 21:07:25 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	max_pos;
	size_t	i;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	if (needle_len > len)
		return (NULL);
	max_pos = len - needle_len;
	i = 0;
	while (i <= max_pos)
	{
		if (haystack[i] == needle[0]
			&& ft_strncmp(haystack + i, needle, needle_len) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
