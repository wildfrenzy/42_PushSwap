/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaliare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:15:05 by nmaliare          #+#    #+#             */
/*   Updated: 2023/02/20 12:41:46 by nmaliare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "./Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_dlist
{
	int				num;
	int				position;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}				t_dlist;

typedef struct s_data
{
	struct s_dlist	*head;
	int				len;
}					t_data;

typedef struct s_helpers
{
	int		middle;
	int		offset;
	int		start;
	int		end;
}				t_helpers;

typedef struct s_pushswap
{
	struct s_dlist	*a;
	struct s_dlist	*b;
	struct s_data	*astart;
	struct s_data	*bstart;
	int 			a_len;
}				t_pushswap;

/*	main.c	*/
void 	init_all(t_pushswap *all);
void	ft_prepare(t_pushswap *all);
int		ft_check_dupl(int num, t_data *start, t_dlist **lst);
void 	clean_exit(t_pushswap *all, char f);

/*	sort.c	*/
void	sort_5(t_pushswap *all);
void	sort_3(t_pushswap *all);
void	first_last(t_pushswap *all);
void	position_main(t_pushswap *all, t_data *cpystart);

/*	sort_helpers.c	*/
int		check_if_sorted(t_dlist **a, t_data *astart);
void	sort_cpy(t_dlist **a, t_data *start);

/*	lists.c	*/

t_dlist	*ft_circle_newnode(int	number, int pos);
int		ft_circle_addfront(t_dlist **lst, t_dlist *new, t_data *all);
void	ft_circle_rot_right(t_dlist **lst, t_data *start);
void	ft_circle_rot_left(t_dlist **lst, t_data *start);
void	ft_circle_swap(t_dlist **lst, t_data *start);
void	ft_circle_rmnode(t_dlist **lst, t_dlist **node, t_data *start);
void	ft_circle_free(t_dlist **lst, t_data *start);
void	ft_circle_push(t_dlist **src, t_dlist **dest, t_data *srcstart, t_data *dststart);
t_dlist	*ft_circle_cpy(t_dlist **lst, t_data *start, t_data *newstart);

/*	rules.c	*/
void	pb(t_pushswap *all);
void	pa(t_pushswap *all);
void	ra(t_pushswap *all);
void	rb(t_pushswap *all);
void	sa(t_pushswap *all);
void	rra(t_pushswap *all);
void	rrb(t_pushswap *all);

/*	a to b	*/
void	a_to_b(t_pushswap *all);
void	make_chunk(t_pushswap *all, int i, t_helpers help);
//void	make_chunk(t_data *astart, t_data *bstart, t_dlist **a, int i, t_helpers help);
//void	check_chunk(t_dlist **b, t_data *bstart, t_helpers help);
void	check_chunk(t_pushswap *all, t_helpers help);
void	init_helper(t_helpers *help, t_data *astart);
int		offset(int len);

/*	b to a	*/
void	b_to_a(t_pushswap *all);
void	b_to_a_help(t_pushswap *all, int biggest_index);
void	check_down(int *down, t_pushswap *all);
int		find_biggest(t_dlist **b, t_data *bstart);


//void	b_to_a(t_data *astart, t_data *bstart, t_dlist **a, t_dlist **b);


/*	print.c	*/
void    ft_printlst(t_dlist *all, t_data *start);
void    ft_print_position(t_dlist *all, t_data *start);

#endif

/*
  ./push_swap_visualizer/build/bin/visualizer
*/
