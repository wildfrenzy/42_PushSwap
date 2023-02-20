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
	if (all->astart->head)
	{
		ft_circle_push(&(all->a), &(all->b), all->astart, all->bstart);
		write(1, "pb\n", 3);
	}
}

void	pa(t_pushswap *all)
{
	if (all->bstart->len > 0)
	{
		ft_circle_push(&(all->b), &(all->a), all->bstart, all->astart);
		write(1, "pa\n", 3);
	}
}
