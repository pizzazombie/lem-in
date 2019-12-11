/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_kg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:56:35 by mkami             #+#    #+#             */
/*   Updated: 2019/11/23 18:57:24 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		kg_rec(t_room *room, int kg)
{
	t_room	*temp;
	int		i;

	i = 0;
	room->kg = kg;
	while (i < room->num_neib)
	{
		if ((room->neib[i]->neib->kg < 0 || room->neib[i]->neib->kg > kg)
				&& room->neib[i]->f == 1)
			kg_rec(room->neib[i]->neib, kg + room->neib[i]->w);
		i++;
	}
	return (1);
}

void	ft_find_short_path(t_all *all)
{
	t_room	**path;
	t_room	*not_this;
	int		i;

	if ((all->l_path = ft_count_l(all)) == 0)
	{
		all->short_path = NULL;
		return ;
	}
	path = (t_room**)malloc(sizeof(t_room*) * (all->l_path + 1));
	path[all->l_path] = NULL;
	i = all->l_path - 1;
	path[i] = all->e;
	i--;
	not_this = NULL;
	while (i > 0)
	{
		path[i] = ft_find_prev(path[i + 1], path[i + 1]->kg, not_this);
		not_this = path[i + 1];
		i--;
	}
	path[0] = all->s;
	all->short_path = path;
	all->num_path_for_alg++;
}

t_room	*ft_find_prev(t_room *temp, int kg, t_room *not_this)
{
	int i;

	i = 0;
	while (i < temp->num_neib)
	{
		if (temp->neib[i]->neib->kg == kg - 1)
		{
			if (ft_check_link(temp->neib[i]->neib, temp) == 1 &&
					temp->neib[i]->neib != not_this)
				return (temp->neib[i]->neib);
		}
		i++;
	}
	i = 0;
	while (i < temp->num_neib)
	{
		if (temp->neib[i]->neib->kg == kg + 1 &&
				temp->neib[i]->neib != not_this)
			return (temp->neib[i]->neib);
		i++;
	}
	return (NULL);
}

int		ft_check_link(t_room *room, t_room *neib)
{
	int i;

	i = 0;
	while (i < room->num_neib)
	{
		if (room->neib[i]->neib == neib)
			return (room->neib[i]->f);
		i++;
	}
	return (0);
}

int		ft_count_l(t_all *all)
{
	t_room	*temp;
	t_room	*not_this;
	t_room	*temp2;
	int		n;

	n = 1;
	temp = all->e;
	not_this = NULL;
	while (temp != all->s && temp != NULL)
	{
		temp2 = temp;
		temp = ft_find_prev(temp2, temp->kg, not_this);
		not_this = temp2;
		n++;
	}
	if (temp != all->s)
		return (0);
	return (n);
}
