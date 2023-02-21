/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaliare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:13:36 by nmaliare          #+#    #+#             */
/*   Updated: 2023/02/21 00:47:06 by nmaliare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	position_main(t_pushswap *all, t_data *cpystart)
{
	t_dlist	*cpy;
	int		cpy_l;

	all->a_len = all->astart->len + 1;
	all->a = all->astart->head;
	cpy = cpystart->head;
	while (--all->a_len > 0)
	{
		cpy_l = cpystart->len + 1;
		while (--cpy_l > 0)
		{
			if (all->a->position == 0 && all->a->num == cpy->num)
			{
				all->a->position = cpy->position;
				cpy = cpystart->head;
				cpy_l = cpystart->len + 1;
			}
			else
				cpy = cpy->next;
		}
		all->a = all->a->next;
	}
}

void	ft_prepare(t_pushswap *all)
{
	t_data	newstart;
	t_dlist	*new;

	newstart.len = 0;
	if (check_if_sorted(&(all->a), all->astart))
		clean_exit(all, 0);
	else
	{
		new = ft_circle_cpy(&(all->a), all->astart, &newstart, all);
		sort_cpy(&new, &newstart);
		position_main(all, &newstart);
		if (all->astart->len <= 3)
			sort_3(all);
		else if (all->astart->len <= 5)
			sort_5(all);
		else
		{
			a_to_b(all);
			b_to_a(all);
		}
		ft_circle_free(&new, &newstart);
		clean_exit(all, 0);
	}
}

void	sort_3(t_pushswap *all)
{
	all->a = all->astart->head;
	while (1)
	{
		if (all->a->position > all->a->prev->position && \
			all->a->next->position == 3)
			rra(all);
		else if (all->a->position > all->a->prev->position)
			ra(all);
		else if (all->a->position > all->a->next->position)
			sa(all);
		else if (all->a->next->position > all->a->prev->position)
			rra(all);
		if (check_if_sorted(&(all->a), all->astart))
			break ;
	}
}

void	first_last(t_pushswap *all)
{
	all->a = all->astart->head;
	if (all->a->position == all->a_len || all->a->position == 1)
		pb(all);
	else if (all->a->prev->position == all->a_len || \
		all->a->prev->position == 1)
	{
		rra(all);
		pb(all);
	}
	else if (all->a->next->position == all->a_len || \
		all->a->next->position == 1)
	{
		ra(all);
		pb(all);
	}
	else if (all->a->next->next->position == all->a_len || \
			all->a->next->next->position == 1)
		ra(all);
	else
		return ;
	first_last(all);
}

void	sort_5(t_pushswap *all)
{
	all->a_len = all->astart->len;
	first_last(all);
	if (all->bstart->len == 2)
	{
		all->b = all->bstart->head;
		sort_3(all);
		if (all->b->position < all->b->next->position)
		{
			pa(all);
			pa(all);
			ra(all);
		}
		else
		{
			pa(all);
			ra(all);
			pa(all);
		}
	}
	else
		sort_3(all);
}
