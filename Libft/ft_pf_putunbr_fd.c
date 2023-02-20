/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putunbr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaliare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:16:29 by nmaliare          #+#    #+#             */
/*   Updated: 2023/01/10 22:13:39 by nmaliare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "libft.h"

void	ft_pf_putunbr_fd(unsigned int nb, int fd, int *len)
{
	char	n;

	if (nb >= 10)
		ft_pf_putunbr_fd(nb / 10, fd, len);
	n = 48 + (nb % 10);
	write(fd, &n, 1);
	*len += 1;
}
