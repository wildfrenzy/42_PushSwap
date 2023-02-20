/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaliare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:35:56 by nmaliare          #+#    #+#             */
/*   Updated: 2023/02/20 14:17:43 by nmaliare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_biggest(t_dlist **b, t_data *bstart)
{
	int	i;
	int	biggest;
	int	index;

	i = 0;
	biggest = 0;
	index = -1;
	*b = bstart->head;
	while (++i <= bstart->len)
	{
		if ((*b)->position > biggest)
		{
			biggest = (*b)->position;
			index = i;
		}
		*b = (*b)->next;
	}
	return (index);
}

void	check_down(int *down, t_pushswap *all)
{
	if (*down > 0 && all->astart->head->prev && \
		all->astart->head->prev->position == all->astart->head->position - 1)
	{
		rra(all);
		*down -= 1;
		check_down(down, all);
	}
}

void	b_to_a(t_pushswap *all)
{
	int	down;
	int	biggest_index;

	down = 0;
	all->b = all->bstart->head;
	all->a = all->astart->head;
	while (all->bstart->len)
	{
		biggest_index = find_biggest(&(all->b), all->bstart);
		if (biggest_index == 1)
			pa(all);
		else if (down == 0 || (all->astart->head->prev && \
			(all->bstart->head->position > all->astart->head->prev->position)))
		{
			pa(all);
			ra(all);
			down++;
		}
		else
			b_to_a_help(all, biggest_index);
		check_down(&down, all);
	}
}

void	b_to_a_help(t_pushswap *all, int biggest_index)
{
	int	node;

	if (biggest_index == all->bstart->len)
		rrb(all);
	else if (biggest_index <= all->bstart->len / 2 + 1)
	{
		node = biggest_index;
		while (node-- > 1)
			rb(all);
	}
	else
	{
		node = (all->bstart->len - biggest_index) + 1;
		while (node-- > 0)
			rrb(all);
	}
	pa(all);
}
