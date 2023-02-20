/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_puthex_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaliare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:18:26 by nmaliare          #+#    #+#             */
/*   Updated: 2023/01/10 22:14:05 by nmaliare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "libft.h"

void	ft_pf_puthex_fd(size_t num, int fd, char indicator, int *len)
{
	char	c;
	int		flag;

	flag = 0;
	if (num >= 16)
		ft_pf_puthex_fd(num / 16, 1, indicator, len);
	else if (num <= 16 && indicator == 'p')
		flag = 1;
	if (num % 16 < 10)
		c = num % 16 + '0';
	else
	{
		if (indicator == 'x' || indicator == 'p')
			c = num % 16 + 'a' - 10;
		if (indicator == 'X')
			c = num % 16 + 'A' - 10;
	}
	if (flag == 1)
	{
		write(fd, "0x", 2);
		*len += 2;
	}
	write(fd, &c, 1);
	*len += 1;
}
