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

t_dlist	*ft_circle_newnode(int number, int pos)
{
	struct s_dlist	*new;

	new = NULL;
	new = (t_dlist *)malloc(sizeof(t_dlist));
	if (new == NULL)
		return (NULL);
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
	//printf(">RM node pos:%d <\n", (*node)->position);
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
			//printf(" RM ELSE\n");
			*lst = NULL;
			start->head = NULL;
		}
		free(tmp);
		start->len -= 1;
		//printf("after RM len: %d\n", start->len);

	/*	if (*lst && start->head)
		{
			printf("\nAFTER MESS:\n\n");
			printf("head: %p %d\n", start->head, start->head->position);
			printf("node pos: %d\n", (*node)->position);
			printf("node next pos: %p %d\n", (*node)->next, (*node)->next->position);
			printf("node prev pos: %d\n", (*node)->prev->position);
			printf("lst pos: %d\n", (*lst)->position);
			printf("lst next pos: %d\n", (*lst)->next->position);
			printf("lst prev pos: %d\n", (*lst)->prev->position);
			printf("---------\n");
		}*/
	}
}

 //TODO: MALLOC ERRORS

void	ft_circle_push(t_dlist **src, t_dlist **dest, t_data *srcstart, t_data *dststart)
{
	t_dlist	*tmp;

	*src = srcstart->head;
	if (srcstart->len > 0)
	{
		if (*dest)
		{
			tmp = ft_circle_newnode((*src)->num, (*src)->position);
			ft_circle_addfront(dest, tmp, dststart);
			dststart->head = tmp;
		}
		else
		{
			*dest = ft_circle_newnode((*src)->num, (*src)->position);
			dststart->head = *dest;
			dststart->len += 1;
		}
		ft_circle_rmnode(src, src, srcstart);
	}
}

void	ft_circle_free(t_dlist **lst, t_data *start)
{
	*lst = start->head;
	while(start->len > 0)
		ft_circle_rmnode(lst, lst, start);
}

t_dlist	*ft_circle_cpy(t_dlist **lst, t_data *start, t_data *newstart)
{
	t_dlist	*new;
	int		i;

	i = start->len + 1;
	*lst = start->head;
	new = NULL;

	while (--i > 0)
	{
		*lst = (*lst)->prev;
		if (!ft_circle_addfront(&new, ft_circle_newnode((*lst)->num, (*lst)->position), newstart))
		{
			ft_circle_free(&new, newstart);
			ft_printf("Malloc Error!\n");
			return (0);
		}
		new = newstart->head;
		new->position = start->len - (start->len - i);
	}
	return (new);
}