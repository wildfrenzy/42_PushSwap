/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaliare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:25:13 by nmaliare          #+#    #+#             */
/*   Updated: 2023/02/12 23:11:05 by nmaliare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*ft_circle_newnode(int number, int pos, t_pushswap *all)
{
	struct s_dlist	*new;

	new = NULL;
	new = (t_dlist *)malloc(sizeof(t_dlist));
	if (new == NULL)
		clean_exit(all, 'm');
	new->num = number;
	new->position = pos;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int	ft_circle_addfront(t_dlist **lst, t_dlist *new, t_data *start)
{
	t_dlist	*end;

	if (new == NULL)
		return (0);
	if (*lst)
	{
		end = start->head->prev;
		*lst = start->head;
		new->next = *lst;
		if (end == NULL)
			end = start->head;
		new->prev = end;
		(*lst)->prev = new;
		end->next = new;
	}
	else
		*lst = new;
	start->head = new;
	start->len += 1;
	return (1);
}

void	ft_circle_rmnode(t_dlist **lst, t_dlist **node, t_data *start)
{
	t_dlist	*tmp;

	tmp = *node;
	if (*node)
	{
		if (start->len > 1)
		{
			if ((*node) == start->head)
			{
				start->head = (*node)->next;
			}
			(*node)->prev->next = (*node)->next;
			(*node)->next->prev = (*node)->prev;
			*lst = start->head;
		}
		else
		{
			*lst = NULL;
			start->head = NULL;
		}
		free(tmp);
		start->len -= 1;
	}
}

void	ft_circle_free(t_dlist **lst, t_data *start)
{
	*lst = start->head;
	while (start->len > 0)
		ft_circle_rmnode(lst, lst, start);
}

t_dlist	*ft_circle_cpy(t_dlist **lst, t_data *start, \
	t_data *newstart, t_pushswap *all)
{
	t_dlist	*new;
	int		i;

	i = start->len + 1;
	*lst = start->head;
	new = NULL;
	while (--i > 0)
	{
		*lst = (*lst)->prev;
		ft_circle_addfront(&new, \
		ft_circle_newnode((*lst)->num, (*lst)->position, all), newstart);
		new = newstart->head;
		new->position = start->len - (start->len - i);
	}
	return (new);
}
