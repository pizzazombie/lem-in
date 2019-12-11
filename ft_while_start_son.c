/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_while_start_son.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:56:35 by mkami             #+#    #+#             */
/*   Updated: 2019/12/04 16:24:05 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_return_link(t_all *all)
{
	int i;

	i = 0;
	while (i < all->l_path - 1)
	{
		ft_bun_link(all->short_path[i], all->short_path[i + 1]);
		ft_change_w(all->short_path[i + 1], all->short_path[i], -1);
		i++;
	}
}

void	ft_bun_link(t_room *room, t_room *neib)
{
	int i;

	i = 0;
	while (i < room->num_neib)
	{
		if (room->neib[i]->neib == neib)
		{
			room->neib[i]->f = 0;
			return ;
		}
		i++;
	}
}

void	ft_change_w(t_room *neib, t_room *room, int nw)
{
	int i;

	i = 0;
	while (i < neib->num_neib)
	{
		if (neib->neib[i]->neib == room)
		{
			neib->neib[i]->w = nw;
			return ;
		}
		i++;
	}
}

void	ft_come_back(t_all *all)
{
	t_room *temp;

	temp = all->list;
	while (temp != NULL)
	{
		ft_find_one_side_link(temp);
		temp = temp->next;
	}
}

void	ft_find_one_side_link(t_room *room)
{
	int i;

	i = 0;
	while (i < room->num_neib)
	{
		if (room->neib[i]->f == 0)
		{
			if (ft_check_link(room->neib[i]->neib, room) == 1)
			{
				room->neib[i]->f = 1;
				ft_change_w(room->neib[i]->neib, room, 1);
			}
		}
		i++;
	}
}
