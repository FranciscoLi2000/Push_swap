/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 20:58:11 by yufli             #+#    #+#             */
/*   Updated: 2025/05/11 20:58:15 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	long	nbl;
	char	c[10];
	short	i;

	nbl = nbr;
	i = 0;
	if (nbr == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (nbl < 0)
	{
		nbl *= -1;
		write(fd, "-", 1);
	}
	while (nbl % 10)
	{
		c[i++] = (nbl % 10) + 48;
		nbl /= 10;
	}
	while (i >= 0)
		write(fd, &c[--i], 1);
}
