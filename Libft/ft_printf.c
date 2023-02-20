/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaliare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 01:09:46 by nmaliare          #+#    #+#             */
/*   Updated: 2023/01/10 22:13:31 by nmaliare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "libft.h"

static void	helper(const char *tmp, va_list *arg, int *len)
{
	size_t	p;

	if (*tmp == 's')
		ft_pf_putstr_fd(va_arg(*arg, char *), 1, len);
	else if (*tmp == 'd' || *tmp == 'i')
		ft_pf_putnbr_fd(va_arg(*arg, int), 1, len);
	else if (*tmp == '%')
		*len += ft_pf_putchar_fd('%', 1);
	else if (*tmp == 'c')
		*len += ft_pf_putchar_fd(va_arg(*arg, int), 1);
	else if (*tmp == 'p')
	{
		p = va_arg(*arg, size_t);
		if (p == 0)
			ft_pf_putstr_fd("(nil)", 1, len);
		else
			ft_pf_puthex_fd(p, 1, *tmp, len);
	}
	else if (*tmp == 'x' || *tmp == 'X')
		ft_pf_puthex_fd(va_arg(*arg, unsigned int), 1, *tmp, len);
	else if (*tmp == 'u')
		ft_pf_putunbr_fd(va_arg(*arg, unsigned int), 1, len);
}

int	ft_printf(const char *format, ...)
{
	va_list		arg;
	const char	*tmp;
	int			len;

	if (format == NULL)
		return (0);
	va_start(arg, format);
	tmp = format;
	len = 0;
	while (*tmp)
	{
		if (*tmp == '%')
		{
			tmp++;
			helper(tmp, &arg, &len);
		}
		else
			len += ft_pf_putchar_fd(*tmp, 1);
		tmp++;
	}
	va_end(arg);
	return (len);
}
