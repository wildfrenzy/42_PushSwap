/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaliare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:55:10 by nmaliare          #+#    #+#             */
/*   Updated: 2023/02/20 11:33:49 by nmaliare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printlst(t_dlist *all, t_data *start)
{
	int i;

	i = 0;
	all = start->head;
	ft_printf(" lst len:%d\n", start->len);
	if (start->len < 1)
	{
		printf("Empty lst\n");
		return ;
	}
	while (i++ < start->len)
	{
		printf("%d ", all->num);
		all = all->next;
	}
	printf("\n");
}

void	ft_print_position(t_dlist *all, t_data *start)
{
	int	i;

	i = 0;
	all = start->head;
	ft_printf("len:%d\n", start->len);
	if (start->len < 1)
	{
		printf("Empty \n");
		return ;
	}
	while (i++ < start->len)
	{
		printf("%d ", all->position);
		all = all->next;
	}
	printf("\n");
}