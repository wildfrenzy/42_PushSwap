/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaliare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:15:09 by nmaliare          #+#    #+#             */
/*   Updated: 2023/02/21 23:09:03 by nmaliare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_dupl(int num, t_data *start, t_dlist **lst)
{
	int	len;

	len = start->len;
	*lst = start->head;
	while (--len > 0)
	{
		if (num == (*lst)->num)
			return (0);
		(*lst) = (*lst)->next;
	}
	if (num == (*lst)->num)
		return (0);
	return (1);
}

void	clean_exit(t_pushswap *all, char f)
{
	if (all->a)
		ft_circle_free(&all->a, all->astart);
	if (all->b)
		ft_circle_free(&all->b, all->bstart);
	free(all->astart);
	free(all->bstart);
	if (f == 'm')
		ft_printf("Malloc Error!\n");
	else if (f == 'd')
		ft_printf("Error\n");
	exit (1);
}

void	init_all(t_pushswap *all)
{
	t_dlist	*a;
	t_dlist	*b;
	t_data	*astart;
	t_data	*bstart;

	a = 0;
	b = 0;
	astart = ft_calloc(sizeof(t_data), 1);
	bstart = ft_calloc(sizeof(t_data), 1);
	if (!astart || !bstart)
		exit(1);
	astart->head = a;
	bstart->head = b;
	astart->len = 0;
	bstart->len = 0;
	all->a = a;
	all->b = b;
	all->astart = astart;
	all->bstart = bstart;
}

int	err_input(char **av)
{
	size_t	i;
	size_t	len;

	i = -1;
	while (*av && *av[++i])
	{
		len = ft_strlen(*av);
		if (!ft_isdigit(*av[i]))
			return (0);
		if (i > INT_MAX)
			return (0);
		if (i == len)
		{
			i = 0;
			av++;
		}
	}
	return (1);
}

int	main(int ac, char *av[])
{
	t_pushswap	all;
	int			i;
	int			num;

	i = ac - 1;
	if (ac < 2)
		return (0);
	if (!err_input(av))
		return (0 & ft_printf("Error\n"));
	init_all(&all);
	all.a = ft_circle_newnode(ft_atoi(av[i]), 0, &all);
	all.astart->len = 1;
	all.astart->head = all.a;
	while (--i > 0)
	{
		num = ft_atoi(av[i]);
		if (!ft_check_dupl(num, all.astart, &(all.a)))
			clean_exit(&all, 'd');
		ft_circle_addfront(&(all.a), \
		ft_circle_newnode(num, 0, &all), all.astart);
	}
	ft_prepare(&all);
	return (0);
}
