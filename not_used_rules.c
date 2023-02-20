/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_used_rules.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaliare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:20:57 by nmaliare          #+#    #+#             */
/*   Updated: 2023/02/20 14:22:17 by nmaliare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_pushswap *all);
void	rr(t_pushswap *all);
void	rrr(t_pushswap *all);
void	sb(t_pushswap *all);

void	ss(t_pushswap *all)
{
	ft_circle_swap(&(all->a), all->astart);
	ft_circle_swap(&(all->b), all->bstart);
	write(1, "ss\n", 3);
}

void	rr(t_pushswap *all)
{
	ft_circle_rot_left(&(all->a), all->astart);
	ft_circle_rot_left(&(all->b), all->bstart);
	write(1, "rr\n", 3);
}

void	rrr(t_pushswap *all)
{
	ft_circle_rot_right(&(all->a), all->astart);
	ft_circle_rot_right(&(all->b), all->bstart);
	write(1, "rrr\n", 4);
}

void	sb(t_pushswap *all)
{
	ft_circle_swap(&(all->b), all->bstart);
	write(1, "sb\n", 3);
}
