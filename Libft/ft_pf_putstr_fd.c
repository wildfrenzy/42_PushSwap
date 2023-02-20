/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putstr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaliare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:49:29 by nmaliare          #+#    #+#             */
/*   Updated: 2022/11/28 15:49:33 by nmaliare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "libft.h"

void	ft_pf_putstr_fd(char const *s, int fd, int *len)
{
	int	i;

	i = -1;
	if (s == NULL)
		ft_pf_putstr_fd("(null)", fd, len);
	else
	{
		while (s[++i])
		{
			ft_pf_putchar_fd((char)s[i], fd);
			*len += 1;
		}
	}
}
