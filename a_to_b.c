/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaliare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:53:46 by nmaliare          #+#    #+#             */
/*   Updated: 2023/02/20 14:35:18 by nmaliare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	offset(int len)
{
	if (len <= 5)
		return (1);
	else if (len <= 10)
		return (len / 2);
	else if (len <= 150)
		return (len / 8);
	else
		return (len / 18);
}

void	check_chunk(t_pushswap *all, t_helpers help)
{
	all->b = all->bstart->head;
	if (all->b->position < help.middle)
		rb(all);
}

void	make_chunk(t_pushswap *all, int i, t_helpers help)
{
	all->b = all->bstart->head;
	if (all->a != all->astart->head)
	{
		if (i == all->astart->len)
			rra(all);
		else if (i <= help.middle)
			while (i-- > 1)
				ra(all);
		else
		{
			i = all->astart->len - i;
			while (i-- > 0)
				rra(all);
		}
	}
	pb(all);
	check_chunk(all, help);
}

void	init_helper(t_helpers *help, t_data *astart)
{
	help->offset = offset(astart->len);
	help->middle = astart->len / 2;
	help->start = help->middle - help->offset;
	help->end = help->middle + help->offset;
}

void	a_to_b(t_pushswap *all)
{
	t_helpers	help;
	int			i;

	i = 0;
	init_helper(&help, all->astart);
	all->a = all->astart->head;
	while (++i <= all->astart->len)
	{
		if (all->a->position >= help.start && all->a->position <= help.end)
		{
			make_chunk(all, i, help);
			i = 0;
			all->a = all->astart->head;
		}
		else
			all->a = all->a->next;
		if (all->bstart->len == (help.end - help.start))
		{
			help.end += help.offset;
			help.start -= help.offset;
		}
	}
}
