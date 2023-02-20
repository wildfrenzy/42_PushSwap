/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaliare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:30:06 by nmaliare          #+#    #+#             */
/*   Updated: 2023/02/20 14:22:28 by nmaliare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_pushswap *all)
{
	ft_circle_rot_left(&(all->a), all->astart);
	write(1, "ra\n", 3);
}

void	rb(t_pushswap *all)
{
	ft_circle_rot_left(&(all->b), all->bstart);
	write(1, "rb\n", 3);
}

void	rra(t_pushswap *all)
{
	ft_circle_rot_right(&(all->a), all->astart);
	write(1, "rra\n", 4);
}

void	rrb(t_pushswap *all)
{
	ft_circle_rot_right(&(all->b), all->bstart);
	write(1, "rrb\n", 4);
}

void	sa(t_pushswap *all)
{
	ft_circle_swap(&(all->a), all->astart);
	write(1, "sa\n", 3);
}
