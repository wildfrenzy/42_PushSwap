/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaliare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:54:34 by nmaliare          #+#    #+#             */
/*   Updated: 2023/02/22 18:54:34 by nmaliare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	num_check(size_t i, char **av, size_t len)
{
	if (!ft_isdigit((*av)[i]))
		return (0);
	if ((len == 10 && ft_strncmp(*av, "2147483647", 10) > 0) || \
			(len == 11 && ft_strncmp(*(av) + 1, "2147483648", 10) > 0))
		return (0);
	return (1);
}

int	err_input(int ac, char **av)
{
	size_t	i;
	size_t	len;

	i = 0;
	av += 1;
	while (ac > 1 && (*av)[i])
	{
		len = ft_strlen(*av);
		if (i > INT_MAX || ((*av)[i] == '-' && len > 11) || \
			(len > 10 && i == 0 && (*av)[i] != '-'))
			return (0);
		if ((*av)[i] == '-')
			i++;
		if (!num_check(i, av, len))
			return (0);
		if (i < len - 1)
			i++;
		else
		{
			i = 0;
			av++;
			ac--;
		}
	}
	return (ac == 1);
}
