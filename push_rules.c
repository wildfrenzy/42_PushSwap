/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaliare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:22:48 by nmaliare          #+#    #+#             */
/*   Updated: 2023/02/20 14:23:10 by nmaliare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_pushswap *all)
{
	t_dlist	*tmp;

	if (all->astart->head)
	{
		if (all->b)
		{
			tmp = ft_circle_newnode(all->a->num, all->a->position, all);
			ft_circle_addfront(&(all->b), tmp, all->bstart);
			all->bstart->head = tmp;
		}
		else
		{
			all->b = ft_circle_newnode(all->a->num, all->a->position, all);
			all->bstart->head = all->b;
			all->bstart->len += 1;
		}
		ft_circle_rmnode(&(all->a), &(all->a), all->astart);
		write(1, "pb\n", 3);
	}
}

void	pa(t_pushswap *all)
{
	t_dlist	*tmp;

	if (all->bstart->len > 0)
	{
		if (all->a)
		{
			tmp = ft_circle_newnode(all->b->num, all->b->position, all);
			ft_circle_addfront(&(all->a), tmp, all->astart);
			all->astart->head = tmp;
		}
		else
		{
			all->a = ft_circle_newnode(all->b->num, all->b->position, all);
			all->astart->head = all->a;
			all->astart->len += 1;
		}
		ft_circle_rmnode(&(all->b), &(all->b), all->bstart);
		write(1, "pa\n", 3);
	}
}
