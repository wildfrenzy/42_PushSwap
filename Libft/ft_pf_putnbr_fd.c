/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putnbr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaliare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:49:17 by nmaliare          #+#    #+#             */
/*   Updated: 2022/11/28 15:49:20 by nmaliare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "libft.h"

void	ft_pf_putnbr_fd(int nb, int fd, int *len)
{
	char	n;

	if (nb > -10 && nb < 0)
	{
		write(fd, "-", 1);
		*len += 1;
	}
	if (nb >= 10 || nb <= -10)
		ft_pf_putnbr_fd(nb / 10, fd, len);
	if (nb < 0)
	{
		nb %= 10;
		nb *= -1;
	}
	n = 48 + (nb % 10);
	write(fd, &n, 1);
	*len += 1;
}
