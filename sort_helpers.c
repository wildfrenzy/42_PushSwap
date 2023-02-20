/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaliare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:06:49 by nmaliare          #+#    #+#             */
/*   Updated: 2023/02/20 12:09:41 by nmaliare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted(t_dlist **a, t_data *astart)
{
	int	i;

	i = 0;
	*a = astart->head;
	if (astart->len > 0)
	{
		while (++i + 1 <= astart->len)
		{
			if ((*a)->num > (*a)->next->num)
				return (0);
			*a = (*a)->next;
		}
	}
	return (1);
}

void	sort_cpy(t_dlist **a, t_data *start)
{
	int	i;
	int	tmp;

	i = 1;
	*a = start->head;
	while ((i + 1) <= start->len)
	{
		if ((*a)->num > (*a)->next->num)
		{
			tmp = (*a)->num;
			(*a)->num = (*a)->next->num;
			(*a)->next->num = tmp;
			i = 1;
			*a = start->head;
		}
		else
		{
			i++;
			*a = (*a)->next;
		}
	}
}
