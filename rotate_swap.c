/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaliare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:44:03 by nmaliare          #+#    #+#             */
/*   Updated: 2023/02/20 14:30:00 by nmaliare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_circle_rot_right(t_dlist **lst, t_data *start)
{
	if (start->len > 1)
	{
		*lst = start->head;
		start->head = (*lst)->prev;
		*lst = start->head;
	}
}

void	ft_circle_rot_left(t_dlist **lst, t_data *start)
{
	if (start->len > 1)
	{
		*lst = start->head;
		start->head = (*lst)->next;
		*lst = start->head;
	}
}

void	ft_circle_swap(t_dlist **lst, t_data *start)
{
	int	tmp;

	if (start->len > 1)
	{
		*lst = start->head;
		tmp = (*lst)->num;
		(*lst)->num = (*lst)->next->num;
		(*lst)->next->num = tmp;
	}
}
