/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaliare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:12:21 by nmaliare          #+#    #+#             */
/*   Updated: 2022/12/13 20:12:21 by nmaliare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_pf_putnbr_fd(int nb, int fd, int *len);
void	ft_pf_putunbr_fd(unsigned int nb, int fd, int *len);
void	ft_pf_puthex_fd(unsigned long num, int fd, char indicator, int *len);
void	ft_pf_putstr_fd(char const *s, int fd, int *len);
int		ft_pf_putchar_fd(char c, int fd);

#endif
